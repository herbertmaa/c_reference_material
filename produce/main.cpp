#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

/**
 * Need three things,
 * 1 - shared value to see if work is done (available)
 * 2 - condition variable to signal or broadcast all threads that are waiting on the condition variable
 * 3 - mutex to protect the critical section
 */

static pthread_mutex_t mutex; // always declare mutex as global.
static pthread_cond_t cond;
static bool available = false; //shared

void * consumer(void * arg) { // need to take in a void *
    int* cubbyhole = (int *) arg; // cast to int, or in this case int*

    for (int i= 0; i < 10; i++) {
        pthread_mutex_lock(&mutex); // start of critical section
        while(!available) { // wait until produced before consuming
            pthread_cond_wait(&cond, &mutex); // this thread releases its mutex and places itself on the wait queue
        }

        printf("get %d\n", *cubbyhole);
        available = false;
        pthread_mutex_unlock(&mutex); // end of critical section
        pthread_cond_signal(&cond); //notify waiting thread - waiting on the condition variable
    }
    pthread_exit(nullptr); //improvement
}

void * producer(void * arg) {
    int*  cubbyhole = (int *) arg;
    for (int i= 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        while(available) // we want to wait until it is consumed before producing again.
            pthread_cond_wait(&cond, &mutex); //notice that the mutex is also released in addition to thread waiting on the condition
        *cubbyhole = i;
        printf("put %d\n", *cubbyhole);
        available = true;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond); //need to signal the correct condition variable that the other thread is waiting on.
    }
    pthread_exit(nullptr); // improvement
}

int main() {
    pthread_t tid;
    int *ret;
    int cubbyhole; //shared resource
    pthread_create(&tid, NULL, producer, (void*) &cubbyhole); //threadID, attributes, thread function, argument to the function
    pthread_create(&tid, NULL, consumer, (void*) &cubbyhole);
    pthread_join(tid, (void **)&ret);
}
