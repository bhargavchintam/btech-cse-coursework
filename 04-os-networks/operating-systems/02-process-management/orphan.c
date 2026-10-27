// an orphan process - parent dies first, child is reparented to init (pid 1)
// cc orphan.c -o orphan && ./orphan
#include<stdio.h>
#include<unistd.h>

int main()
{
    pid_t pid = fork();
    if(pid > 0)
    {
        printf("parent %d exiting first\n", getpid());
        return 0;
    }
    sleep(1);                    // parent is gone by now
    printf("child %d adopted, new ppid = %d\n", getpid(), getppid());
    return 0;
}
