// replace the process image with execlp.  cc exec_demo.c -o exec_demo && ./exec_demo
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        printf("child running 'date':\n");
        fflush(stdout);          // exec discards the stdio buffer
        execlp("date", "date", (char*)NULL);
        perror("execlp");        // only reached if exec fails
        _exit(1);
    }
    wait(NULL);
    printf("parent: child finished\n");
    return 0;
}
