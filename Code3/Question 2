#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main() 
{
    // Open a file with write access, create if necessary, truncate if exists
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    
    if (fd < 0) 
    {
        perror("open");   // Handle file opening error
        exit(1);
    }

    // Write from the parent process before forking
    write(fd, "Parent before fork\n", 19);

    // Create a new process using fork
    pid_t pid = fork();

    // Error handling for fork
    if (pid < 0) 
    {
        perror("fork");   // Handle fork failure
        exit(1);
    } 
    // Child process block
    else if (pid == 0) 
    {
        write(fd, "Child writing\n", 14);  // Child writes to the file
    } 
    // Parent process block
    else 
    {
        write(fd, "Parent writing\n", 15);  // Parent writes to the file
    }

    // Close the file descriptor after writing
    close(fd);

    return 0;
}

// Both child and parent processes can write to the file.
// The order in which they write is non-deterministic.
