#include"stdio.h"
int gcd(int a,int b){
	int c;
	if((c= a%b)==0){
		return b;
	}
	return gcd(b,c);	
}


int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("\n %d",gcd(a,b));
}