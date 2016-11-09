#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <assert.h>
#include <sys/socket.h>
#include <pthread.h>
int range=10000;
char _pk[50];
#define true 1
#define false 0

char reqId[5],msgId[5];

void init(){

	int x=1234,y=2345;
	sprintf(reqId,"%d",x);
	sprintf(msgId,"%d",y);
}

int getRandom(int seed){
	srand(seed);
	return abs(rand()%range);
}

int hashIndex(int index){
	index=index*2+1452*(index-1)%1000-11451;
	index*=index;
	index=(index)%range;
	return index;
}
int getAuth(int index){
	int i=getRandom(index);
	index=hashIndex(i);
	return index;
}


int Authenticate(int nsfd){
	char _seed[50];
	read(nsfd,_seed,50);
	int seed=atoi(_seed);
	int authVal=getAuth(seed);
	char buffer[50];
	sprintf(buffer,"%d",authVal);
	write(nsfd,buffer,strlen(buffer));
	buffer[0]='\0';
	read(nsfd,buffer,50);
	int confirmation=atoi(buffer);
	if(confirmation)return true;
	return false;

}

int main(int argc,char*argv[]){
	init();

	pthread_t rt,wt;
	

	int nsfd,n,length;
	struct sockaddr_in saddr;
	char buffer[1024];
	nsfd=socket(AF_INET,SOCK_STREAM,0);
	//assert(nsfd>=0);
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(atoi(argv[1]));
	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	int ret=connect(nsfd,(struct sockaddr*)&saddr,sizeof(saddr));
	if(!Authenticate(nsfd)){
		//Exit the process
		return 0;
	}

	read(nsfd,_pk,50);
	printf("PK : %s\n",_pk);

	while(1){
		
	}
	return 0;
}