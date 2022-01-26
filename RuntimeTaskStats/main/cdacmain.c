#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t StatsTask;

void Stats(void){
    char buff[50]={'\0'};
    printf("Runtime Statistics of 'Stats' task is: \n");
    vTaskGetRunTimeStats(buff);
    printf("%s\n",buff);
    vTaskDelete(NULL);
}

void app_main()
{
    printf("In App Main function!!!\n");
    BaseType_t result;
    result = xTaskCreate(Stats, "Stats", 2048, NULL, 5, StatsTask);
    if(result == pdPASS){
        printf("Stats Task Created!!!!!\n\n");
    }
    else{
        printf("Stats Task not created!!!!!\n\n");
    }
    char buff2[50];
    printf("Runtime Statistics of 'App_main' task is: \n");
    vTaskGetRunTimeStats(buff2);
    printf("%s\n",buff2);
}

