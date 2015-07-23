#include"DCNSock.h"
#include<stdio.h>
#define ERROR(n)  	if(serv.IsError==true){\
 				printf("Error:%d MSG:%s ERRNO:%d!\n",n,(char*)serv.ErrorInfo.ErrorStr,serv.ErrorInfo.ErrorNo);\
 				return 0;\
 			}else\
 			{\
 				printf("Success:%d!\n",n);\
 			}
int main(){
	DCNSock serv;
 	serv.SetIsServer(true);
	serv.SetPort(1450);
 	serv.ServerInit();
 	serv.IsError=false;
 	serv.ServerBind();
 	ERROR(1)
 	serv.ServerListen();
 	ERROR(2)
 	while((serv.ServerCheckAccept())!=true);
 	ERROR(3)
 	printf("Detected A Request!\n");
 	serv.ServerAccept();
 	ERROR(4)
 	printf("Enter:Send\n");
 	getchar();
	serv.Send("Hello World\n");
	ERROR(5)
	while((serv.ServerCheckRead(0))!=true);
	ERROR(6)
	printf("Checked Read!\n");
	serv.Recv(1024);
	printf("Count of Recved Bytes:%d\n",serv.LastRecv.Length);
	for(int i=0;i<serv.LastRecv.Length;i++){
		printf("%02d\t",serv.LastRecv.Buf[i]);
		if(i%20==0&&i!=0)putchar('\n');
	}
	putchar('\n');
	int EnLen=*((int*)(serv.LastRecv.Buf+4));
	int CoLen=*((int*)serv.LastRecv.Buf);
	char TypeMsg=serv.LastRecv.Buf[8];
	
	printf("ENLen:%d CONLen:%d \nType Message:%d \nContent:%s\n",EnLen,CoLen,(int)TypeMsg,serv.LastRecv.Buf+524);
	serv.CloseClients();
	return 0;
}
