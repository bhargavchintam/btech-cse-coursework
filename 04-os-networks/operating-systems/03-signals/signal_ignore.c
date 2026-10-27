// ignore a signal with SIG_IGN.  cc signal_ignore.c -o signal_ignore && ./signal_ignore
#include<stdio.h>
#include<signal.h>

int main()
{
    signal(SIGINT, SIG_IGN);
    printf("SIGINT is now ignored, raising it...\n");
    raise(SIGINT);
    printf("still alive - the signal was ignored\n");
    return 0;
}
