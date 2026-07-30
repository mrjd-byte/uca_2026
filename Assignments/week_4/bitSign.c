#include <stdio.h>

int bitSign(int x) {
    return !!x || (x >> 31);
}

int main(){
    int a;
    int b;
    printf("Enter a integer: ");
    scanf("%d", &a);

    int result = bitSign(a);
    printf("The result of bitSign(%d) is: %d\n", a, result);
    return 0;
}