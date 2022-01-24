#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t FirstHandle;

void FirstTask(void){
    printf("First Task Created Succesfully\n");
    vTaskDelete(NULL);
}

void app_main()
{
    BaseType_t flag;
    flag = xTaskCreate(FirstTask, "FirstTask", 1024, NULL, 5, &FirstHandle);
    if(flag == pdPASS){
        printf("Task Created Succesfully\n");
    }
}