// System V message queue - sender.  cc msg_send.c -o msg_send && ./msg_send
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

struct msgbuf { long mtype; char mtext[100]; };

int main()
{
    int id = msgget(2345, IPC_CREAT | 0666);
    struct msgbuf m;
    m.mtype = 1;
    strcpy(m.mtext, "message queue works");
    msgsnd(id, &m, sizeof m.mtext, 0);
    printf("sent: %s\n", m.mtext);
    return 0;
}
