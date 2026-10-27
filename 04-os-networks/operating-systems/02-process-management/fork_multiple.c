// create n child processes.  cc fork_multiple.c -o fork_multiple && ./fork_multiple
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    int n = 3, i;
    for(i = 0; i < n; i++)
    {
        pid_t pid = fork();
        if(pid == 0)
        {
            printf("child %d : pid=%d ppid=%d\n", i + 1, getpid(), getppid());
            fflush(stdout);
            _exit(0);            // child stops here, else it forks too
        }
    }
    for(i = 0; i < n; i++)
        wait(NULL);
    printf("all %d children done\n", n);
    return 0;
}
