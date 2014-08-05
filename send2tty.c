#include <termios.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

int main(int argc, char *argv[])
{
    if (argc < 3 ){
        printf("usage: %s tty_file string\n", argv[0]);
        exit(-1);
    }
    int fd, serial, i;
    fd = open(argv[1], O_RDONLY);
    if(fd==-1){
        printf("error when open %s\n", argv[1]);
    }
    for(i=0; argv[2][i] !=0; i++){
        ioctl(fd, TIOCSTI,(char*)&argv[2][i]);
    }
    ioctl(fd, TIOCSTI,"\n");
    close(fd);
}
