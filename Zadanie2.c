#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

void* Thread (void* arg) {
    int n = rand() % 10001;

    for (int i = 0; i < n; ++i) {
        printf("Thread #%ld, i = %d\n", (long) arg, i);
    }

    pthread_exit((void*) (intptr_t) n);
}

int main() {
    pthread_t threads[NUMBER_OF_THREADS];
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    int error = 0;
    for (long i = 0; i < NUMBER_OF_THREADS; ++i) {
        if (pthread_create(&threads[i], &attr, Thread, (void*) i)) {
            error = 1;
            break;
        }
    }

    pthread_attr_destroy(&attr);

    if (error) {
        fprintf(stderr, "Error creating new thread.");
        exit(EXIT_FAILURE);
    }

    long sum = 0;
    for (int i = 0; i < NUMBER_OF_THREADS; ++i) {
        void *status;
        if (pthread_join(threads[i], &status)) {
            error = 1;
            break;
        }

        sum += (long) status;
    }

    if (error) {
        fprintf(stderr, "Error joining threads.");
        exit(EXIT_FAILURE);
    }

    printf("Iterations: %ld\n", sum);
    pthread_exit(NULL);
}