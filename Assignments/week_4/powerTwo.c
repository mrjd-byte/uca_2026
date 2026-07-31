#include <stdio.h>

int isPower2(int x) {
  return !(x & (x + (~1 + 1)));
}


int main(){
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);

    int result = isPower2(a);
    printf("The result of isPower2(%d) is: %d\n", a, result);
    return 0;
}