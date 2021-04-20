#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int Licznik = 0;

int main ()
{
    pthread_t th0, th1;
    int pthread_create(pthread_t* th0, pthread_attr_t attr, void* (*start_routine)(void*) Display, void* arg);
    int pthread_create(pthread_t* th1, pthread_attr_t attr, void* (*start_routine)(void*), void* arg);
}

void Display (void* args)
{
    while(true)
        printf("%d\n", Licznik);
}

void Increment (void* args)
{
    while(true)
        Licznik++;
}