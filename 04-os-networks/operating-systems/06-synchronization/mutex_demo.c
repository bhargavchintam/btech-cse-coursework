// same counter, protected by a mutex.  cc mutex_demo.c -lpthread -o mutex_demo && ./mutex_demo
#include<stdio.h>
#include<pthread.h>

#define T 4
#define LOOP 1000000
long counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* inc(void *arg)
{
    for(int i = 0; i < LOOP; i++)
    {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main()
{
    pthread_t t[T];
    for(int i = 0; i < T; i++)
        pthread_create(&t[i], NULL, inc, NULL);
    for(int i = 0; i < T; i++)
        pthread_join(t[i], NULL);
    printf("expected %d, got %ld\n", T * LOOP, counter);
    return 0;
}
