/*
Print 1–N Using N Threads (Semaphore Ring)
Idea is
Create N semaphores, one per thread

Initialize:
 sem[0] = 1 → first thread starts
 sem[1..N-1] = 0

Each thread:
 Waits on its own semaphore

Prints it's number and signals the next semaphore (i + 1) % N
This enforces strict ordering.
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define N 5   // Number of threads (and numbers to print)

sem_t sems[N];

void *print_number(void *arg) {
    int id = *(int *)arg;

    sem_wait(&sems[id]);  // wait for turn

    printf("Thread %d prints %d\n", id, id + 1);

    sem_post(&sems[(id + 1) % N]); // signal next thread
    return NULL;
}

int main() {
    pthread_t threads[N];
    int ids[N];

    // Initialize semaphores
    for (int i = 0; i < N; i++) {
        sem_init(&sems[i], 0, (i == 0) ? 1 : 0);
        ids[i] = i;
    }

    // Create threads
    for (int i = 0; i < N; i++) {
        pthread_create(&threads[i], NULL, print_number, &ids[i]);
    }

    // Wait for all threads
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    for (int i = 0; i < N; i++) {
        sem_destroy(&sems[i]);
    }

    return 0;
}
