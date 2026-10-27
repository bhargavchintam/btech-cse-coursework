// gcc 07_time_and_date.c -o datetime
#include<stdio.h>
#include<time.h>

int main()
{
    time_t t;
    struct tm *info;
    char buf[64];

    time(&t);
    info = localtime(&t);
    strftime(buf, sizeof(buf), "%d-%m-%Y %H:%M:%S", info);
    printf("Current date and time: %s\n", buf);
    return 0;
}
