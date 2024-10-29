/* You can read the partition from the microcontroller after running the application by: */
/* parttool.py --port /dev/tty.usbmodem1101 read_partition --partition-type=data --partition-subtype=fat --output flash.img */
/* NOTE: /dev/tty... must match with your used port. */
/* And then transfer the flash.img into files by running: */
/* $IDF_PATH/components/fatfs/fatfsparse.py flash.img */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "esp_vfs.h"
#include "esp_vfs_fat.h"
#include "esp_console.h"
#include "esp_system.h"
#include "cmd_system.h"
#include "cmd_wifi.h"
#include "nvs.h"
#include "nvs_flash.h"
#include "esp_http_server.h"

#define HTML_PAGE_BUFFER 4096

static const char *page_path = "/fat/index.htm";
static const char *base_path = "/fat";

static wl_handle_t s_wl_handle = WL_INVALID_HANDLE;
static httpd_handle_t web_server_handle = NULL;

/* buffer for html page */
static char html_page[HTML_PAGE_BUFFER];

/* --------------------------------------------------- */
static esp_err_t index_get_handler(httpd_req_t *req) 
{
    FILE *f;
    /* open file for read */
    f = fopen(page_path, "r");
    if (f == NULL) {
        printf("error opening file\n");
        return ESP_FAIL;
    }
    /* read file in buffer */
    if (fread(html_page, 1, HTML_PAGE_BUFFER, f) == 0) 
    {
        printf("error reading file\n");
        return ESP_FAIL;
    }
    /* close */
    fclose(f);

    httpd_resp_send(req, html_page, HTTPD_RESP_USE_STRLEN);
    return ESP_OK;
}

httpd_uri_t uri_index = {
    .uri = "/",           /* uniform resource identifier */
    .method = HTTP_GET,   /* http method: for request GET */
    .handler = index_get_handler, /* callback function */
    .user_ctx = NULL      /* no user context here */
};

/* --------------------------------------------------- */
static int start_webserver_func(int argc, char** argv)
{
    if (web_server_handle != NULL)
    {
        printf("webserver already running\n");
        return -1;
    }
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();

    if (httpd_start(&web_server_handle, &config) == ESP_OK) 
    {
        httpd_register_uri_handler(web_server_handle, &uri_index);
    }
    return 0;
}

static int stop_webserver_func(int argc, char** argv) 
{
    if (web_server_handle == NULL)
    {
        printf("webserver not running\n");
        return -1;
    }
    httpd_stop(web_server_handle);
    web_server_handle = NULL;
    return 0;
}

/* --------------------------------------------------- */
static void register_start_webserver() 
{
    /* structure defining the command */
    const esp_console_cmd_t start_webserver_cmd = {
        .command = "start_webserver",   /* command name */
        .help = "start webserver",      /* info text   */
        .hint = NULL,                   /* hint text   */
        .func = &start_webserver_func, /* callback function */
    };
    /* register command */
    esp_console_cmd_register(&start_webserver_cmd);
}

static void register_stop_webserver() 
{
    const esp_console_cmd_t stop_webserver_cmd = {
        .command = "stop_webserver",
        .help = "stop webserver",
        .hint = NULL,
        .func = &stop_webserver_func,
    };
    esp_console_cmd_register(&stop_webserver_cmd);
}

/* --------------------------------------------------- */
void app_main(void)
{
    /* mount file system */
    const esp_vfs_fat_mount_config_t mount_config = {
            .max_files = 4,
            .format_if_mount_failed = false,
            .allocation_unit_size = CONFIG_WL_SECTOR_SIZE
    };
    esp_err_t err = esp_vfs_fat_spiflash_mount_rw_wl(base_path, "storage", &mount_config, &s_wl_handle);

    if (err != ESP_OK) {
        printf("problem with fat\n");
        return;
    }

    /* nvs required for wifi driver */
    err = nvs_flash_init();
    if (err != ESP_OK){
        printf("problem with nvs\n");
        return;
    } 

    /* prepare console */
    esp_console_repl_t *repl = NULL;
    esp_console_repl_config_t repl_config = ESP_CONSOLE_REPL_CONFIG_DEFAULT();

    /* register commands */
    esp_console_register_help_command();
    register_system_common();
    register_wifi();
    register_start_webserver();
    register_stop_webserver();

    /* init console on uart */
    esp_console_dev_uart_config_t hw_config = ESP_CONSOLE_DEV_UART_CONFIG_DEFAULT();
    esp_console_new_repl_uart(&hw_config, &repl_config, &repl);

    /* start console */
    esp_console_start_repl(repl);

    /* Unmount FATFS */
    //ESP_ERROR_CHECK(esp_vfs_fat_spiflash_unmount_rw_wl(base_path, s_wl_handle));
}
