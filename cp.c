#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int inputFd, outputFd, openFlags;
    mode_t filePerms;
    ssize_t numRead;
    char buf[BUF_SIZE];

    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open input file
    inputFd = open(argv[1], O_RDONLY);
    if (inputFd == -1) {
        printf("Error opening input file.\n");
        exit(EXIT_FAILURE);
    }

    // Set flags and permissions for output file
    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    // Open output file
    outputFd = open(argv[2], openFlags, filePerms);
    if (outputFd == -1) {
        printf("Error opening output file.\n");
        close(inputFd);
        exit(EXIT_FAILURE);
    }

    // Copy contents
    while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0) {
        if (write(outputFd, buf, numRead) != numRead) {
            printf("Problem writing to output file.\n");
            close(inputFd);
            close(outputFd);
            exit(EXIT_FAILURE);
        }
    }

    if (numRead == -1) {
        printf("Error reading input file.\n");
    }

    close(inputFd);
    close(outputFd);

    return 0;
}
