#include<DCSet/DCNNode.h>
#include<stdio.h>
#include<unistd.h>  
#include<sys/time.h>
int gettimeofday(struct timeval *tv, struct timezone *tz);
int main(){
	printf("%s","Hello "+"World");
	putchar('\n');
	return 0;
}
