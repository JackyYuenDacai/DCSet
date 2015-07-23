#include"DCInfoT.h"
#include<stdio.h>
#include<sys/time.h>
#include<pthread.h>
#include<unistd.h>
DCInfo serv;
DCDNodeT<int> ClientNum;
void* IndivThread(void*arg){
	return (void*)8;
}
void AcceptProc(){
	while(serv.ServerCheckAccept()==true){
		serv.ServerAccept();
		if((pthread_create(NULL,NULL,IndivThread,(void*)serv.ClientsCount-1))!=0){
			printf("Error! %ld\n",serv.ClientsCount-1);
		}
		usleep(100);w
	}
}
int main(){
	bool Shut=true;

 	serv.SetIsServer(true);
 	serv.SetPort(0xDCC);
	serv.ServerInit();
 	serv.ServerBind();
 	serv.ServerListen();
 	Shut=false;
 	printf("MSG Server Start!#Port:%d\n",0xDCC);
 	while(Shut==false){
 		AcceptProc();
 		sleep(1);
 	}
 	return 0;
}

