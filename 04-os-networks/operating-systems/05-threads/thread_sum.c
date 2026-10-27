// parallel array sum split across threads.  cc thread_sum.c -lpthread -o thread_sum && ./thread_sum
#include<stdio.h>
#include<pthread.h>

#define N 100
#define T 4

int a[N];

typedef struct { int lo, hi; long sum; } chunk;

void* worker(void *arg)
{
    chunk *c = (chunk*)arg;
    c->sum = 0;
    for(int i = c->lo; i < c->hi; i++)
        c->sum += a[i];
    return NULL;
}

int main()
{
    for(int i = 0; i < N; i++)
        a[i] = i + 1;                    // 1..100

    pthread_t t[T];
    chunk c[T];
    int per = N / T;
    for(int k = 0; k < T; k++)
    {
        c[k].lo = k * per;
        c[k].hi = (k == T - 1) ? N : (k + 1) * per;
        pthread_create(&t[k], NULL, worker, &c[k]);
    }
    long total = 0;
    for(int k = 0; k < T; k++)
    {
        pthread_join(t[k], NULL);
        total += c[k].sum;
    }
    printf("sum of 1..%d = %ld\n", N, total);
    return 0;
}
