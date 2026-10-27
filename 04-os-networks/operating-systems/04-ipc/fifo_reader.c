// named pipe (FIFO) - reader side.  cc fifo_reader.c -o fifo_reader && ./fifo_reader
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
    char buf[100];
    mkfifo("myfifo", 0666);
    int fd = open("myfifo", O_RDONLY);
    read(fd, buf, sizeof buf);
    printf("reader got: %s\n", buf);
    close(fd);
    unlink("myfifo");
    return 0;
}
