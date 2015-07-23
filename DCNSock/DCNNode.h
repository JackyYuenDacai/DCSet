#include<stdlib.h>
#include<string.h>
#ifndef DCNode_H

#define DCNode_H
#define abs(value) (value<0?-value:value)

typedef unsigned char byte ;
class DCNStr
{
  	struct NodeLink
  	{
	  	unsigned char c;
		NodeLink*next,*unext;
	};
	NodeLink*head,*nail;
	NodeLink*pointer;
	struct TurnLog
	{
		void*Addr;
		TurnLog*next;
	};
	TurnLog*LogHead,*LogNow;
	long long pointNum;
	long long NodeCount;
public:
	void Alloc(){
		head=(NodeLink*)malloc(sizeof(NodeLink));
		nail=head;
		head->unext=NULL;
		NodeCount=0;
		pointer=nail;
		pointNum=-1;
		LogHead=(TurnLog*)malloc(sizeof(TurnLog));
		LogNow=LogHead;LogNow->Addr=0;
	}
	DCNStr(long long len){
		Alloc();
		AddNode(len);
	}
	DCNStr(){
		Alloc();
	}
	void Settle(long long int Length=0)
	{
                if(head!=NULL)return;
		Alloc();
		AddNode(Length);
	}
	void AddNode(long long NCount){
		for(;NCount>0;NCount--){
			NodeCount++;
			nail->next=(NodeLink*)malloc(sizeof(NodeLink));
                        (nail->next)->unext=nail;
                        nail=nail->next;
		}
	}
	void AddArrayLog(void*Addr){
		LogNow->Addr=Addr;
		LogNow->next=(TurnLog*)malloc(sizeof(TurnLog));
		LogNow=LogNow->next;LogNow->Addr=0;
	}
	void ClearArrayLog(){
		TurnLog*Enum;
		LogNow=LogHead;
		if(LogHead->Addr==0)
			return;
		free(LogHead->Addr),LogNow=LogHead->next;
		while(LogNow->Addr!=0)
		{
			free(LogNow->Addr);
                        Enum=LogNow;
			LogNow=LogNow->next;
                        free(Enum);
		}
		free(LogNow);
		LogNow=LogHead,LogNow->Addr=0;
	}
	NodeLink* NodeSet(long long index){
	
		if(index<0)return NULL;
		if((index+1)>NodeCount)
       		return (AddNode((index+1)-NodeCount),nail);
       		if(abs(NodeCount/2-index)<abs(index-pointNum)){
       			NodeLink*retNode;
       			switch(int(index>=(NodeCount/2)))
			{
			case 0:
				retNode=head->next;
				for(long long i=0;i<index;i++)
				retNode=retNode->next;
				pointNum=index;
				pointer=retNode;
				return retNode;
		 	case 1:
				retNode=nail;
				for(long long i=0;i<(NodeCount-index-1);i++)
					retNode=retNode->unext;
				pointNum=index;
				pointer=retNode;
				return retNode;
			}
       		}
       		else{
       			switch(int(index>=pointNum)){
       			case 0:
       				for(long long i=0;i<=pointNum-index;i++)
       				pointer=pointer->unext,pointNum--;
       				return pointer;
       			case 1:
       				for(long long i=0;i<=index-pointNum;i++)
       				pointer=pointer->next,pointNum++;
       				return pointer;
       			}
       			
       		}
       		return NULL;
	}
	void DelNode(long long index){
		if(index>=NodeCount||index<0)
		return;
		if(index==NodeCount-1)
		{
			nail=(nail->unext);free(nail->next);
			nail->next=NULL;NodeCount--;
			return;
		}
		NodeLink*DelN=NodeSet(index);
		DelN->unext->next=DelN->next;
		DelN->next->unext=DelN->unext;
		free(DelN);
		NodeCount--;
	}
	void DelAll(){
		for(long long i=0;i<NodeCount;i++)
			nail=nail->unext,
			free(nail->next);
		NodeCount=0;
		head=nail;head->next=nail;nail->unext=head;
	}
	char*ToCharStr(){
		NodeLink*save=head->next;
        	char*retArray=(char*)malloc(size_t(sizeof(char)*(NodeCount+1)));
       		for(long long i=0;i<NodeCount;i++)
			retArray[i]=char(save->c),
			save=save->next;
		retArray[NodeCount]='\0';
		AddArrayLog(retArray);
		return retArray;
	}
	operator char*(){
		return ToCharStr();
	}
	operator const char*(){
		return (const char*)ToCharStr();
	}
	long long GetLength(){
		return NodeCount;
	}
	void AddString(char*Str,int length){
		NodeLink*save=nail;
		AddNode(length);save=save->next;
		for(long long i=0;i<length;i++)
		{
			save->c=Str[i];
			save=save->next;
		}
	}
	unsigned char& operator [](long long index){
		return (NodeSet(index)->c);
	}
	unsigned char& operator [](long index){
		return (NodeSet(index)->c);
	}	
	unsigned char& operator [](int index){
		return (NodeSet(index)->c);
	}
	unsigned char& operator [](short index){
		return (NodeSet(index)->c);
	}
	void operator =(char* Str){
		this->DelAll();
		this->AddString(Str,strlen(Str));
	}
	void operator =(const char* Str){
		this->DelAll();
		this->AddString((char*)Str,strlen((char*)Str));
	}
	void operator +=(char Lett){
		NodeSet(NodeCount+1)->c=Lett;
	}
	void operator +=(char* Str){
		AddString(Str,strlen(Str));
	}
	void operator +=(const char* Str){
		AddString((char*)Str,strlen((char*)Str));
	}
	void operator=(DCNStr&dcnode){
		DelAll();
		AddString(dcnode.ToCharStr(),dcnode.GetLength());
	}
	
