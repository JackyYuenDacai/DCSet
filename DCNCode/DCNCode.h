#include<DCSet/DCNNode.h>

#ifndef DCNCode_H
 #define DCNCode_H
#endif
unsigned char HexNo[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'U', 'V', 'W', 'X', 'Y', 'Z' };
class DCNCode
{
public:
	DCNStr Data;
	long long Length;
	void EBinary(){
		char*TurnStr=(char*)Data;
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
		Data.DelAll();
		for(int i=0,En=0;TurnStr[i]!=0;i+=9,En++){
			char Value=0;
			
			for(int EM=1,C=7;EM<9;EM++)
				(Value+=(TurnStr[EM+i]-'0')<<C),(C==0?C=0:C--);
			Data[En]=Value;
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
		EBinary();Data.ClearArrayLog();
		ENrziCode();Data.ClearArrayLog();
		EUpper();Data.ClearArrayLog();
		EFinal();Data.ClearArrayLog();
	}
	void Decrypt(){
		DFinal();Data.ClearArrayLog();
		DUpper();Data.ClearArrayLog();
		DNrziCode();Data.ClearArrayLog();
		DBinary();Data.ClearArrayLog();		
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

