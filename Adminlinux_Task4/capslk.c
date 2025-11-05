
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    //step1: open the brightness file
    int fd = open("/sys/class/leds/input1::capslock/brightness", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // step2: write the value (0 or 1)
    write(fd, argv[1], strlen(argv[1]));

    // step3: close the file
    close(fd);

    return 0;
}

