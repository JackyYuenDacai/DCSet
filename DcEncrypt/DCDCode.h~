#include"DCDNode.h"

#ifndef DCDCODE_H
 #define DCDCODE_H
#endif
unsigned char HexNo[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'U', 'V', 'W', 'X', 'Y', 'Z' };
class DCDCode
{
	DCDNode Data;
	void EBinary()
	{
		
		short*TurnStr=Data.ArrayShows();
		Data.DelAll();
		for(long long int i=0,En=8;TurnStr[i]!=0;i++,En+=18)
		 for(long long int Euem=En,Value=TurnStr[i];En>=Euem-8;En--)
		 {
			 Data[En]=Value%2+'0';
			 Value/=2;
		 }	 
		/*short*TurnStr=Data.ArrayShows();
		Data.DelAll();
		for(int En=8,Value=TurnStr[0];En>-1;En--)
			Data[En]=Value%2+'0',
			Value/=2;
		for(int i=1,En=17;TurnStr[i]!=0;i++,En+=16)
		 for(int Euem=En,Value=TurnStr[i];En>=Euem-7;En--)
		 {
			 Data[En]=Value%2+'0';
			 Value/=2;
		 }		
		 */
	}
	void ENrziCode()
	{
		char*TurnStr=Data.ArrayShowc();
		Data.DelAll();
		short Rev=1;
		for(long long int i=0;TurnStr[i]!=0;i++)
			TurnStr[i]=='0'?(Rev=!Rev,Data[i]=Rev+'0'):Data[i]=Rev+'0';
	}
	void EUpper()
	{
		char*TurnStr=Data.ArrayShowc();
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
				Data[En]=(unsigned char)Same+'A';
				En++;Same=0;
			}
		}
	}
	void EFinal()
	{
       char*TurnStr=Data.ArrayShowc();
	   Data.DelAll();
	   for(long long int i=0,En=0,Same=0;TurnStr[i]!=0;i++)
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
		short*TurnStr=Data.ArrayShows();
		Data.DelAll();
		for(int i=0,En=0,Value=0;TurnStr[i]!=0;i+=9,En++)
		{
			Data[En]=0;
			Value=0;
			for(int EM=1,C=7;EM<9;EM++)
				(Data[En]+=(TurnStr[EM+i]-'0')<<C),(C==0?C=0:C--);
		}		
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
		char *TurnStr=Data.ArrayShowc();
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
		char*TurnStr=Data.ArrayShowc();
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
		char*TurnStr=Data.ArrayShowc();
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
	public:		
	void Settle()
	{
		Data.Settle();
	}
	void Fresh()
	{
		Data.DelAll();
		Data.ClearArray();
	}
	void EncryptStr(char*Str)
	{
		Data.DelAll();
		Data=Str;
	}
	DCDCode()
	{
		Settle();
	}
	DCDCode(char*String)
	{
		Settle();
		Data=String;
	}
	DCDCode(long long Count)
	{
		Settle();
		Data=Count;
	}
	DCDCode(char Letter)
	{
		Settle();
		Data=Letter;
	}
	void Encrypt()
	{
        EBinary();
		ENrziCode();
		Data.ClearArray();
		EUpper();
		EFinal();
		Data.ClearArray();
	}
	void Decipher()
	{
		DFinal();
		DUpper();
		DNrziCode();
		Data.ClearArray();
		DBinary();	
		Data.ClearArray();
	}
	char* ArrayShowc()
	{
		return Data.ArrayShowc();
	}
	char* ArrayUse()
	{
		return (char*)Data.ArrayUse();
	}
	long long int GetLength()
	{
		return Data.GetLength();
	}
	void operator=(char*String)
	{
		Data=String;
	}
};

char*Encode(char*str);

char*Decode(char*str);

