// collect a child's exit status.  cc wait_demo.c -o wait_demo && ./wait_demo
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    int status;
    pid_t pid = fork();
    if(pid == 0)
    {
        printf("child exiting with 42\n");
        exit(42);
    }
    waitpid(pid, &status, 0);
    if(WIFEXITED(status))
        printf("parent: child %d exited, status = %d\n", pid, WEXITSTATUS(status));
    return 0;
}
