// pass an argument and get a result back.  cc thread_args.c -lpthread -o thread_args && ./thread_args
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* square(void *arg)
{
    int n = *(int*)arg;
    int *res = malloc(sizeof(int));
    *res = n * n;
    return res;
}

int main()
{
    pthread_t t;
    int n = 7;
    void *ret;
    pthread_create(&t, NULL, square, &n);
    pthread_join(t, &ret);
    printf("square of %d = %d\n", n, *(int*)ret);
    free(ret);
    return 0;
}
