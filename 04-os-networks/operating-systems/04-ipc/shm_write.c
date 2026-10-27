// System V shared memory - writer.  cc shm_write.c -o shm_write && ./shm_write
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
    int id = shmget(1234, 128, IPC_CREAT | 0666);
    char *p = shmat(id, NULL, 0);
    strcpy(p, "data in shared memory");
    printf("writer put: %s\n", p);
    shmdt(p);
    return 0;
}
