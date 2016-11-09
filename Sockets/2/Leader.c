#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <assert.h>
#include <sys/socket.h>
#include <gmp.h>

char reqId[5],msgId[5];

int gId,range=10000;
char _pc[1024],_pk[1024];
int groupMembers[50];
int groupSize=0,l,curr=0;
int invalidAuth[50];
char __pk[1024];
int  __pkInd=0;

void init(){
	int i;
	for(i=0;i<50;i++){
		invalidAuth[i]=0;
	}

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
	int i=getRandom(index);
	index=hashIndex(i);
	return index;
}

int genKey(int num){
	char key[100];
	int x=0,i;
	key[0]='\0';
	if(num==4){
		for(i=num;i<l;i++){
			key[x++]=_pk[i];
		}
	}
	else{
		key[x++]=_pk[num];
	}
	key[x]='\0';
	int ans=atoi(key);
	return ans;
}
void getKey(int fd){
	char buf[1024];
	write(fd,reqId,strlen(reqId));
	sleep(rand()%2);
	read(fd,buf,1024);
	int i=0;
	for(i=0;i<strlen(buf);i++){
		if(buf[i]!='\0'){
			__pk[__pkInd++]=buf[i];
		}
	}
	return;
}
int main(int argc,char *argv[]){
	init();
	int nsfd,n,length,sfd;
	char buffer[1024];
	struct sockaddr_in saddr,_saddr,caddr;
	//Leader getting public and private keys from server
	printf("gid? ");
	scanf("%d",&gId);

	nsfd=socket(AF_INET,SOCK_STREAM,0);
	//assert(nsfd>=0);
	_saddr.sin_family=AF_INET;
	_saddr.sin_port=htons(atoi(argv[1]));
	_saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	int ret=connect(nsfd,(struct sockaddr*)&_saddr,sizeof(_saddr));

	sendGid(nsfd,gId);
	
	/*
	while(1){
	printf(">client:");
	fgets(buffer,1023,stdin);
	write(nsfd,buffer,strlen(buffer));
	read(nsfd,buffer,1023);
	printf(">server:%s\n",buffer);
	}
	*/

/*LEADER AUTHENTICATING ALL CLIENTS */

	l=strlen(_pk);

	sfd=socket(AF_INET,SOCK_STREAM,0);
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(atoi(argv[2]));
	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	bind(sfd,(struct sockaddr *) &saddr,sizeof(saddr));

	int fds[5],i=0,max=0;
	listen(sfd,5);

	while(max<5){
		printf("Started...\n");
		length=sizeof(caddr);
		fds[i]=accept(sfd,(struct sockaddr*)&caddr,&length);
		printf("Connection accepted\n");
		//Authentication value for the new group member
		char _i[3];
		sprintf(_i,"%d",i);
		//Send i to group user so he can be authenticated
		write(fds[i],_i,sizeof(_i));
		int authVal=getAuth(i);
		char _authVal[1024];
		sprintf(_authVal,"%d",authVal);
		read(fds[i],buffer,1023);
		
		if(!strcmp(_authVal,buffer)){
			printf("Client %i Authenticated Sending private key\n",i+1);
			//Send Confirmation
			int Confirmation=1;
			sprintf(buffer,"%d",Confirmation);
			write(fds[i],buffer,strlen(buffer));

			int key=genKey(groupSize);
			sleep(rand()%4);
			sprintf(buffer,"%d",key);
			write(fds[i],buffer,strlen(buffer));
			groupSize++;
		}
		else{
			int Confirmation=0;
			sprintf(buffer,"%d",Confirmation);
			write(fds[i],buffer,strlen(buffer));
			
			invalidAuth[i]=1;
		}
		i++;max++;
	}

	//if you need to get key run a for loop for all clients and send fd to getKey() also before the loop set __pkInd=0 and __pk[0]='\0'
	return 0;
}