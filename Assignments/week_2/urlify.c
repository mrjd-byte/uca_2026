#include <stdio.h>

void url_encode(char *str, int true_length) {
    int spaces = 0;

    for (int i = 0; i < true_length; i++) {
        if (str[i] == ' ')
            spaces++;
    }

    int new_length = true_length + spaces * 2;

    str[new_length] = '\0';

    int i = true_length - 1;
    int j = new_length - 1;

    while (i >= 0) {

        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        }
        else {
            str[j--] = str[i];
        }

        i--;
    }
}

int main() {
    char str[30] = "Hello World   ";

    url_encode(str, 11);

    printf("%s\n", str);

    return 0;
}
