#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() 
{
    int x = 100;
    pid_t pid = fork();  // Fork creates a new process

    // Error handling for fork
    if (pid < 0) {
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } 
    // Child process block
    else if (pid == 0) 
    {
        printf("Child process: x = %d\n", x);
        x = 200;  // Modify x in the child process
        printf("Child process (after changing x): x = %d\n", x);
    } 
    // Parent process block
    else 
    {
        printf("Parent process: x = %d\n", x);
        x = 300;  // Modify x in the parent process
        printf("Parent process (after changing x): x = %d\n", x);
    }

    return 0;
}

// When fork() is called, the child and parent processes operate in separate address spaces.
