#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>


/*
 * demo of mmap, map a file and write to Standard output.
 */
void copy(int fd, int size) {
    char *buf;
    buf = mmap(NULL,size,PROT_READ,MAP_PRIVATE,fd,0);
    write(1,buf,size);
    return;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage: %s <filename>\n", argv[0]);
        exit(-1);
    }

    struct stat stat_1;
    int fd = open(argv[1],O_RDONLY,0);
    fstat(fd, &stat_1);
    int size = stat_1.st_size;

    copy(fd, size);

    return 0;
}
