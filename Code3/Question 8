#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUFSZE 32

int main(int argc, char *argv[])
{
    // Buffer and pipe setup
    char buff[BUFSZE];
    int p[2];

    // Create a pipe
    if (pipe(p) < 0) {
        exit(1);  // Exit if pipe creation fails
    }

    // First fork to create child #1
    int rc1 = fork();
    if (rc1 < 0) {
        // Handle fork failure
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    } else if (rc1 == 0) {
        // Child #1 process block
        printf(" Child #1 ");
        
        // Close the reading end of the pipe
        close(p[0]);
        
        // Redirect standard output to the pipe's writing end
        dup2(p[1], 1);

        // Send message to the pipe
        printf("_This is getting sent to the pipe_");
    } else {
        // Parent process block

        // Second fork to create child #2
        int rc2 = fork();
        if (rc2 < 0) {
            // Handle fork failure
            fprintf(stderr, "fork #2 failed\n");
            exit(1);
        } else if (rc2 == 0) {
            // Child #2 process block
            printf(" Child #2 ");

            // Close the writing end of the pipe
            close(p[1]);

            // Redirect standard input to the pipe's reading end
            dup2(p[0], 0);

            // Buffer to read data from the pipe
            char buff[512];
            
            // Read data from the pipe (stdin redirected to pipe)
            read(STDIN_FILENO, buff, 512);

            // Print the buffer content
            printf("%s", buff);
        } else {
            // Parent waits for the second child to finish
            int wc = waitpid(rc2, NULL, 0);
            printf("goodbye");  // Parent process message
        }
    }

    return 0;
}
