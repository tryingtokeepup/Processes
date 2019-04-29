// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *f = fopen("text.txt", "w");
    int rc = fork();
    // ------------------------------------------------ child process starts executing here
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child process satisfies this branch
        fprintf(f, "%s", "I'm a teapot, short and stout. ");
        // first is the file, second is the type, third is the msg
    }
    else
    {
        wait(NULL);
        // this waits until there are no child processes left to execute, and then it executes the below code
        fprintf(f, "%s", " I'm a cool guy, short and stout. And im the parent!");
        fclose(f);
    }
    printf("cool, this works! i love c. sort of.");
    return 0;
}

// FILE *f = fopen("file.txt", "w");
// if (f == NULL)
// {
//     printf("Error opening file!\n");
//     exit(1);
// }

// /* print some text */
// const char *text = "Write this to the file";
// fprintf(f, "Some text: %s\n", text);

// /* print integers and floats */
// int i = 1;
// float py = 3.1415927;
// fprintf(f, "Integer: %d, float: %f\n", i, py);

// /* printing single chatacters */
// char c = 'A';
// fprintf(f, "A character: %c\n", c);

// fclose(f);