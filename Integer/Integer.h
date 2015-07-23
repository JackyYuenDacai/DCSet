#include<DCSet/DCNNode.h>
typedef unsigned long long ullong;
class Integer
{
public:
	DCNStr Vector,Buffer;
	DCNStr Pitch;
	bool Init;
	int Base;
	char* ToCharStr()
	{
	   return  Vector.ToCharStr();
	}
	
	void Add(ullong value){
		ullong Enum=Vector.GetLength()-1;
	  	while(Enum>=0&&value!=0)
	  	{
	  		Vector[Enum]+=value%10;
			value/=10;
	   		Enum--;
	 	}
	  	while(value!=0)
	  	{
			Vector.PushTop()=value%10+'0';
			value/=10;
	  	}
	  	Enum=Vector.GetLength()-1;
	  	while(Enum>=1)
	  	(Vector[Enum]>'9'?(Vector[Enum-1]+=1,Vector[Enum]-=10):0),Enum--;
	  	Vector[0]>'9'?(Vector.PushTop()='1',Vector[1]-=10):0;     
	}
	void Add(Integer&value)
	{
	  ullong Enum=Vector.GetLength()-1;
	  ullong VEnum=value.Vector.GetLength()-1;
	  while(Enum>=0&&VEnum>=0)
	  {
	  	Vector[Enum]+=value.Vector[VEnum];
	   	Enum--;VEnum--;
	  }
	  while(VEnum>=0)
	  {
		Vector.PushTop()=(value.Vector[VEnum]);
		VEnum--;
	  }
	  Enum=Vector.GetLength()-1;
	  while(Enum>=1)
	  (Vector[Enum]>'9'?(Vector[Enum-1]+=1,Vector[Enum]-=10):0),Enum--;
	  Vector[0]>'9'?(Vector.PushTop()='1',Vector[1]-=10):0;     
	}/*
	A*B=C
	A=45,B=56;
	45
	56
	 
	30
       240
       250
      2000
      2520
	
*/
	void Times(ullong value){
		long long int Enum=Vector.GetLength()-2-value.Vector.GetLength();
		long long int VEnum=0;
	}
	void Times(Integer value)
	{
		long long int Enum=Vector.GetLength()-2-value.Vector.GetLength();
		long long int VEnum=0;
		Buffer=Vector;
		//Vector[Enum]='0'+
	}

	void Assign(unsigned int value)
	{
	   Vector.DelAll();
	   Vector[0]='0'+value%10;
	   value/=10;
	   while(value!=0)
	   	Vector.PushTop()=('0'+value%10),value/=10;
	}
	void operator =(unsigned int value)
	{
	   Assign(value);
	}
	void operator =(Integer value)
	{
	   //Vector.DelAll();
	   Vector=value.ToCharStr();
	}
	void operator +=(unsigned int value)
	{
	   Add(value);
	}
	void operator +=(int value)
	{
	   Add(value);
	}
	void operator +=(Integer value)
	{
	  Add(value);
	}
	void FreeOut()
	{
	   Vector.ClearArrayLog();
	}
	Integer(unsigned int value)
	{
	   if(Init==false)return;
	   Vector.Settle();
	   Vector[0]='0'+value%10;
	   value/=10;
	   while(value!=0)
	   Vector.PushTop()='0'+value%10,
	   value/=10;
	   Init=true;
	}
	Integer(unsigned long value)
	{
	   if(Init==false)return;
	   Vector.Settle();
	   Vector[0]='0'+value%10;
	   value/=10;
	   while(value!=0)
	   Vector.PushTop()='0'+value%10,
	   value/=10;
	   Init=true;
	}
	Integer()
	{
	   if(Init==false)return;
	   Vector.Settle();
	   Vector[0]='0';
	   Init=true;
	}
	Integer(ullong value)
	{
	   if(Init==false)return;
	   Vector.Settle();
	   Vector[0]='0'+value%10;
	   value/=10;
	   while(value!=0)
	   Vector.PushTop()=('0'+value%10),
	   value/=10;
	   Init=true;
	}
};
