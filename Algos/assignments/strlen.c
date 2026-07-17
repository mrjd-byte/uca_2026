#include <stdio.h>

int my_strlen(const char *str) {
    const char *start = str;

    while (*str != '\0') {
        str++;
    }
    return str - start;
}

int main() {
    char str[] = "Hello World";

    printf("Length = %d\n", my_strlen(str));

    return 0;
}
