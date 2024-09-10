#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    // Fork to create a new process
    int rc = fork();

    if (rc == 0)  // Child process block
    {
        // Attempt to wait for a child process, which doesn't exist for the child itself
        int wc = wait(NULL);
        printf("child process\n");
        printf("Return code from wait() is %d\n", wc);  // Will return -1, as the child has no child process
    }
    else if (rc > 0)  // Parent process block
    {
        // Parent process runs and does not wait in this example
        printf("parent process\n");
    }
    else  // Fork failed
    {
        // Error handling for fork failure
        fprintf(stderr, "Fork failed\n");
    }

    return 0;
}

// Explanation:
// - wait() returns the process ID of the terminated child.
// - It returns -1 if there is an error, such as no child process to wait on.
// - In this code, the child calls wait(), but since it has no child process, it returns -1.
