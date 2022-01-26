#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t DisplayHandle;
TaskHandle_t SensorHandle;


void SensorTask(void *pv){
    while(1){
    printf("Sensor Task is Running\n");
    vTaskDelay(500/portTICK_PERIOD_MS);
    }
}

void DisplayTask(void *pv){
    while(1){
    printf("Display Task is Running\n");
    vTaskDelay(2000/portTICK_PERIOD_MS);
    }
}

void app_main()
{
    BaseType_t sensor;
    BaseType_t display;
    sensor = xTaskCreate(SensorTask, "SensorTask", 2048, NULL, 10, &SensorHandle);
    display = xTaskCreate(DisplayTask, "DisplayTask", 2048, NULL, 5, &DisplayHandle);
    if(sensor == pdPASS){
        printf("Sensor Task Created Succesfully\n");
    }
    if(display == pdPASS){
        printf("Display Task Created Succesfully\n");
    }
}