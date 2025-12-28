/*
Use two semaphores initialized asymmetrically to enforce strict alternation between odd and even 
threads without using mutexes or condition variables.

sem_odd → controls when odd thread runs
sem_even → controls when even thread runs

Start with:
 sem_odd = 1 (odd prints first)
 sem_even = 0
Threads signal each other after printing.

Output: 
Odd Thread: 1
Even Thread: 2
Odd Thread: 3
Even Thread: 4
Odd Thread: 5
Even Thread: 6
Odd Thread: 7
Even Thread: 8
Odd Thread: 9
Even Thread: 10
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_NUM 10

sem_t sem_odd;
sem_t sem_even;
int number = 1;

void *print_odd(void *arg) {
    while (number <= MAX_NUM) {
        sem_wait(&sem_odd);   // wait for odd turn

        if (number <= MAX_NUM) {
            printf("Odd Thread: %d\n", number);
            number++;
        }

        sem_post(&sem_even); // allow even thread
    }
    return NULL;
}

void *print_even(void *arg) {
    while (number <= MAX_NUM) {
        sem_wait(&sem_even); // wait for even turn

        if (number <= MAX_NUM) {
            printf("Even Thread: %d\n", number);
            number++;
        }

        sem_post(&sem_odd);  // allow odd thread
    }
    return NULL;
}

int main() {
    pthread_t odd_thread, even_thread;

    // Initialize semaphores
    sem_init(&sem_odd, 0, 1);   // odd starts
    sem_init(&sem_even, 0, 0);  // even waits

    pthread_create(&odd_thread, NULL, print_odd, NULL);
    pthread_create(&even_thread, NULL, print_even, NULL);

    pthread_join(odd_thread, NULL);
    pthread_join(even_thread, NULL);

    sem_destroy(&sem_odd);
    sem_destroy(&sem_even);

    return 0;
}
