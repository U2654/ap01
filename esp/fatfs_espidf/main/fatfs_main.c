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
#include "esp_system.h"

const char *base_path = "/fat";

static wl_handle_t s_wl_handle = WL_INVALID_HANDLE;

void app_main(void)
{
    const esp_vfs_fat_mount_config_t mount_config = {
            .max_files = 4,
            .format_if_mount_failed = false,
            .allocation_unit_size = CONFIG_WL_SECTOR_SIZE
    };
    esp_err_t err = esp_vfs_fat_spiflash_mount_rw_wl(base_path, "storage", &mount_config, &s_wl_handle);

    if (err != ESP_OK) {
        printf("problem\n");
        return;
    }

    /* open file already on device */
    const char *filename_read = "/fat/test.txt";
    /* buffer for text lines */
    char line[128];
    FILE *f;
    /* open file for read */
    f = fopen(filename_read, "r");
    if (f == NULL) {
        return;
    }
    /* read line by line until end and print */
    while (fgets(line, sizeof(line), f) != NULL)
    {
        printf("%s", line);
    }
    /* close */
    fclose(f);

    /* create a new file and write */
    const char *filename_write = "/fat/text.txt";
    /* handle is reused */
    f = fopen(filename_write, "w");
    if (f == NULL) {
        return;
    }
    fprintf(f, "Hello\n");
    fprintf(f, "filesystem!\n");
    fclose(f);

    /* Unmount FATFS */
    ESP_ERROR_CHECK(esp_vfs_fat_spiflash_unmount_rw_wl(base_path, s_wl_handle));
}
