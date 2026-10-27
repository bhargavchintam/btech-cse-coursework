// dining philosophers, deadlock avoided by making the last one grab forks in reverse
// cc dining_philosophers.c -lpthread -o dp && ./dp
#include<stdio.h>
#include<pthread.h>

#define N 5
pthread_mutex_t forks[N];

void* philosopher(void *arg)
{
    long id = (long)arg;
    int left = id, right = (id + 1) % N;
    if(id == N - 1)              // break the circular wait
    {
        int t = left; left = right; right = t;
    }
    pthread_mutex_lock(&forks[left]);
    pthread_mutex_lock(&forks[right]);
    printf("philosopher %ld is eating\n", id);
    pthread_mutex_unlock(&forks[right]);
    pthread_mutex_unlock(&forks[left]);
    return NULL;
}

int main()
{
    pthread_t p[N];
    for(int i = 0; i < N; i++)
        pthread_mutex_init(&forks[i], NULL);
    for(long i = 0; i < N; i++)
        pthread_create(&p[i], NULL, philosopher, (void*)i);
    for(int i = 0; i < N; i++)
        pthread_join(p[i], NULL);
    printf("everyone ate, no deadlock\n");
    return 0;
}
