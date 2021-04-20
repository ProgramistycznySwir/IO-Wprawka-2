#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int Licznik = 0;

void* Display (void* args);
void* Increment (void* args);

int main ()
{
    pthread_t th0, th1;
    pthread_attr_t attr;
    char* arg = "gah";
    // int th0_result = pthread_create(&th0, NULL, Display, (void*) arg);
    int th0_result = pthread_create(&th0, NULL, Display, NULL);
    int th1_result = pthread_create(&th1, NULL, Increment, NULL);

    printf("Exitted main thread.\n");
    return 0;
}

void* Display (void* args)
{
    while(1)
        printf("%d\n", Licznik);
}

void* Increment (void* args)
{
    while(1)
        Licznik++;
}