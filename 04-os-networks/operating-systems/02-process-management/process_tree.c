// a small process tree using nested fork.  cc process_tree.c -o process_tree && ./process_tree
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    printf("A: pid=%d\n", getpid());
    fflush(stdout);              // flush before fork or the buffer gets copied to the child
    pid_t b = fork();
    if(b == 0)
    {
        printf("  B: pid=%d ppid=%d\n", getpid(), getppid());
        fflush(stdout);
        pid_t c = fork();
        if(c == 0)
            printf("    C: pid=%d ppid=%d\n", getpid(), getppid());
        else
            wait(NULL);
        fflush(stdout);
        _exit(0);
    }
    wait(NULL);
    return 0;
}
