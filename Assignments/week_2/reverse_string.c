#include <stdio.h>
#include <string.h>

void reverse_string(char *str){
	int n=strlen(str);
	for(int i = 0; i< n/2; i++){
		char ch = str[i];
		str[i] = str[n-i-1];
	       	str[n-i-1] = ch;	
	}
}

int main(){
	char str[50]; 

    	printf("Enter a string upto 50 chars:");
  
   	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';

    	printf("You entered: %s\n", str);
	
	reverse_string(str);
    	printf("Reversed string: %s\n", str);
    	return 0;

}
