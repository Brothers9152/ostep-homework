#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    // Fork to create a new process
    int rc = fork();

    if (rc == 0)  // Child process block
    {
        // Close the standard output file descriptor
        close(STDOUT_FILENO);

        // Attempt to write something with printf, but it won't appear since stdout is closed
        printf("Write something\n");
    }
    else if (rc > 0)  // Parent process block
    {
        // Wait for the child process to finish
        wait(NULL);

        // This will print to the console since parent's stdout is still open
        printf("Parent process\n");
    }
    else  // Fork failed
    {
        // Handle fork failure
        printf("Fork Failed\n");
    }

    return 0;
}

// Explanation:
// - Closing STDOUT_FILENO (standard output) prevents the child process from printing anything using printf.
// - The parent process still has its stdout open, so it can continue printing to the console.
