
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream> // For testing and debugging

using namespace std;
void* doit(void * arg) {
    char* msg = (char *) (arg);
    for (int i= 0; i < 10; i++) {
        printf("%s\n", msg);
        sleep(1);
    }
}

int main() {
    pthread_t tid; // Get the main function's unique thread ID
    int *ret;

    // The pthread_create() function starts a new thread in the calling process. The new thread starts execution by invoking start_routine()
    pthread_create(&tid, nullptr, doit, (void *) "Jamaica");

    // The pthread_create() function starts a new thread in the calling process. The new thread starts execution by invoking start_routine()
    pthread_create(&tid, nullptr, doit, (void *) "Fiji");

    // Main thread calls join() to wait for other threads to terminate before it exits
    pthread_join(tid, (void **) &ret);

}