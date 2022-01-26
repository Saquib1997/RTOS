#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

#define PIN 15

void SensorTask(void *pv){
    while(1){
    printf("Sensor Task is Running\n");
    printf("Sensor Task Stack Size: %d\n",uxTaskGetStackHighWaterMark(NULL)); 
    printf("Sensor Task: CPU ID %d\n",xTaskGetAffinity(NULL)); //This API tell which CPU Core is running this task in a Multicore CPU
    vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void LedTask(void *pv){
    esp_rom_gpio_pad_select_gpio(PIN);
    gpio_set_direction(PIN, GPIO_MODE_OUTPUT);
    while(1){
    gpio_set_level(PIN, 0);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    gpio_set_level(PIN, 1);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    printf("LED Task Stack Size: %d\n",uxTaskGetStackHighWaterMark(NULL));
    printf("LED Task: CPU ID %d\n",xTaskGetAffinity(NULL)); //This API tell which CPU Core is running this task in a Multicore CPU
    }
}

void app_main()
{
    xTaskCreate(SensorTask, "SensorTask", 2048, NULL, 5, NULL);
    xTaskCreate(LedTask, "LedTask", 2048, NULL, 5, NULL);
    printf("FreeRTOS -----------------> Priority based Preemptive Kernel\n");
}