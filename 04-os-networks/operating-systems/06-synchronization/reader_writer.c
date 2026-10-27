// readers-writers with a pthread rwlock.  cc reader_writer.c -lpthread -o rw && ./rw
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_rwlock_t lock = PTHREAD_RWLOCK_INITIALIZER;
int data = 0;

void* reader(void *arg)
{
    long id = (long)arg;
    pthread_rwlock_rdlock(&lock);
    printf("reader %ld sees data = %d\n", id, data);
    pthread_rwlock_unlock(&lock);
    return NULL;
}

void* writer(void *arg)
{
    long id = (long)arg;
    pthread_rwlock_wrlock(&lock);
    data++;
    printf("writer %ld set data = %d\n", id, data);
    pthread_rwlock_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t r[3], w[2];
    for(long i = 0; i < 2; i++)
        pthread_create(&w[i], NULL, writer, (void*)i);
    for(long i = 0; i < 3; i++)
        pthread_create(&r[i], NULL, reader, (void*)i);
    for(int i = 0; i < 2; i++) pthread_join(w[i], NULL);
    for(int i = 0; i < 3; i++) pthread_join(r[i], NULL);
    printf("final data = %d\n", data);
    return 0;
}
