//not working
#include<iostream>
#include <cstring>
using namespace std;
int notprime(int a[],int n){
	return (a[n/64] & (1<<(n>>1)&31));
}
void markcomposite(int a[],int n){
	a[n/64] |= (1<<(n>>1)&31);
}
void bit_sieve(int n){
	int a[n/64];
	memset(a,0,sizeof(a));
	for(int i=3;i<=n;i+=2){
		if(!notprime(a,i)){
			markcomposite(a,i);
		}
	}

	cout<<"2 ";
	 for (int i = 3; i <= n; i += 2) 
        if (!notprime(a, i)) 
            printf("%d ", i); 
}
int main(){
	int n;
	cin>>n;
	bit_sieve(n);
	return 0;
}