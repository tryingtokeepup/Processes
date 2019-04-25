// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main(void)
{
    // Your code here
    pid_t pid = fork();
    if (pid == 0)
    {

        char buf[128];
        int fd[2];
        pipe(fd);
        char *message_one = "Hello World!\n";
        char *message_two = "My name is Kai!\n";
        char *message_three = "And I like cookies!\n";

        exit(3);
    }
    else
    {
        printf("Parent process!\n");

        wait(NULL);

        printf("Press RETURN to exit out of here!\n");
        getchar();
    }
    return 0;
}
