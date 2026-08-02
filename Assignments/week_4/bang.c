#include <stdio.h>

int bang(int x){
    return (((~x + 1) | x) >> 31) + 1;
}

int main(){
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);

    int result = bang(a);
    printf("The result of bang(%d) is: %d\n", a, result);
    return 0;
}