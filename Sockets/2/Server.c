#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <assert.h>
#include <gmp.h>
#include <math.h>

int max=0,gid;
int range=100000;

int getRandom(int seed){
	srand(seed);
	return abs(rand()%range);
}

int main(int argc,char *argv[]){

	//printf("%d %d",getRandom(1000),getRandom(getRandom(1000)*1000));
	struct sockaddr_in saddr,caddr;
	int n,ret,nsfd,sfd;
	char buffer[1024];
	int length;

	sfd=socket(AF_INET,SOCK_STREAM,0);
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(atoi(argv[1]));
	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	bind(sfd,(struct sockaddr *) &saddr,sizeof(saddr));
	//assert(ret>=0);

	listen(sfd,2);
	
	while(max<2){
		printf("Started...\n");
		length=sizeof(caddr);
		nsfd=accept(sfd,(struct sockaddr*)&caddr,&length);
		printf("Connection accepted\n");
		read(nsfd,buffer,1023);
		
		max++;


		printf(">Leader:%s\n",buffer);
	
		gid=atoi(buffer);

		//write(nsfd,buffer,strlen(buffer));		

		sprintf(buffer,"%d",getRandom(gid));

		write(nsfd,buffer,strlen(buffer));
		printf("pc:%s\n",buffer);

		sleep(rand()%4);
		sprintf(buffer,"%d",getRandom(gid*getRandom(gid)));

		write(nsfd,buffer,strlen(buffer));
		printf("pk:%s\n",buffer);

	}
	
	return 0;
}