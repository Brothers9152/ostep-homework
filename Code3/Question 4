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
        printf("Executing Child Process\n");
        
        // Execute the 'ls' command using execl (executes a program)
        execl("/bin/ls", "ls", NULL);  // "/bin/ls" is the path to the ls command

        // If execl fails, it will return and the following line will be executed
        perror("execl failed");
        exit(1);
    }
    else if (rc > 0)  // Parent process block
    {
        // Wait for the child process to finish
        wait(NULL);
    }
    else  // Fork failed
    {
        fprintf(stderr, "Error occurred during fork()\n");
        exit(1);
    }

    return 0;
}

// Explanation:
// - Functions with 'l' in their name (e.g., execl) take arguments separated by commas.
// - Functions with 'v' in their name take arguments as vectors (arrays).
// - Functions with 'e' in their name also take environment variables as an additional argument.
