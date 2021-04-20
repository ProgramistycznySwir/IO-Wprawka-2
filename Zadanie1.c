#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int Licznik = 0;

int main ()
{
    pthread_t th0, th1;
}

void Display (void* args)
{
    printf("%d\n", Licznik);
}

void Increment (void* args)
{
    Licznik++;
}