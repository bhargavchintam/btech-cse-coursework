// bounded-buffer producer/consumer with a mutex and condition variables
// cc producer_consumer.c -lpthread -o pc && ./pc
#include<stdio.h>
#include<pthread.h>

#define SIZE 5
#define ITEMS 10

int buf[SIZE], count = 0, in = 0, out = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;

void* producer(void *arg)
{
    for(int i = 1; i <= ITEMS; i++)
    {
        pthread_mutex_lock(&m);
        while(count == SIZE)
            pthread_cond_wait(&not_full, &m);
        buf[in] = i;
        in = (in + 1) % SIZE;
        count++;
        printf("produced %d\n", i);
        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&m);
    }
    return NULL;
}

void* consumer(void *arg)
{
    for(int i = 0; i < ITEMS; i++)
    {
        pthread_mutex_lock(&m);
        while(count == 0)
            pthread_cond_wait(&not_empty, &m);
        int item = buf[out];
        out = (out + 1) % SIZE;
        count--;
        printf("        consumed %d\n", item);
        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&m);
    }
    return NULL;
}

int main()
{
    pthread_t p, c;
    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);
    pthread_join(p, NULL);
    pthread_join(c, NULL);
    return 0;
}
