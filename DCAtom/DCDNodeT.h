#include<stdlib.h>
#include<string.h>

#ifndef DCDNODE_H
 #define DCDNODE_H
#endif

char Copyright[]="Copyright 2014@JackyYuenDacai";
template <class t>
class DCDNode
{
  struct NodeLink
  {
	  void*data;
	  NodeLink*next,*unext;
  };
  struct TurnLog
  {
	  void*Addr;
	  TurnLog*next;
  };
  NodeLink*head,*nail;
  TurnLog*LogHead,*LogNow;
  long long int NodeCount;
  size_t SinLength;
public:
	DCDNode(long long int Length=1)
	{
                SinLength=sizeof(t);
		head=(NodeLink*)malloc(sizeof(NodeLink));
                head->data=malloc(SinLength);
		nail=head;nail->unext=head;
		head->next=nail;NodeCount=Length;
		for( long long int i=0;i<(Length-1);i++)
		{
			nail->next=(NodeLink*)malloc(sizeof(NodeLink));
			(nail->next)->unext=nail;nail=nail->next;
			nail->data=malloc(SinLength);
                }
		LogHead=(TurnLog*)malloc(sizeof(TurnLog));
		LogNow=LogHead;LogNow->Addr=0;
	}
        void Settle(long long int Length=1)
	{
                if(head!=NULL)return;
		SinLength=sizeof(t);
		head=(NodeLink*)malloc(sizeof(NodeLink));
                head->data=malloc(SinLength);
		nail=head;nail->unext=head;
		head->next=nail;NodeCount=Length;
		for( long long int i=0;i<(Length-1);i++)
		{
			nail->next=(NodeLink*)malloc(sizeof(NodeLink));
			(nail->next)->unext=nail;nail=nail->next;
			nail->data=malloc(SinLength);
                }
		LogHead=(TurnLog*)malloc(sizeof(TurnLog));
		LogNow=LogHead;LogNow->Addr=0;
	}
        void AddNode(long long int count)
	{
		for( long long int i=0;i<count;i++)
	        {
			nail->next=(NodeLink*)malloc(sizeof(NodeLink));
			(nail->next)->unext=nail;nail=nail->next;
			nail->data=malloc(SinLength);
              		NodeCount++;
          	}
	}
	t* NodeSet(long long int count)
	{
          NodeLink*retNode;
		  if((count+1)>NodeCount)
            return (AddNode((count+1)-NodeCount),(t*)nail->data);
		  switch(int(count>=(NodeCount/2)))
		  {
			case 0:
				retNode=head;
				for(long long int i=0;i<count;i++)
				retNode=retNode->next;
				return (t*)(retNode->data);
		    case 1:
				retNode=nail;
				for(long long int i=0;i<(NodeCount-count-1);i++)
					retNode=retNode->unext;
				return (t*)(retNode->data);
		  }
		  return 0;
	}
	void DelNode(long long int count)
	{
          NodeLink*DelN;
          if(count>=NodeCount||count<=0)
			  return;
		  if(count==NodeCount-1)
		  {
			  nail=(nail->unext);free(nail->next->data);
			  free(nail->next);
			  nail->next=NULL;
			  NodeCount--;
			  return;
		  }
          switch(int(count>=(NodeCount/2)))
          {
	  case 1:
		DelN=nail;
		for(long long int i=0;i<(NodeCount-count-1);i++)
		  DelN=DelN->unext;
		(DelN->next)->unext=DelN->unext;
		(DelN->unext)->next=DelN->next;
		free(DelN->data);
		free(DelN);	
		NodeCount--;   
		return;
          case 0:
		DelN=head;
		for(long long int i=0;i<count;i++)
		  DelN=DelN->next;
		(DelN->next)->unext=DelN->unext;
		(DelN->unext)->next=DelN->next;
		free(DelN->data);
		free(DelN);
		NodeCount--;
		return ;
          }
	}
	void DelAll()
	{
		for(long long int i=0;i<(NodeCount-1);i++)
			nail=nail->unext,
			free(nail->next->data),
			free(nail->next);
		NodeCount=1;
		head=nail;head->next=nail;nail->unext=head;
	}
	t*ArrayUse()
	{
		NodeLink*save=head;
        	t*retArray=(t*)malloc(size_t(SinLength*NodeCount));
        	for(long long int i=0;i<NodeCount;i++)
        	{
			retArray[i]=*save->data;
			save=save->next;
		}
		LogNow->Addr=(void*)retArray;
		LogNow->next=(TurnLog*)malloc(sizeof(TurnLog));
		LogNow=LogNow->next;LogNow->Addr=0;
        	return  retArray;
	}
	t*ArrayShowc()
    	{ 
        NodeLink*save=head;
        t*retArray=(t*)malloc(size_t(SinLength*(NodeCount+1)));
        for(long long int i=0;i<NodeCount;i++)
			retArray[i]=*(t*)save->data,
			save=save->next;
	retArray[NodeCount]='\0';
	LogNow->Addr=(void*)retArray;
	LogNow->next=(TurnLog*)malloc(sizeof(TurnLog));
	LogNow=LogNow->next;LogNow->Addr=0;
        return retArray;
    	}
	void ClearArray()
	{
		TurnLog*Enum;
		bool T=0;
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
	long long int GetLength()
    	{
		return NodeCount;
	}  
	t& operator [](long long int count)    //Not Sure
    	{
        	return *NodeSet(count);
    	}
    	void  operator +=(long long int count)
    	{
        	AddNode(count);
    	}
	void AddString(const t*strings,int length)
    	{
                NodeLink*save=nail;
		AddNode(length);save=save->next;
		for(long long int i=0;i<length;i++)
		{
			*(t*)save->data=strings[i];
			save=save->next;
		}
    	}
	void WriString(const t*strings,int length)
	{
		if(length>NodeCount)
			AddNode(length-NodeCount);
		else if(NodeCount>length)
			DelAll(),AddNode(length-1);
		NodeLink*save=head;
		for(long long int i=0;i<length;i++)
			*(t*)save->data=strings[i],
			save=save->next;
	}
	void  operator +=(t letter)
	{
                *nail->data=letter;
		AddNode(1);
		
	}
	void  operator  =(t lether)
	{
		DelAll();
		*head->data=lether;
	}
	void  operator  =(long long int count)
	{
		DelAll();
		AddNode(count);
	}
	~DCDNode()
	{
		ClearArray();
		DelAll();
        free(LogHead);
		free(head);
	}
};
