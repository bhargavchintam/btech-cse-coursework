// System V message queue - receiver.  cc msg_receive.c -o msg_receive && ./msg_receive
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msgbuf { long mtype; char mtext[100]; };

int main()
{
    int id = msgget(2345, 0666);
    struct msgbuf m;
    msgrcv(id, &m, sizeof m.mtext, 1, 0);
    printf("received: %s\n", m.mtext);
    msgctl(id, IPC_RMID, NULL);
    return 0;
}
