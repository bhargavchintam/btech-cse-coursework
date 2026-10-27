// signal handling the reliable way, with sigaction.  cc sigaction_demo.c -o sigaction_demo && ./sigaction_demo
#include<stdio.h>
#include<signal.h>

void handler(int sig)
{
    printf("sigaction caught signal %d\n", sig);
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);
    raise(SIGINT);
    printf("handled, continuing\n");
    return 0;
}
