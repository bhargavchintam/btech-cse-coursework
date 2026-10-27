// mutual exclusion across processes with a POSIX semaphore
// cc semaphore_demo.c -o sem && ./sem
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<semaphore.h>
#include<sys/wait.h>

int main()
{
    sem_unlink("/os_sem_demo");
    sem_t *s = sem_open("/os_sem_demo", O_CREAT, 0644, 1);   // binary semaphore

    for(int k = 0; k < 3; k++)
    {
        if(fork() == 0)
        {
            sem_wait(s);                 // P - enter critical section
            printf("child %d in critical section\n", getpid());
            fflush(stdout);
            sleep(1);
            printf("child %d leaving\n", getpid());
            fflush(stdout);
            sem_post(s);                 // V - leave
            _exit(0);
        }
    }
    for(int k = 0; k < 3; k++)
        wait(NULL);
    sem_close(s);
    sem_unlink("/os_sem_demo");
    return 0;
}
