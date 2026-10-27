// SIGALRM after a timer with alarm().  cc alarm_demo.c -o alarm_demo && ./alarm_demo
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handler(int sig)
{
    printf("alarm went off\n");
}

int main()
{
    signal(SIGALRM, handler);
    alarm(1);
    printf("waiting for the alarm...\n");
    pause();
    printf("done\n");
    return 0;
}
