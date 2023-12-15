#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_PHILOSOPHERS // Replace with desired number of philosophers

pthread_t philosophers[NUM_PHILOSOPHERS];
sem_t chopsticks[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int philosopher_id = (int) arg;

    int left_chopstick = philosopher_id;
    int right_chopstick = (philosopher_id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        // Thinking

        printf("Philosopher %d is thinking\n", philosopher_id);
        sleep(rand() % 3);

        // Trying to acquire chopsticks

        printf("Philosopher %d is trying to acquire chopsticks\n", philosopher_id);

        if (sem_trywait(&chopsticks[left_chopstick]) == 0) {
            if (sem_trywait(&chopsticks[right_chopstick]) == 0) {
                // Eating

                printf("Philosopher %d is eating\n", philosopher_id);
                sleep(rand() % 3);

                // Releasing chopsticks

                sem_post(&chopsticks[right_chopstick]);
                sem_post(&chopsticks[left_chopstick]);
            } else {
                sem_post(&chopsticks[left_chopstick]);
                printf("Philosopher %d failed to acquire right chopstick\n", philosopher_id);
            }
        } else {
            printf("Philosopher %d failed to acquire left chopstick\n", philosopher_id);
        }
    }
    return NULL;
}

int main() {
    int i;

    // Initialize semaphores

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&chopsticks[i], 0, 1);
    }

    // Create philosopher threads

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_create(&philosophers[i], NULL, philosopher, (void *) i);
    }

    // Join philosopher threads

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy semaphores

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_destroy(&chopsticks[i]);
    }

    return 0;
}
