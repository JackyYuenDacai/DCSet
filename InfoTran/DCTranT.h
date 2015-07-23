#include"DCInfoT.h"

class DCTran{
DCInfo Conn;
public:
	DCTran(bool IsS,char*Addr=NULL){
	 	Conn.SetAddress(Addr);
	 	Conn.SetIsServer(IsS);
	}
};
