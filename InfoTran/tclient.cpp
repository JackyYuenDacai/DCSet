#include"DCInfoT.h"
#include<stdio.h>
 			
int main(){
 DCInfo conn[35];
 int i=0;
 char*Test="GET http://www.bmkc.edu.hk/ HTTP/1.0\r\nHost:www.bmkc.edu.hk\r\nUser-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN; rv:1.9.2.3) Gecko/20100401 Firefox/3.6.3\r\nConnection:keep-alive\r\n\r\n";
 for(i=0;i<20;i++){
 conn[i].SetAddress("www.bmkc.edu.hk");
 conn[i].SetIsServer(false);

 conn[i].SetPort(80);
 conn[i].ClientInit();}
for(i=0;i<20;i++){
 conn[i].ClientConn();
 if(conn[i].IsError==true)
 	printf("E%d ",i);
 else
 	printf("S%d ",i);
 }
 for(int e=0;e<1000;e){
 for(i=0;i<20;i++){
 	conn[i].Send((char*)Test,strlen(Test));
 }
 }
 putchar('\n');
 return 0;
}
