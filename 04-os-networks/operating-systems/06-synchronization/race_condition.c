// race condition on an unprotected counter.  cc race_condition.c -lpthread -o race && ./race
#include<stdio.h>
#include<pthread.h>

#define T 4
#define LOOP 1000000
long counter = 0;

void* inc(void *arg)
{
    for(int i = 0; i < LOOP; i++)
        counter++;               // not atomic - updates get lost
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
