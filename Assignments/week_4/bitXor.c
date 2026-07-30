#include <stdio.h>

int bitXor(int x, int y) {
  return ~(~(x & ~y) & ~(~x & y));
}

int main(){
    int a;
    int b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    int result = bitXor(a, b);
    printf("The result of bitXor(%d, %d) is: %d\n", a, b, result);
    return 0;
}