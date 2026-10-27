// catch SIGINT with a handler.  cc signal_handler.c -o signal_handler && ./signal_handler
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handler(int sig)
{
    printf("caught signal %d (SIGINT)\n", sig);
}

int main()
{
    signal(SIGINT, handler);
    printf("normally you press Ctrl+C; here we raise it once\n");
    raise(SIGINT);
    printf("back in main, program continues\n");
    return 0;
}
