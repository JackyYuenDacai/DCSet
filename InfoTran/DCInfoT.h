#pragma once
#include"DCDCode.h"
#include"DCDNodeT.h"
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>
#include<netdb.h>

#define CLIENT_PORT 0xDCDD
#define MAX_CLIENTS 0xDC

class DCInfo{
public: 
	bool IsS;
	bool Isipv4;
	bool IsError;
	bool IsBlocking;
	int MSockFd;
	int flags;
	int LRecvCount;
	char*RecvBuf;
	long ClientsCount;
	short ClientPort;
	short ServerPort;
	fd_set ClientCheck;
	fd_set ServerCheck;
	timeval CheckTimeout;
	DCDNode Addr;
	
	struct Client{
		short id;
		int sock_fd;
		sockaddr addr;
		socklen_t addrlen;
	};
	DCDNodeT<Client> Clients;
	sockaddr_in ServAddr;
	struct{
		DCDNode ErrorStr;
		int ErrorNo;
		short Stage;
	}ErrorInfo;

public:

	DCInfo(){
		Alloc();
	}
	DCInfo(bool IsS){
		this->IsS=IsS;
		this->Isipv4=true;
		Alloc();
	}
	DCInfo(bool IsS,bool Isipv4){
		this->IsS=IsS;
		this->Isipv4=Isipv4;
		Alloc();
	}
	bool SetAddress(char*Addr){
		char**ptr;
		char   str[32];
		struct hostent *hptr;
		if((inet_pton(AF_INET,Addr,&ServAddr.sin_addr))>0){
			this->Addr=Addr;
			return true;
		}
		else{
			 if((hptr = gethostbyname(Addr)) == NULL){
				GetErrorInfo(0);
        			return false;
        		}
        		this->Addr=(char*)inet_ntop(hptr->h_addrtype, hptr->h_addr, str, sizeof(str));
        		return true;
		}
		return false;
	}
	void SetIsServer(bool IsS){
		this->IsS=IsS;
	}
	void SetIsipv4(bool Isipv4){
		this->Isipv4=Isipv4;	
	}
	void SetPort(short pn){
		this->ClientPort=pn;
	}
	bool SetNonBlock(){
		flags=fcntl(MSockFd,F_GETFL,0);
		if(flags<0){
			GetErrorInfo(1);
    			return false;      
		}
		fcntl(MSockFd,F_SETFL,flags|O_NONBLOCK);
		return true;
	}
	bool Init(){
		return (IsS==false?ClientInit():ServerInit());
	}
	
	void ClientSetFd(){
		FD_ZERO(&ClientCheck);
		FD_SET(MSockFd,&ClientCheck);
		
	}
	void ServerSetFd(){
		FD_ZERO(&ServerCheck);
		FD_SET(MSockFd,&ServerCheck);
		for(int i=0;i<Clients.GetLength();i++){
			FD_SET(Clients[i].sock_fd,&ServerCheck);
		}
	}
	DCDNodeT<Client> GetClients(){
		return Clients;
	}
	
	char* Recv(long Len,short id=0){
		free(RecvBuf);
		RecvBuf=(char*)malloc(sizeof(char)*Len);
		int ret;
		if(this->IsS==false){
			
			if((ret=recv(MSockFd,RecvBuf,Len,0))<0){
				GetErrorInfo();
				return NULL;
			}
			else{
				LRecvCount=ret;
				return RecvBuf;
			}
		}
		else{
			
			if((ret=recv(Clients[id].sock_fd,RecvBuf,Len,0))<0){
				GetErrorInfo();
				return NULL;
			}
			else{
				LRecvCount=ret;
				return RecvBuf;
			}
		}
	}
	bool Send(char*data,long len=0,short id=0){
		if(len==0)len=strlen(data)+1;
		if(IsS==false){
			if((send(MSockFd,(const char*)data,len,0))<0){
				GetErrorInfo();
				return false;
			}
			else{
				return true;
			}
		}
		else{
			if((send(Clients[id].sock_fd,(const char*)data,len,0))<0){
				GetErrorInfo();
				return false;
			}
			else{
				return true;
			}
		}
	}
	void CloseClient(short id){
		close(Clients[id].sock_fd);
		Clients.DelNode(id);
		ClientsCount--;
	}
	void CloseClients(){
		for(int i=0;i<Clients.GetLength();i++)
			close(Clients[i].sock_fd);
	}
	void CloseServer(){
		close(MSockFd);
	}
   	DCDNodeT<short> 
   	ServerCheckRead(){
   		ServerSetFd();
		int ret=select(Clients.GetLength()+1,&ServerCheck,NULL,NULL,&CheckTimeout);
		DCDNodeT<short> AbleList;
		if(ret<0){
			GetErrorInfo(3);
			return -1;
		}
		else if(ret==0){
			return ret;
		}
		for(short i=0;i<Clients.GetLength();i++){
			if(FD_ISSET(Clients[i].sock_fd,&ServerCheck))
			AbleList+=i;
		}
		return AbleList;
	}
   	bool ServerCheckAccept(){
   		FD_ZERO(&ServerCheck);
		FD_SET(MSockFd,&ServerCheck);
		int ret=select(Clients.GetLength()+1,&ServerCheck,NULL,NULL,&CheckTimeout);
		if(ret<0){
			GetErrorInfo(3);
			return false;
		}
		else if(ret==0){
			return false;
		}
   		if(FD_ISSET(MSockFd,&ServerCheck)){
   			return true;
   		}
   		return false;
   	}
   	bool ServerAccept(){
   		int i=ClientsCount;
   		Clients[i].sock_fd=accept(MSockFd,(struct sockaddr*)&(Clients[i].addr),&(Clients[i].addrlen));
   		if(Clients[i].sock_fd<=0){
   			GetErrorInfo();
   			Clients.DelNode(i);
   			ClientsCount--;
   			return false;
   		}
   		ClientsCount++;
   		return true;
   	}
	
