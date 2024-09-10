#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define true 1
#define false 1

int main()
{
    // Open or create a file with read-write permissions
    int backend_file = open("backend_file.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);

    // Fork to create a new process
    int rc = fork();

    if (rc == 0)  // Child process block
    {
        // Child writes "true" to the backend file
        write(backend_file, "true", 4);
        printf("I am child process\n");
        printf("hello\n");

        // Close the file in child process
        close(backend_file);
    }
    else if (rc > 0)  // Parent process block
    {
        char buffer[4];  // Buffer to store read data
        buffer[4] = '\0';  // Null-terminate the buffer

        // Parent continuously checks the file content
        while (strcmp(buffer, "true\0") != 0)
        {
            // Close and reopen the file to see the updated content
            close(backend_file);
            backend_file = open("backend_file.txt", O_CREAT | O_RDWR, S_IRWXU);
            read(backend_file, buffer, 4);
            usleep(10 * 1000);  // Sleep for 10 milliseconds
        }

        printf("I am parent process\n");
        printf("goodbye\n");
    }

    // Close the file descriptor in parent process
    close(backend_file);

    return 0;
}

// This program demonstrates that the parent process can wait for the child to update the file.
