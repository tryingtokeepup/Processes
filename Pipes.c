#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

// the command `man pipe` can be used to list the commands we can use in c! handy dandy.
int main(void)
{
    //     char buf[128];
    //     int fd[2];
    //     // fd[0];
    //     // fd[1];

    //     pipe(fd);

    //     char *message_one = "Hello World!\n";

    //     int bytes_written = write(fd[1], message_one, strlen(message_one));

    //     int bytes_read = read(fd[0], buf, sizeof buf);

    //     write(STDOUT_FILENO, buf, bytes_read);
    //     //printf(buf);
    //     return 0;

    pid_t pid = fork();
    if (pid == 0)
    {

        printf("Child process!\n");
        exit(3);
    }
    else
    {
        printf("Parent process!\n");
        getchar();

        wait(NULL);

        printf("Press RETURN to exit out of here!\n");

        getchar();
    }
    return 0;
}
