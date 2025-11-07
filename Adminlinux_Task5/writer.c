#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 0x1234u
#define SIZE 100u

int main(void)
{
    int shmid = shmget(KEY, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget failed");
        exit(EXIT_FAILURE);
    }

    char *ptr = shmat(shmid, NULL, 0);
    if (ptr == (char *) -1) {
        perror("shmat failed");
        exit(EXIT_FAILURE);
    }

    strcpy(ptr, "Hello from process A");

    printf("Process A wrote: %s\n", ptr);

    if (shmdt(ptr) == -1) {
        perror("shmdt failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
