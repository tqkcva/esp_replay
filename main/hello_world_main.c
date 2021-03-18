/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

#ifdef CONFIG_IDF_TARGET_ESP32
#define CHIP_NAME "ESP32"
#endif

#ifdef CONFIG_IDF_TARGET_ESP32S2BETA
#define CHIP_NAME "ESP32-S2 Beta"
#endif

void app_main(void)
{
    printf("Hello world!\n");
    printf("Say something, I will reply them\n");

    char *msg = pvPortMalloc(1024);
    int index = 0;
    int c;

    while (1)
    {
        c = getchar();
        if (index >= 1023)
        {
            printf("\nMessage is too large. I reset it\n");
            index = 0;
        }
        else if (c != EOF)
        {
            msg[index] = c;
            if (msg[index] == '\n')
            {
                msg[index + 1] = '\0';
                printf("\nYou say: %s\n", msg);
                index = 0;
            }
            else
            {
                index++;
            }
        }
        vTaskDelay(1);
    }
}
