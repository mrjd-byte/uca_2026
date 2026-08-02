#include <stdio.h>

int getByte(int x, int n) {
    return (x >> (n << 3)) & 0xFF;
}

int main() {
    int x = 0x12345678;

    printf("Byte 0: 0x%X\n", getByte(x, 0));
    printf("Byte 1: 0x%X\n", getByte(x, 1));
    printf("Byte 2: 0x%X\n", getByte(x, 2));
    printf("Byte 3: 0x%X\n", getByte(x, 3));

    return 0;
}