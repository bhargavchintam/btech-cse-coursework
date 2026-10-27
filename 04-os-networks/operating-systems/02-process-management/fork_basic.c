// fork basics - parent and child.  cc fork_basic.c -o fork_basic && ./fork_basic
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if(pid == 0)
        printf("child : pid=%d ppid=%d\n", getpid(), getppid());
    else
    {
        wait(NULL);
        printf("parent: pid=%d child=%d\n", getpid(), pid);
    }
    return 0;
}
