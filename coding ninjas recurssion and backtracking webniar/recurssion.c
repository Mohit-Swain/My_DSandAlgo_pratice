#include"stdio.h"
int fact(int n){
	int small;
	if(n==0)	//base case
		return 1;
	small = fact(n-1);
	return n*small;
}
int power(int n,int r){
	if(r==0)
		return 1;
	else{
		return n*power(n,r-1);
	}
}

void TOH(char s,char h,char d,int n){
	if(n==1){
		printf("disk no %d from %c to %c \n",n,s,d);
		return;
	}
	TOH(s,d,h,n-1);
	printf("disk no %d from %c to %c \n",n,s,d);
	TOH(h,s,d,n-1);
}
int main(){
	TOH('A','B','C',4);
}