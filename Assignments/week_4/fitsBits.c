#include <stdio.h>

int fitsBits(int x, int n) {
    int shift = 32 + (~n +1);

    return !(((x << shift) >> shift) ^ x);
}

int main(){
    int a;
    int b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    int result = fitsBits(a, b);
    printf("The result of fitBits(%d, %d) is: %d\n", a, b, result);
    return 0;
}