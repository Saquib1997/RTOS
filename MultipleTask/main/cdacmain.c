#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <FreeRTOSConfig.h>

TaskHandle_t DisplayHandle;
TaskHandle_t SensorHandle;

void SensorTask(void *pv){
    printf("Sensor Task is Running\n");
    vTaskDelete(NULL);
}

void DisplayTask(void *pv){
    printf("Display Task is Running\n");
    vTaskDelete(NULL);
}

void app_main()
{
    BaseType_t sensor;
    BaseType_t display;
    display = xTaskCreate(DisplayTask, "DisplayTask", 2048, NULL, 2, &DisplayHandle);
    sensor = xTaskCreate(SensorTask, "SensorTask", 2048, NULL, 10, &SensorHandle);
    if(sensor == pdPASS){
        printf("Sensor Task Created Succesfully\n");
    }
    if(display == pdPASS){
        printf("Display Task Created Succesfully\n");
    } 
}