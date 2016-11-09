
#include <stdlib.h>
#include <stdio.h>

int main(){
	int key;
	scanf("%d",&key);
	char buffer[100];
	itoa(key,buffer,2);
	printf("%s\n",buffer);
	return 0;
}