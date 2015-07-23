#include"DCNSock.h"
#include<stdio.h>
#define ERROR(n)  	if(client.IsError==true){\
 				printf("Error:%d MSG:%s ERRNO:%d!\n",n,(char*)client.ErrorInfo.ErrorStr,client.ErrorInfo.ErrorNo);\
 				return 0;\
 			}else\
 			{\
 				printf("Success:%d!\n",n);\
 			}
int main(){
	DCNSock client;
 	client.SetIsServer(false);
 	client.SetAddress("localhost");
	client.SetPort(1450);
 	client.ClientInit();
 	ERROR(1)
 	client.ClientConn();
 	ERROR(2)
	
	while((client.ClientCheckRead())!=true);
	printf("Detected Readable! Enter:Read\n");
	getchar();
	client.Send("Hello World\n");
	ERROR(4)
	printf("Checked Read!\n");
	printf("Recv:%d %s\n",client.LRecvCount,client.Recv(50));
	client.CloseServer();
	return 0;
}
