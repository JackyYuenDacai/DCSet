#include"DCNNode.h"
#include<stdio.h>
#ifndef DCNCode_H
 #define DCNCode_H
#endif
unsigned char HexNo[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'U', 'V', 'W', 'X', 'Y', 'Z' };
class DCNCode
{	
	DCNStr Data;
	long long Length;
	long long encrypt_key = 0;
	long long decrypt_key = 0;
public:

#define PUSH_KEYA(a,b,c,d) encrypt_key = a & 0xFF << 24 +  b & 0xFF << 16 + c & 0xFF << 8 + d & 0xFF 
#define PUSH_KEYB(a,b,c,d) encrypt_key = a & 0xFF << 56 +  b & 0xFF << 48 + c & 0xFF << 40 + d & 0xFF <<32

#define GET_KEYAA ((encrypt_key & 0xFF << 24) >> 24)
#define GET_KEYAB ((encrypt_key & 0xFF << 16) >> 16)
#define GET_KEYAC ((encrypt_key & 0xFF << 8) >> 8)
#define GET_KEYAD (encrypt_key & 0xFF )

#define GET_MOD(a) (a<0?128*(-a/128+1)+a:((int)a)%256)

	void SetEncryptKey(long long key){
		encrypt_key=key;
	}
	void EKeyEmb(){
		float det_a=GET_KEYAA*GET_KEYAD-GET_KEYAB*GET_KEYAC;
		if(det_a != 1) return;
		unsigned char*TurnStr=(unsigned char*)(char*)Data; 
		int a,b,c,d;
		Length=Data.GetLength();
		Data.Insert(0,8);
		//Data[0]=((unsigned char*)&Length)[0];
		//Data[1]=((unsigned char*)&Length)[1];
		//Data[2]=((unsigned char*)&Length)[2];
		//Data[3]=((unsigned char*)&Length)[3];
		//Data[Data.GetLength() - Data.GetLength()%4 + 8 - 1]='\0';
		TurnStr=(unsigned char*)(char*)Data;
		*((long long int *)TurnStr)=(unsigned long long int)Length;
		Data.DelAll();
		Length+=8;
		// 0 1  4 5    0*4+1*6    0*5+1*7
		// 2 3  6 7    2*4+3*6    2*5+3*7
		for(long long int i=0;i<Length;i+=4){
			a = TurnStr[i + 0];b = TurnStr[i + 1];c = TurnStr[i + 2];d =TurnStr[i + 3];
			TurnStr[i + 0]=GET_MOD( a * GET_KEYAA +  b * GET_KEYAC );
			TurnStr[i + 1]=GET_MOD( a * GET_KEYAB +  b * GET_KEYAD );
			TurnStr[i + 2]=GET_MOD( c * GET_KEYAA +  d * GET_KEYAC );
			TurnStr[i + 3]=GET_MOD( c * GET_KEYAB +  d * GET_KEYAD );
		}
		Data.AddString((char*)TurnStr,Length);
	}
	void DKeyEmb(){				
		float det_a=GET_KEYAA*GET_KEYAD-GET_KEYAB*GET_KEYAC;
		if(det_a != 1) return;
		unsigned char*TurnStr=(unsigned char*)(char*)Data; 

		float 	inv_a=	GET_KEYAD/det_a,
				inv_b=-	GET_KEYAB/det_a,
				inv_c=-	GET_KEYAC/det_a,
				inv_d=	GET_KEYAA/det_a;
		long long int original_length =0;
		int a,b,c,d;
		Length=Data.GetLength();
		//printf("Length : %d \n",Length);
		Data.DelAll();
		for(long long int i=0;i<Length;i+=4){
			a = TurnStr[i + 0];b = TurnStr[i + 1];c = TurnStr[i + 2];d =TurnStr[i + 3];
			TurnStr[i + 0]=GET_MOD((int)( a * inv_a +  b * inv_c ));
			TurnStr[i + 1]=GET_MOD((int)( a * inv_b +  b * inv_d ));
			TurnStr[i + 2]=GET_MOD((int)( c * inv_a +  d * inv_c ));
			TurnStr[i + 3]=GET_MOD((int)( c * inv_b +  d * inv_d ));
		}
		original_length = *((long long int*)TurnStr);//printf("Length : %d \n",original_length);	
		//for(int i=0;i<original_length;i++)
		//	 printf("%d ",(char*)(TurnStr+8)[i]);	printf("\n");
		//original_length = 10;
		Data.AddString((char*)(TurnStr+8),original_length);
	}
	void EBinary(){
		unsigned char*TurnStr=(unsigned char*)(char*)Data;
		Length=Data.GetLength();
		Data.DelAll();
		for(long long int i=0,En=8;i<Length;i++,En+=18)
			for(long long int Euem=En,Value=TurnStr[i];En>=Euem-8;En--)
			{
				Data[En]=Value%2+'0';
				Value/=2;
			}	
	}
	void ENrziCode(){
		char*TurnStr=(char*)Data;
		Length=Data.GetLength();
		Data.DelAll();
		short Rev=1;
		for(long long int i=0;i<Length;i++)
			TurnStr[i]=='0'?(Rev=!Rev,Data[i]=Rev+'0'):Data[i]=Rev+'0';
	}
	void EUpper()
	{
		char*TurnStr=(char*)Data;
		Length=Data.GetLength();
		Data.DelAll();
		for(long long int i=0,En=0,Same=0;i<Length;i++)
		{
			if(TurnStr[i]==TurnStr[i+1])
			{
				Same++;
				continue;
			}
			else
			{				
				Data[En]=(unsigned char)Same+'A';
				En++;Same=0;
			}
		}
	}
	void EFinal()
	{
		char*TurnStr=(char*)Data;
		Length=Data.GetLength();
	   	Data.DelAll();
	   	for(long long int i=0,En=0,Same=0;i<Length;i++)
           	if(TurnStr[i]==TurnStr[i+1])
		   {
			   Same++;
			   continue;
		   }
		   else
		   {				
			   Data[En]=Same==0?(TurnStr[i]-'A'+'a'):TurnStr[i];
			   if(Same>1)
				  Data[++En]=HexNo[Same];
			   En++;Same=0;
		   }
	}
	void DBinary()
	{	
		char*TurnStr=(char*)Data;
		Length = 0;
		long long int data_length = Data.GetLength();
		Data.DelAll();
		for(int i=0,En=0;Length<data_length;i+=9,En++){
			char Value=0;
			for(int EM=1,C=7;EM<9;EM++)
				(Value+=(TurnStr[EM+i]-'0')<<C),(C==0?C=0:C--);
			Data[En]=Value;
			Length += 1;
		}
		/*short*TurnStr=Data.ToShortInt();
		Data.DelAll();
		for(int i=0,En=0,Value=0;TurnStr[i]!=0;i+=9,En++)
		{
			Data[En]=0;
			Value=0;
			for(int EM=1,C=7;EM<9;EM++)
				(Data[En]+=(TurnStr[EM+i]-'0')<<C),(C==0?C=0:C--);
		}*/		
		/*
		short*TurnStr=Data.ArrayShows();
		Data.DelAll();
		Data[0]=0;
		for(int EM=1,C=7;EM<9;EM++)
			(Data[0]+=(TurnStr[EM+0]-'0')<<C),(C==0?C=0:C--);
		for(int i=8,En=1;TurnStr[i]!=0;i+=8,En++)
		{
			Data[En]=0;
			for(int EM=0,C=6;EM<8;EM++)
				(Data[En]+=(TurnStr[EM+i]-'0')<<C),(C==0?C=0:C--);
		}
		*/
	}
	void DNrziCode()
	{
		char *TurnStr=(char*)Data;
		Data.DelAll();
		for(long long int i=0,En=0,Same=0;TurnStr[i]!=0;i++)
		{
			if(TurnStr[i]==TurnStr[i+1])
			{
				Same++;
				continue;
			}
			else
			{				
				Data[En]='0',
				En++;
				for(long long int Sem=0;Sem<Same;Sem++)
					Data[En]='1',++En;
				Same=0;
			}
		}		
	}
	void DUpper()
	{
		int Bin=0;
		char*TurnStr=(char*)Data;
		Data.DelAll();
		for(long long int i=0,Count=0,En=0;TurnStr[i]!=0;i++)
		{
			Count=TurnStr[i]-'A'+1;
			for(short Enum=0;Enum<Count;Enum++,En++)
			 Data[En]=Bin+'0';
			Bin==0?Bin=1:Bin=0;
		}
	}
	void DFinal()
	{
		char*TurnStr=(char*)Data;
		Data.DelAll();
		for(int i=0,En=0,Count=0,Value;TurnStr[i]!=0;i++)
		{
			Value=TurnStr[i];
			Count=1;
			if(TurnStr[i]<='Z')
			{
				Count=2;
				if( (TurnStr[i + 1] >= '0'&&TurnStr[i + 1] <= '9') || 
					(TurnStr[i + 1] >= 'U'&&TurnStr[i + 1] <= 'Z'))
				  Count=(TurnStr[i+1]>='U'?TurnStr[i+1]-'U'+10:TurnStr[i+1]-'0')+1,i++;
			}
			for(int Enum=0;Enum<Count;Enum++,En++)
            	Data[En]=(Value>='a'?Value-'a'+'A':Value);
		}
	}
	void Encrypt(){
		EBinary();	Data.ClearArrayLog();
		ENrziCode();Data.ClearArrayLog();
		EUpper();	Data.ClearArrayLog();
		EFinal();	Data.ClearArrayLog();
		EKeyEmb();Data.ClearArrayLog();
	}
	void Decrypt(){
		DKeyEmb();Data.ClearArrayLog();
		DFinal();	Data.ClearArrayLog();
		DUpper();	Data.ClearArrayLog();
		DNrziCode();Data.ClearArrayLog();
		DBinary();	Data.ClearArrayLog();		
	}
	void AddString(char*data,long long len){
		Data.AddString(data,len);
	}
	void operator=(char*array){
		Data=array;
	}
 
	void operator=(const char*array){
		Data=array;
	}
	unsigned char& operator [](long long index){
		return (Data.NodeSet(index)->c);
	}
	unsigned char& operator [](long index){
		return (Data.NodeSet(index)->c);
	}	
	unsigned char& operator [](int index){
		return (Data.NodeSet(index)->c);
	}
	unsigned char& operator [](short index){
		return (Data.NodeSet(index)->c);
	}
	long long GetLength(){
		return Data.GetLength();
	}
	operator char*(){
		return (char*)Data;
	}
	DCNStr& operator=(DCNStr& dcnode){
		Data=dcnode;
		return Data;
	}
};
