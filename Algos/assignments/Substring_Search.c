#include <stdio.h>

int find_substring(const char *haystack, const char *needle) {
    int i, j;

 
    if (needle[0] == '\0')
        return 0;

    for (i = 0; haystack[i] != '\0'; i++) {

        for (j = 0; needle[j] != '\0'; j++) {

            if (haystack[i + j] != needle[j])
                break;

        }

        if (needle[j] == '\0')
            return i;
    }

    return -1;
}

int main() {
    char haystack[] = "Coding Academy";
    char needle[] = "cad";

    printf("%d\n", find_substring(haystack, needle));

    return 0;
}
