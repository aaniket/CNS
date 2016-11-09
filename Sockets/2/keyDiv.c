
#include <stdlib.h>
#include <stdio.h>

int main(){
	int key;
	scanf("%d",&key);
	char buffer[100];
	sprintf(buffer,"%o",key);
	printf("%s\n%ld",buffer,sizeof(buffer)/sizeof(buffer[0]));
	return 0;
}