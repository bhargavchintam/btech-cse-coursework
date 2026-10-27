// create and join a thread.  cc thread_create.c -lpthread -o thread_create && ./thread_create
#include<stdio.h>
#include<pthread.h>

void* run(void *arg)
{
    printf("hello from the thread\n");
    return NULL;
}

int main()
{
    pthread_t t;
    pthread_create(&t, NULL, run, NULL);
    pthread_join(t, NULL);
    printf("main done\n");
    return 0;
}
