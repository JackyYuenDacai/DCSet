#include<stdio.h>
#include<time.h>
#include"DCRNode.h"
int main(){
	int A[10000];
	for(int i=0;i<10000;i++)
		A[i]=rand();
	DCNode<int> test;
	test.AddArray(A,10000);
	srand(time(0));
	for(int i=0;i<1;i++){
		int buf=rand()%10000;
		int testNo=test[buf];
		if(testNo!=A[buf]){
			printf("BUF:%d NUM:%d\n",buf,A[buf]);
		}
	}
	return 0;
}
