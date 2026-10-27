// named pipe (FIFO) - writer side.  cc fifo_writer.c -o fifo_writer && ./fifo_writer
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

int main()
{
    mkfifo("myfifo", 0666);
    int fd = open("myfifo", O_WRONLY);
    char *msg = "message through the fifo";
    write(fd, msg, strlen(msg) + 1);
    printf("writer sent: %s\n", msg);
    close(fd);
    return 0;
}
