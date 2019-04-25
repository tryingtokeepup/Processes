// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int rc = fork();
    // ------------------------------------------------ child process starts executing here
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child process satisfies this branch
        //bin is a linux kernel, and it seems to just ref the directory that ex4 is in
        execl("/bin/ls", "ls", "-1", (char *)0);
    }
    else
    {
        wait(NULL);
        // this waits until there are no child processes left to execute, and then it executes the below code
        execl("/bin/ls", "ls", "-1", (char *)0);
    }

    return 0;
}
