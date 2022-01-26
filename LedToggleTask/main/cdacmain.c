#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

#define PIN 15

void SensorTask(void *pv){
    while(1){
    printf("Sensor Task is Running\n");
    vTaskDelay(500/portTICK_PERIOD_MS);
    }
}

void LedTask(void *pv){
    esp_rom_gpio_pad_select_gpio(PIN);
    gpio_set_direction(PIN, GPIO_MODE_OUTPUT);
    while(1){
    gpio_set_level(PIN, 0);
    vTaskDelay(200/portTICK_PERIOD_MS);
    gpio_set_level(PIN, 1);
    vTaskDelay(200/portTICK_PERIOD_MS);
    }
}



void app_main()
{
    xTaskCreate(SensorTask, "SensorTask", 2048, NULL, 5, NULL);
    xTaskCreate(LedTask, "LedTask", 2048, NULL, 5, NULL);
    printf("FreeRTOS -----------------> Priority based Preemptive Kernel\n");
}