// several threads, each with its own id.  cc thread_multiple.c -lpthread -o thread_multiple && ./thread_multiple
#include<stdio.h>
#include<pthread.h>

void* run(void *arg)
{
    long id = (long)arg;
    printf("thread %ld running\n", id);
    return NULL;
}

int main()
{
    pthread_t t[5];
    long i;
    for(i = 0; i < 5; i++)
        pthread_create(&t[i], NULL, run, (void*)i);
    for(i = 0; i < 5; i++)
        pthread_join(t[i], NULL);
    printf("all threads joined\n");
    return 0;
}
