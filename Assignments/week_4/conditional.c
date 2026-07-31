#include <stdio.h>

int conditional(int x, int y, int z) {
  return ((~!!x + 1) & y) | (~(~!!x + 1) & z);
}

int main(){
    int num1;
    int num2;
    int num3;

    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    int ans = conditional(num1, num2, num3);
    printf("The returned value is %d \n", ans);
}