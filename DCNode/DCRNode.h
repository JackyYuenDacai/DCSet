#include<stdlib.h>
template <class Type>
class DCNode{
  	struct NodeLink
  	{
	  	void* data;
		NodeLink*next,*unext;
	};
	NodeLink*head,*nail;
	struct TurnLog
	{
		void*Addr;
		TurnLog*next;
	};
	TurnLog*LogHead,*LogNow;
	long long NodeCount;
	size_t IndivSize;
	bool Mutex;
public:
	void Alloc(){
		head=(NodeLink*)malloc(sizeof(NodeLink));
		nail=head;
		IndivSize=sizeof(Type);
		head->data=malloc(IndivSize);
		head->unext=NULL;
		NodeCount=0;
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
	void PushTop(){
		NodeCount++;
		head->unext=(NodeLink*)malloc(sizeof(NodeLink));
		head->unext->next=head;
		head=head->unext;
		(head->next)->data=(void*)new Type;
	}
	void AddNode(long long NCount){
		for(;NCount>0;NCount--){
			NodeCount++;
			nail->next=(NodeLink*)malloc(sizeof(NodeLink));
			nail->next->data=(void*)new Type;
                        (nail->next)->unext=nail;
                        nail=nail->next;
		}
	}
	Type& New(){
		AddNode(1);
		return *(Type*)(nail->data);
	}
	Type& Last(){
		return *(Type*)(nail->data);
	}
	Type& Top(){
		return *(Type*)(head->next->data);
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
		NodeLink*retNode=NULL;
		while(Mutex==true);
		Mutex=true;
		if(index+1>NodeCount)
			return (AddNode((index+1)-NodeCount),nail);
			
		switch(index>NodeCount/2){
			case false:
				retNode=head;
				for(long long i=0;i<index+1;i++)
					retNode=retNode->next;
				break;
			case true:
				retNode=nail;
				for(long long int i=0;i<NodeCount-index-1;i++)
					retNode=retNode->unext;
				break;
		}
		Mutex=false;
		return retNode;
	}
	void Insert(long long index,long long count=1){
		NodeLink*linkbuf=NodeSet(index)->unext;
		NodeLink*linkto=linkbuf->next;
		for(;count>0;count--){
			NodeCount++;
			linkbuf->next=(NodeLink*)malloc(sizeof(NodeLink));
			linkbuf->next->data=(void*)new Type;
                        linkbuf->next->unext=linkbuf;
                        linkbuf=linkbuf->next;
		}
		linkto->unext=linkbuf;
		linkbuf->next=linkto;
	}
	void Swap(long long a,long long b){
		NodeLink*FLink=NodeSet(a);
		NodeLink*SLink=NodeSet(b);
		void*data=FLink->data;
		FLink->data=SLink->data;
		SLink->data=data;
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
		delete DelN->data;
		free(DelN);
		NodeCount--;
	}
	void DelAll(){
		for(long long i=0;i<NodeCount;i++){
			nail=nail->unext;
			delete (Type*)nail->next->data;
			free(nail->next);
		}
		NodeCount=0;
		head=nail;head->next=nail;
		nail->unext=head;
	}
	Type*ToAnyType(){
		NodeLink*save=head->next;
        	Type*retArray=(Type*)malloc(size_t(IndivSize*(NodeCount)));
       		for(long long i=0;i<NodeCount;i++)
			retArray[i]=*(Type*)(save->data),
			save=save->next;
		AddArrayLog(retArray);
		return retArray;
	}
	operator Type*(){
		return ToAnyType();
	}
	operator const Type*(){
		return (const Type*)ToAnyType();
	}
	long long GetLength(){
		return NodeCount;
	}
	void AddArray(Type*Array,int length){
		NodeLink*save=nail;
		AddNode(length);
		save=save->next;
		for(long long i=0;i<length;i++)
		{
			save->data=(void*)Array[i];
			save=save->next;
		}
	}
	Type& operator [](long long index){
		return *(Type*)NodeSet(index)->data;
	}
	Type& operator [](long index){
		return *(Type*)NodeSet((long long)index)->data;
	}	
	Type& operator [](int index){
		return *(Type*)NodeSet((long long)index)->data;
	}
	//Type& operator [](short index){
	//	return *(Type*)(NodeSet(index)->data);
	//}
	void operator +=(Type Lett){
		*((Type*)(NodeSet(NodeCount+1)->data))=Lett;
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
