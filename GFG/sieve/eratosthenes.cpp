#include<iostream>
#include<cstring>
using namespace std;
void sieve(int n){
	bool p[n+1];
	memset(p,true,sizeof(p));
	for(int i=3;i*i<=n;i+=2){
		if(p[i]==true){
			for(int j=i*i;j<=n;j+=i){
				p[j]=false;
			}
		}
	}
	cout<<2<<" ";
	for(int i=3;i<=n;i+=2){
		if(p[i]==true)
			cout<<i<<" ";
	}
}
int main(){
	int n;
	cin>>n;
	sieve(n);
	return 0;
}