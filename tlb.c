#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <sched.h>

// Function to get time in microseconds
double get_time_in_microseconds() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return time.tv_sec * 1e6 + time.tv_usec;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <number_of_pages> <number_of_trials>\n", argv[0]);
        exit(1);
    }

    // Pin the program to a single CPU to avoid TLB inconsistencies
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(0, &mask); // Pin to CPU 0
    if (sched_setaffinity(0, sizeof(mask), &mask) == -1) {
        perror("sched_setaffinity");
        exit(1);
    }

    // Parse input arguments
    int num_pages = atoi(argv[1]);
    int num_trials = atoi(argv[2]);
    int page_size = getpagesize();
    int *array = (int *)malloc(num_pages * page_size);
    if (!array) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize the array to avoid the cost of first-time page access
    for (int i = 0; i < num_pages * page_size / sizeof(int); i++) {
        array[i] = i;
    }

    // Variable to prevent compiler optimization
    volatile int sink = 0;

    // Measure the time to access each page
    double start_time = get_time_in_microseconds();
    for (int t = 0; t < num_trials; t++) {
        for (int i = 0; i < num_pages; i++) {
            sink += array[i * page_size / sizeof(int)];
        }
    }
    double end_time = get_time_in_microseconds();

    // Calculate the average time per page access
    double elapsed = (end_time - start_time) / (num_pages * num_trials);
    printf("Average time per page access: %.2f microseconds\n", elapsed);

    // Free allocated memory
    free(array);
    return 0;
}