	~DCNStr(){
		DelAll();
		ClearArrayLog();
		free(LogHead);
		free(head);
	}
};
template <class ANType>
class DCNode{
  	struct NodeLink
  	{
	  	void* data;
		NodeLink*next,*unext;
	};
	NodeLink*head,*nail;
	NodeLink*pointer;
	struct TurnLog
	{
		void*Addr;
		TurnLog*next;
	};
	TurnLog*LogHead,*LogNow;
	long long pointNum;
	long long NodeCount;
	size_t IndivSize;
	bool Mutex;
public:
	void Alloc(){
		head=(NodeLink*)malloc(sizeof(NodeLink));
		nail=head;
		IndivSize=sizeof(ANType);
		head->data=malloc(IndivSize);
		head->unext=NULL;
		NodeCount=0;
		pointer=nail;
		pointNum=-1;
		Mutex=false;
		LogHead=(TurnLog*)malloc(sizeof(TurnLog));
		LogNow=LogHead;LogNow->Addr=0;
	}
	DCNode(long long len){
		Alloc();
		AddNode(len);
	}
	DCNode(){
		Alloc();
	}
	void Settle(long long int Length=0)
	{
                if(head!=NULL)return;
		Alloc();
		AddNode(Length);
	}
	void AddNode(long long NCount){
		for(;NCount>0;NCount--){
			NodeCount++;
			nail->next=(NodeLink*)malloc(sizeof(NodeLink));
			nail->next->data=(void*)malloc(IndivSize);
                        (nail->next)->unext=nail;
                        nail=nail->next;
		}
	}
	void AddArrayLog(void*Addr){
		LogNow->Addr=Addr;
		LogNow->next=(TurnLog*)malloc(sizeof(TurnLog));
		LogNow=LogNow->next;LogNow->Addr=0;
	}
	void ClearArrayLog(){
		TurnLog*Enum;
		LogNow=LogHead;
		if(LogHead->Addr==0)
			return;
		free(LogHead->Addr),LogNow=LogHead->next;
		while(LogNow->Addr!=0)
		{
			free(LogNow->Addr);
                        Enum=LogNow;
			LogNow=LogNow->next;
                        free(Enum);
		}
		free(LogNow);
		LogNow=LogHead,LogNow->Addr=0;
	}
	NodeLink* NodeSet(long long index){
		while(Mutex==true);
		Mutex=true;
		if(index<0){
			Mutex=false;
			return NULL;
		}
		if((index+1)>NodeCount){
		Mutex=false;
       		return (AddNode((index+1)-NodeCount),nail);
       		}
       		if(abs(NodeCount/2-index)<abs(index-pointNum)){
       			NodeLink*retNode;
       			switch(int(index>=(NodeCount/2)))
			{
			case 0:
				retNode=head->next;
				for(long long i=0;i<index;i++)
				retNode=retNode->next;
				pointNum=index;
				pointer=retNode;
				Mutex=false;
				return retNode;
		 	case 1:
				retNode=nail;
				for(long long i=0;i<(NodeCount-index-1);i++)
					retNode=retNode->unext;
				pointNum=index;
				pointer=retNode;
				Mutex=false;
				return retNode;
			}
       		}
       		else{
       			switch(int(index>=pointNum)){
       			case 0:
       				for(long long i=0;i<=pointNum-index;i++)
       				pointer=pointer->unext,pointNum--;
       				Mutex=false;
       				return pointer;
       			case 1:
       				for(long long i=0;i<=index-pointNum;i++)
       				pointer=pointer->next,pointNum++;
       				Mutex=false;
       				return pointer;
       			}
       			
       		}
       		return NULL;
	}
	void DelNode(long long index){
		if(index>=NodeCount||index<0)
		return;
		if(index==NodeCount-1)
		{
			nail=(nail->unext);free(nail->next);
			nail->next=NULL;NodeCount--;
			return;
		}
		NodeLink*DelN=NodeSet(index);
		DelN->unext->next=DelN->next;
		DelN->next->unext=DelN->unext;
		free(DelN->data);
		free(DelN);
		NodeCount--;
	}
	void DelAll(){
		for(long long i=0;i<NodeCount;i++)
			nail=nail->unext,
			free(nail->next->data),
			free(nail->next);
		NodeCount=0;
		head=nail;head->next=nail;nail->unext=head;
	}
	ANType*ToAnyType(){
		NodeLink*save=head->next;
        	ANType*retArray=(ANType*)malloc(size_t(IndivSize*(NodeCount)));
       		for(long long i=0;i<NodeCount;i++)
			retArray[i]=*(ANType*)(save->data),
			save=save->next;
		AddArrayLog(retArray);
		return retArray;
	}
	operator ANType*(){
		return ToAnyType();
	}
	operator const ANType*(){
		return (const ANType*)ToAnyType();
	}
	long long GetLength(){
		return NodeCount;
	}
	void AddArray(ANType*Array,int length){
		NodeLink*save=nail;
		AddNode(length);save=save->next;
		for(long long i=0;i<length;i++)
		{
			save->data=Array[i];
			save=save->next;
		}
	}
	ANType& operator [](long long index){
		return *(ANType*)(NodeSet(index)->data);
	}
	ANType& operator [](long index){
		return *(ANType*)(NodeSet(index)->data);
	}	
	ANType& operator [](int index){
		return *(ANType*)(NodeSet(index)->data);
	}
	ANType& operator [](short index){
		return *(ANType*)(NodeSet(index)->data);
	}
	void operator +=(ANType Lett){
		*((ANType*)(NodeSet(NodeCount+1)->data))=Lett;
	}
	void operator=(DCNode&dcnode){
		DelAll();
		AddArray(dcnode.ToAnyType(),dcnode.GetLength());
	}
	
	~DCNode(){
		DelAll();
		ClearArrayLog();
		free(LogHead);
		free(head);
	}
};

#endif
