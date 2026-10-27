// parent signals a child with kill().  cc kill_demo.c -o kill_demo && ./kill_demo
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>

void onterm(int sig)
{
    printf("child got SIGTERM, exiting\n");
    fflush(stdout);
    _exit(0);
}

int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        signal(SIGTERM, onterm);
        printf("child %d waiting for a signal\n", getpid());
        fflush(stdout);
        while(1) pause();
    }
    sleep(1);
    printf("parent sending SIGTERM to %d\n", pid);
    kill(pid, SIGTERM);
    wait(NULL);
    printf("parent done\n");
    return 0;
}
