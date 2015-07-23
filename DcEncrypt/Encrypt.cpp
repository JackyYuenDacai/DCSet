#include"DCDCode.h"
#include<stdio.h>
char*Encode(char*str)
{
	DCDCode dcode;
	dcode=str;
	dcode.Encrypt();
	return dcode.ArrayShowc();
}
char*Decode(char*str)
{
	DCDCode dcode;
	dcode=str;
	dcode.Decipher();
	return dcode.ArrayShowc();
}
int main(int argc,char**argv)
{
	char*HelpPage="\n\t\t**DCDCode Encrypt** \n\t\tv.2.0.0 By JY Dacai\n\tSyntax:encrypt <e|d|h> <arg>;\n\n\t\te:Encrypt <arg> To DCDCode \n\t\td:Decode <arg> to Original String.\n\t\th:Print this Help Page.\n\nCopyright 2014(C)Jacky Yuen.\n";
	printf("\n");
	for(int i=0;i<argc;i++)
	printf("%s\t",argv[i]);
	printf("\n");
	if(argc>3)return 0;
	if(argc==1){
		printf("%s",HelpPage);
		return 0;
	}
	//if(strlen(argv[1])>1)return 0;
	switch(argv[1][0])
	{
		case 'e':
	printf("eee");
		printf("%s\n",Encode(argv[2]));
		break;
		case 'd':
		printf("%s\n",Decode(argv[2]));
		break;
		case 'h':
		printf("%s",HelpPage);
		break;
		default:
		printf("%s",HelpPage);
		break;
	}
	return 0;
}
