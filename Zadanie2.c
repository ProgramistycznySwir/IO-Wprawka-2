#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

void* Thread (void* arg) {
    int k = rand() % 10000;

    for (int i = 0; i < k; ++i)
        printf("Thread #%ld, iteration %d/%d\n", (long) arg, i, k);

    pthread_exit((void*) (intptr_t) k);
}

int main()
{
    pthread_t threads[NUMBER_OF_THREADS];
    // pthread_attr_t attr;

    for (int i = 0; i < NUMBER_OF_THREADS; ++i)
    {
        if (pthread_create(&threads[i], NULL, Thread, (void*) i))
        {
            printf("Error creating thread no. %d\n", i);
            exit(1);
        }
    }


    long summaryIterations = 0;
    for (int i = 0; i < NUMBER_OF_THREADS; ++i)
    {
        void* status;
        if (pthread_join(threads[i], &status))
        {
            printf("Error joining thread %d\n", i);
            exit(EXIT_FAILURE);
        }

        summaryIterations += (long) status;
    }

    printf("\nNumber of iterations: %ld\n", summaryIterations);
    return 0;
    // pthread_exit(NULL);
}