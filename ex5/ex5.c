// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main(void)
{
    // Your code here
    char buf[128];
    int fd[2];
    pipe(fd);

    pid_t pid = fork();
    if (pid == 0)
    {

        printf("Child process!\n");

        write(fd[1], msg1, strlen(msg1));
        write(fd[1], msg2, strlen(msg2));
        write(fd[1], msg3, strlen(msg3));

        exit(3);
    }
    else
    {
        printf("Parent process!\n");

        wait(NULL);
        int message_reader = read(fd[0], buf, sizeof buf);
        write(STDOUT_FILENO, buf, message_reader);
        printf("Press RETURN to exit out of here!\n");
        getchar();
    }
    return 0;
}
