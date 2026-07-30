#include <stdio.h>
int bitAnd(int x, int y) {
    return ~(~x | ~y);
}
int main() {
    int a;
    int b; 
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    int result = bitAnd(a, b);
    printf("The result of bitAnd(%d, %d) is: %d\n", a, b, result);
    return 0;
}   