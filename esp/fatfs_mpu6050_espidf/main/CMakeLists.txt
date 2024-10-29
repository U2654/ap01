idf_component_register(SRCS "mpu6050_i2c.c" "main.c"
                    INCLUDE_DIRS ".")

# Create a FATFS image from the contents of the 'fatfs_image' directory
# that fits the partition named 'storage'. FLASH_IN_PROJECT indicates that
# the generated image should be flashed when the entire project is flashed to
# the target with 'idf.py -p PORT flash'.
set(image ../fatfs_image)
fatfs_create_spiflash_image(storage ${image} FLASH_IN_PROJECT)