	int ClientCheckRead(){
		ClientSetFd();
		int ret=select(MSockFd+1,&ClientCheck,NULL,NULL,&CheckTimeout);
		if(ret==-1){
			GetErrorInfo(3);
			return -1;
		}
		else if(ret==0){
			return ret;
		}
		if(FD_ISSET(MSockFd,&ClientCheck)){
			return 1;
		}
		return 2;
	}
	int ClientCheckWrite(){
		ClientSetFd();
		int ret=select(MSockFd+1,NULL,&ClientCheck,NULL,&CheckTimeout);
		if(ret==-1){
			GetErrorInfo(3);
			return -1;
		}
		else if(ret==0){
			return ret;
		}
		if(FD_ISSET(MSockFd,&ClientCheck)){
			return 1;
		}
		return 2;
	}
	void SetTimeout(long Sec,long USec=0){
		CheckTimeout.tv_sec=Sec;
		CheckTimeout.tv_usec=USec;
	}
	bool ServerInit(){
		if((MSockFd=socket(AF_INET,SOCK_STREAM,0))==-1){
			GetErrorInfo(1);
			return false;		
		}
		ServAddr.sin_family=AF_INET;
		ServAddr.sin_port=htons(ClientPort);
		ServAddr.sin_addr.s_addr=htonl(INADDR_ANY);
		return true;
	}
	bool ServerBind(){
		if(bind(MSockFd,(struct sockaddr*)&ServAddr,sizeof(ServAddr))==-1){  
			GetErrorInfo(2);	
			return false;		
		}
		return true;
	}
	bool ServerListen(int num=0){
		if(num==0)num=MAX_CLIENTS;
		if((listen(MSockFd,num))==-1){
			GetErrorInfo(2);
			return false;
		}
		return true;
	}
	bool ClientInit(){
		if((MSockFd=socket(AF_INET,SOCK_STREAM,0))<0){
			GetErrorInfo(1);
			return false;		
		}
		ServAddr.sin_family=AF_INET;
		ServAddr.sin_port=htons(ClientPort);
		if((inet_pton(AF_INET,Addr.ArrayShowc(),&ServAddr.sin_addr))<=0){
			GetErrorInfo(1);	
			return false;
		}
		return true;
	}
	bool ClientConn(){
		if((connect(MSockFd,(struct sockaddr*)&ServAddr,sizeof(struct sockaddr)))!=0){ 
			GetErrorInfo(2);	
			return false;
		} 
		return true;
	}
	void Alloc(){
		ClientPort=CLIENT_PORT;
		Addr.Settle();	
		IsError=false;
		ClientsCount=0;
		ErrorInfo.ErrorStr.Settle();
		memset(&ServAddr,0,sizeof(ServAddr));
		CheckTimeout.tv_sec=0;
		CheckTimeout.tv_usec=0;
		LRecvCount=0;
		RecvBuf=(char*)malloc(sizeof(char)*1);
	}
	void GetErrorInfo(short Stage=0){
		ErrorInfo.ErrorStr=strerror(errno);	
		ErrorInfo.ErrorNo=errno;
		ErrorInfo.Stage=Stage;
		IsError=true;
	}
	~DCInfo(){
		IsS==true?CloseClients():CloseServer();
	}
};
