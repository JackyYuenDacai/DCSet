#include<stdlib.h>
#include<string.h>

#ifndef DCDNODE_H
 #define DCDNODE_H
#endif

char Copyright[]="Copyright 2014@JackyYuenDacai";
class DCDNode
{
  struct NodeLink
  {
	  unsigned char c;
	  NodeLink*next,*unext;
  };
  struct TurnLog
  {
	  unsigned char*Addr;
	  TurnLog*next;
  };
  NodeLink*head,*nail;
  TurnLog*LogHead,*LogNow;
  long long int NodeCount;
public:
	DCDNode(long long int Length=1)
	{
		head=(NodeLink*)malloc(sizeof(NodeLink));
				  nail=head;
				  nail->unext=head;
				  head->next=nail;
				  NodeCount=Length;
			for( long long int i=0;i<(Length-1);i++)
			{
                         nail->next=(NodeLink*)malloc(sizeof(NodeLink));
                         (nail->next)->unext=nail;
						 nail=nail->next;
            }
		LogHead=(TurnLog*)malloc(sizeof(TurnLog));
		LogNow=LogHead;LogNow->Addr=0;
	}
	void Settle(long long int Length = 1)
	{
		if(head!=NULL)return;
		head=(NodeLink*)malloc(sizeof(NodeLink));
				  nail=head;
				  nail->unext=head;
				  head->next=nail;
				  NodeCount=Length;
		for( long long int i=0;i<(Length-1);i++)
		{
                         nail->next=(NodeLink*)malloc(sizeof(NodeLink));
                         (nail->next)->unext=nail;
						 nail=nail->next;
        }
		LogHead=(TurnLog*)malloc(sizeof(TurnLog));
		LogNow=LogHead;LogNow->Addr=0;
	}
	void AddNode(long long int count)
    {
		  for( long long int i=0;i<count;i++)
	      {
			  nail->next=(NodeLink*)malloc(sizeof(NodeLink));
              (nail->next)->unext=nail;
			  nail=nail->next;
              NodeCount++;
          }
	}
	unsigned char* NodeSet(long long int count)
    {
          NodeLink*retNode;
		  if((count+1)>NodeCount)
            return (AddNode((count+1)-NodeCount),&nail->c);
		  switch(int(count>=(NodeCount/2)))
		  {
			case 0:
				retNode=head;
				for(long long int i=0;i<count;i++)
				retNode=retNode->next;
				return &(retNode->c);
		    case 1:
				retNode=nail;
				for(long long int i=0;i<(NodeCount-count-1);i++)
					retNode=retNode->unext;
				return &(retNode->c);
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
			  nail=(nail->unext);
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
              free(DelN);	
			  NodeCount--;   
			  return;
          case 0:
              DelN=head;
              for(long long int i=0;i<count;i++)
                DelN=DelN->next;
              (DelN->next)->unext=DelN->unext;
              (DelN->unext)->next=DelN->next;
              free(DelN);
			  NodeCount--;
			  return ;
          }
     }
	void DelAll()
	{
		for(long long int i=0;i<(NodeCount-1);i++)
			nail=nail->unext,
			free(nail->next);
		NodeCount=1;
		head=nail;head->next=nail;nail->unext=head;
	}
	unsigned char*ArrayUse()
	{
		NodeLink*save=head;
        unsigned char*retArray=(unsigned char*)malloc(size_t(sizeof(char)*NodeCount));
        for(long long int i=0;i<NodeCount;i++)
        {
			retArray[i]=save->c;
			save=save->next;
		}
		LogNow->Addr=retArray;
		LogNow->next=(TurnLog*)malloc(sizeof(TurnLog));
		LogNow=LogNow->next;LogNow->Addr=0;
        return  retArray;
	}
	short*ArrayShows()
	{
		NodeLink*save=head;
        short*retArray=(short*)malloc(size_t(sizeof(int)*(NodeCount+1)));
        for(long long int i=0;i<NodeCount;i++)
        {
			retArray[i]=save->c;
			save=save->next;
		}
		retArray[NodeCount]='\0';
		LogNow->Addr=(unsigned char*)retArray;
		LogNow->next=(TurnLog*)malloc(sizeof(TurnLog));
		LogNow=LogNow->next;LogNow->Addr=0;
        return  retArray;
	}
	int* ArrayShowi()
	{
        NodeLink*save=head;
        int*retArray=(int*)malloc(size_t(sizeof(int)*(NodeCount+1)));
        for(long long int i=0;i<NodeCount;i++)
        {
			retArray[i]=save->c;
			save=save->next;
		}
		retArray[NodeCount]='\0';
		LogNow->Addr=(unsigned char*)retArray;
		LogNow->next=(TurnLog*)malloc(sizeof(TurnLog));
		LogNow=LogNow->next;LogNow->Addr=0;
        return  retArray;
    }
    char*ArrayShowc()
    { 
        NodeLink*save=head;
        char*retArray=(char*)malloc(size_t(sizeof(char)*(NodeCount+1)));
        for(long long int i=0;i<NodeCount;i++)
			retArray[i]=char(save->c),save=save->next;
		retArray[NodeCount]='\0';
		LogNow->Addr=(unsigned char*)retArray;
		LogNow->next=(TurnLog*)malloc(sizeof(TurnLog));
		LogNow=LogNow->next;LogNow->Addr=0;
        return retArray;
    }
	unsigned char*ArrayShowu()
    { 
        NodeLink*save=head;
        unsigned char*retArray=(unsigned char*)malloc(size_t(sizeof(char)*(NodeCount+1)));
        for(long long int i=0;i<NodeCount;i++)
			retArray[i]=save->c,save=save->next;
		retArray[NodeCount]='\0';
		LogNow->Addr=retArray;
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
    unsigned char& operator [](long long int count)    //Not Sure
    {
        return *NodeSet(count);
    }
    void  operator +=(long long int count)
    {
        AddNode(count);
    }
    void  operator +=(char*strings)
    {   
		NodeLink*save=nail;
		int Len=(strlen(strings));
		AddNode(Len);save=save->next;
		for(long long int i=0;i<Len;i++)
		{
			save->c=strings[i];
			save=save->next;
		}
    }
    void AddString(char*strings,int length)
    {
                NodeLink*save=nail;

		AddNode(length);save=save->next;
		for(long long int i=0;i<length;i++)
		{
			save->c=strings[i];
			save=save->next;
		}
    }
	void  operator +=(char letter)
	{
                nail->c=letter;
		AddNode(1);
		
	}
	void  operator  =(char lether)
	{
		DelAll();
		head->c=lether;
	}
	void  operator=(char*strings)
	{
		int Len=(strlen(strings));
		if(Len>NodeCount)
			AddNode(Len-NodeCount);
		else if(NodeCount>Len)
			DelAll(),AddNode(Len-1);
		NodeLink*save=head;
		for(long long int i=0;i<Len;i++)
			save->c=(unsigned char)strings[i],
			save=save->next;
	  }
	void  operator=(long long int count)
	{
		DelAll();
		AddNode(count);
	}
	void operator=(DCDNode&dcnode)
	{
		operator=(dcnode.ArrayShowc());
	}
	~DCDNode()
	{
		ClearArray();
		DelAll();
        free(LogHead);
		free(head);
	}
};
