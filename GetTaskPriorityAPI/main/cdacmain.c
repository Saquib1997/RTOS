#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

#define PIN 15

TaskHandle_t SensorHandle;
TaskHandle_t LedHandle;

void SensorTask(void *pv){
    while(1){
    printf("Sensor Task is Running\n");
    printf("Sensor Task Stack Size: %d\n",uxTaskGetStackHighWaterMark(NULL)); //This API Prints how much stack size is unused from the allocated stack size
    printf("Sensor Task Priority is: %d\n",uxTaskPriorityGet(NULL)); //This API Prints what is the priority of the task whose TaskHandle is passed
    vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}

void TempratureTask(void *pv){
    esp_rom_gpio_pad_select_gpio(PIN);
    gpio_set_direction(PIN, GPIO_MODE_OUTPUT);
    while(1){
    gpio_set_level(PIN, 0);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    gpio_set_level(PIN, 1);
    vTaskDelay(1000/portTICK_PERIOD_MS);
    printf("LED Task Stack Size: %d\n",uxTaskGetStackHighWaterMark(NULL)); //This API Prints how much stack size is unused from the allocated stack size
    printf("LED Task Priority is: %d\n",uxTaskPriorityGet(NULL)); //This API Prints what is the priority of the task whose TaskHandle is passed
    }
}

void app_main()
{
    xTaskCreate(SensorTask, "SensorTask", 2048, NULL, 5, &SensorHandle);
    xTaskCreate(LedTask, "LedTask", 2048, NULL, 3, &LedHandle);
    printf("FreeRTOS -----------------> Priority based Preemptive Kernel\n");
    //Task Priority API usage
    if(uxTaskPriorityGet(SensorHandle) > uxTaskPriorityGet(LedHandle))
    printf("Sensor Task is of higher priority with priority of %d\n",uxTaskPriorityGet(SensorHandle));
    else
    printf("Led Task is of higher priority with priority of %d\n",uxTaskPriorityGet(LedHandle));
}