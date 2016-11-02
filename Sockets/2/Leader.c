#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <assert.h>
#include <sys/socket.h>
#include <gmp.h>

int gId,range=10000;
char _pc[1024],_pk[1024];


int getRandom(int seed){
	srand(seed);
	return abs(rand()%range);
}

int hashIndex(index){
	index=index*2+1452*(index-1)%1000-11451;
	index*=index;
	index=(index)%range;
	return index;
}

void sendGid(int nsfd,int gId){
	char _gId[1024];
	sprintf(_gId,"%d",gId);
	//printf("%s\n",_gId);
	write(nsfd,_gId,strlen(_gId));

	//read(nsfd,_gid,)
	//sleep(rand()%4);
	//printf("woke up\n");
	read(nsfd,_pc,1023);
	//printf("%s\n", _pc);
	sleep(rand()%4);
	read(nsfd,_pk,1023);
	printf("pc:%s\npk:%s\n",_pc,_pk);
}

int getAuth(int index){
	int index=getRandom(index);
	index=hashIndex(index);
	return index;
}


int main(int argc,char *argv[]){

scanf("%d",&gId);

int nsfd,n,length.ret,sfd;
struct sockaddr_in saddr,_saddr,caddr;
char buffer[1024];
nsfd=socket(AF_INET,SOCK_STREAM,0);
//assert(nsfd>=0);
_saddr.sin_family=AF_INET;
_saddr.sin_port=htons(atoi(argv[1]));
_saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
int ret=connect(nsfd,(struct sockaddr*)&_saddr,sizeof(_saddr));


sendGid(nsfd,gId);

/*while(1){
printf(">client:");
fgets(buffer,1023,stdin);
write(nsfd,buffer,strlen(buffer));
read(nsfd,buffer,1023);
printf(">server:%s\n",buffer);
}
*/


/*LEADER AUTHENTICATING ALL CLIENTS */


	sfd=socket(AF_INET,SOCK_STREAM,0);
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(atoi(argv[2]));
	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	bind(sfd,(struct sockaddr *) &saddr,sizeof(saddr));

	int fds[5],i=0;

	while(max<5){
		printf("Started...\n");
		length=sizeof(caddr);
		fds[i]=accept(sfd,(struct sockaddr*)&caddr,&length);
		printf("Connection accepted\n");

		int authVal=getAuth(i);
		char _authVal[1024];
		sprintf(_authVal,"%d",authVal);
		read(fds[i],buffer,1023);
		
		if(!strcmp(_authVal,buffer)){
			printf("Client %i Authenticated Sending private key\n",i);
			buffer=getKey(_pk,i);
			write(fds[i],buffer,strlen(buffer));
		}
		
		i++;max++;
	}

return 0;
}