#include <stdio.h>

int main(){

	int a = 0;
	int b = 1;
	int sum = 0;
	
	int n ;
	scanf("%d", &n);

	while(b<n){
		int x = b;
		b = a + b;
		a = x;

		if(b%2 == 0){
			sum+=b;
		}

	}
	printf("Sum of even numbers is : %d", sum);
	return 0;
}
