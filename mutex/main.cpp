#include <iostream>


#define COUNT_TO 10000
#define MAX_CORES 8

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
long long i = 0; // the lock above protects this critical value and prevents Race Condition from occurring

void* start_counting(void* arg){
    for(;;){

        pthread_mutex_lock(&mutex);
        /* Critical section of code */
        if(i >= COUNT_TO){
            pthread_mutex_unlock(&mutex);
            return NULL;
        }

        ++i;
        /* Free the lock */
        pthread_mutex_unlock(&mutex);
        printf("i = %lld\n", i);
    }
}


int main() {

    int i = 0;
    pthread_t *thread_group = (pthread_t*) malloc(sizeof(pthread_t) * MAX_CORES);

    for(i = 0; i < MAX_CORES; ++i){
        pthread_create(&thread_group[i], NULL, start_counting, NULL);
    }

    for(i = 0; i < MAX_CORES; ++i){
        pthread_join(thread_group[i], NULL);
    }

    return EXIT_SUCCESS;
}
