#include <stdio.h>
#include <pthread.h>

void *SensorThread(void *arg){

    printf("Sensor Thread in ESP\n");
    return NULL;
}

void *DisplayThread(void *arg){

    printf("Display Thread in ESP\n");
    return NULL;
}

void app_main()
{
    pthread_t sensorID, displayID;
    printf("Hello from Saquib!!!\n");
    pthread_create(&sensorID, NULL, SensorThread, NULL);
    pthread_create(&displayID, NULL, DisplayThread, NULL);
    pthread_join(sensorID, NULL);
    pthread_join(displayID, NULL);
}