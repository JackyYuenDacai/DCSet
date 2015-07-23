#include"DCNCode.h"
#include<stdio.h>
int main(){
	DCNCode a;
	a="Hello World";
	printf("%s\n",(char*)a.Data);

	a.Encrypt();
	a.Decrypt();
	printf("%s\n",(char*)a);
	return 0;
}
