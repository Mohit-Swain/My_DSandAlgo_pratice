#include<iostream>
#include<cstring>
using namespace std;
//spf - smallest prime factor
#define MSIZE 1000001
int spf[MSIZE];

void sieve(){
	memset(spf,0,sizeof(spf));
	spf[1]=1;
	for(int i=2;i<MSIZE;i+=2){
		spf[i]=2;
	}
	for(int i=3;i*i<MSIZE;i+=2){
		if(spf[i]==0){
			for(int j=i;j<MSIZE;j+=i){
				if(spf[j]==0)
					spf[j] = i;
			}
		}
	}
}

void primefactor(int n){
	while(n!=1){
		cout<<spf[n]<<" ";
		n = n/spf[n];
	}
}
int main()
{
	sieve();
	int n;
	cin>>n;
	primefactor(n);
	return 0;
}