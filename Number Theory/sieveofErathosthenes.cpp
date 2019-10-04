#include<iostream>
#include <cstring>
#define ll long long
using namespace std;
bool prime[1000000];

void sieve(int n){
	memset(prime,true,sizeof(prime));

	prime[0]=prime[1]=false;

	for(int i=2;i<=n;i++){
		if(prime[i]){
			for(int j=i*i;j<=n;j+=i){
				if(j%i==0){
					prime[j]=false;
				}
			}
		}
	}
	for(int i=0;i<=n;i++){
		cout<<i<<" "<<prime[i]<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	sieve(n);
	return 0;
}