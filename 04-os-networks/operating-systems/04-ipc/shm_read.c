// System V shared memory - reader.  cc shm_read.c -o shm_read && ./shm_read
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
    int id = shmget(1234, 128, 0666);
    char *p = shmat(id, NULL, 0);
    printf("reader got: %s\n", p);
    shmdt(p);
    shmctl(id, IPC_RMID, NULL);          // remove the segment
    return 0;
}
