// anonymous pipe between parent and child.  cc pipe_demo.c -o pipe_demo && ./pipe_demo
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    int fd[2];
    char buf[100];
    pipe(fd);
    pid_t pid = fork();
    if(pid == 0)
    {
        close(fd[0]);                    // child writes
        char *msg = "hello from child";
        write(fd[1], msg, strlen(msg) + 1);
        close(fd[1]);
        _exit(0);
    }
    close(fd[1]);                        // parent reads
    read(fd[0], buf, sizeof buf);
    printf("parent received: %s\n", buf);
    close(fd[0]);
    wait(NULL);
    return 0;
}
