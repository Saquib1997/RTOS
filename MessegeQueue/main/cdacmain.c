#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>

QueueHandle_t SensorQueue;

void SensorTask(void *pv){
    int SensorData=0;
    while(1){
    SensorData++;
    printf("Sensor Data Sending: %d\n",SensorData);
    xQueueSend(SensorQueue, &SensorData, portMAX_DELAY);
    vTaskDelay(500/portTICK_PERIOD_MS);
    if(SensorData == 10)
    vTaskDelay(10000/portTICK_PERIOD_MS);
    }
}

void DisplayTask(void *pv){
    int DisplayData=0;
    while(1){
    //xQueueReceive(SensorQueue, &DisplayData, portMAX_DELAY);
    printf("Display Data Received: %d\n",DisplayData);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void app_main()
{
    SensorQueue = xQueueCreate(10, sizeof(int));
    xTaskCreate(SensorTask, "SensorTask", 2048, NULL, 10, NULL);
    xTaskCreate(DisplayTask, "DisplayTask", 2048, NULL, 5, NULL);
}