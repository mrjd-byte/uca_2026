#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    size_t len;
    off_t offset;
    int fd;
    char *buf;
    ssize_t numRead, numWritten;

    if (argc < 3) {
        printf("Usage: %s <file> {r<length>|w<string>|s<offset>...}\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Opening file \"%s\"...\n", argv[1]);

    fd = open(argv[1], O_RDWR | O_CREAT,
              S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IROTH);

    if (fd == -1) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    printf("File opened successfully.\n");

    for (int i = 2; i < argc; i++) {

        switch (argv[i][0]) {

        case 'w':

            printf("\nWriting \"%s\"...\n", &argv[i][1]);

            numWritten = write(fd, &argv[i][1], strlen(&argv[i][1]));

            if (numWritten == -1) {
                perror("Write failed");
                close(fd);
                exit(EXIT_FAILURE);
            }

            printf("Successfully wrote %zd bytes.\n", numWritten);

            break;          

        case 'r':

            len = atoi(&argv[i][1]);

            printf("\nReading %zu bytes...\n", len);

            buf = malloc(len);

            if (buf == NULL) {
                perror("Memory allocation failed");
                close(fd);
                exit(EXIT_FAILURE);
            }

            numRead = read(fd, buf, len);

            if (numRead == -1) {
                perror("Read failed");
                free(buf);
                close(fd);
                exit(EXIT_FAILURE);
            }

            if (numRead == 0) {
                printf("End of file reached.\n");
                free(buf);
                break;
            }

            printf("Successfully read %zd bytes.\n", numRead);

            printf("Data: ");

            for (int j = 0; j < numRead; j++)
                printf("%c", (unsigned char)buf[j]);

            printf("\n");

            free(buf);

            break;

        case 's':

            offset = atol(&argv[i][1]);

            printf("\nMoving file pointer to byte %ld...\n", (long)offset);

            if (lseek(fd, offset, SEEK_CUR) == -1) {
                perror("Seek failed");
                close(fd);
                exit(EXIT_FAILURE);
            }

            printf("File pointer moved successfully.\n");

            break;

        default:

            printf("Invalid argument \"%s\"\n", argv[i]);
            printf("Argument must start with one of [w, r, s]\n");

            close(fd);

            exit(EXIT_FAILURE);
        }
    }

    if (close(fd) == -1) {
        perror("Failed to close file");
        exit(EXIT_FAILURE);
    }

    printf("\nFile closed successfully.\n");
    printf("Program completed successfully.\n");

    return EXIT_SUCCESS;
}
