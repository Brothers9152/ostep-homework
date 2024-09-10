#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    // Fork to create a new process
    int rc = fork();

    if (rc == 0)  // Child process block
    {
        // Print the child process ID
        printf("child process. PID is %d\n", getpid());
        exit(0);  // Exit the child process
    }
    else if (rc > 0)  // Parent process block
    {
        int status;  // Variable to store the child's exit status
        
        // Wait for the specific child process to terminate using waitpid()
        waitpid(rc, &status, 0);

        // Print the parent process ID
        printf("parent process. PID is %d\n", getpid());
    }
    else  // Fork failed
    {
        // Error handling for fork failure
        fprintf(stderr, "Fork Failed\n");
    }

    return 0;
}

// Explanation:
// - waitpid() allows the parent to wait for a specific child process (identified by its process ID).
// - It can be useful when the parent wants to wait for a particular child process instead of all child processes.
