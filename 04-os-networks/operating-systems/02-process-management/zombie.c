// a zombie process - child exits, parent hasn't reaped it yet
// cc zombie.c -o zombie && ./zombie   (run 'ps' while it sleeps to see <defunct>)
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        printf("child %d exiting now\n", getpid());
        fflush(stdout);
        _exit(0);
    }
    printf("parent %d not waiting yet, child %d is a zombie\n", getpid(), pid);
    sleep(1);
    wait(NULL);                  // reap it
    printf("child reaped\n");
    return 0;
}
