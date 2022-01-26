#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t DisplayHandle;
TaskHandle_t SensorHandle;

void SensorTask(void *pv){
    int count=0;
    while(1){
    count++;
    printf("Sensor Task is Running = %d\n",count);
    if(count == 10){
    vTaskDelay(5000/portTICK_PERIOD_MS);
    }
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
    xTaskCreate(SensorTask, "SensorTask", 1800, NULL, 10, &DisplayHandle);
    xTaskCreate(DisplayTask, "DisplayTask", 1800, NULL, 5, &SensorHandle);
}