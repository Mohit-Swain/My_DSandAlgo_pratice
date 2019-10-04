#include<iostream>
#define ll long long
using namespace std;
bool isPrime(ll n){
	if(n==1 || n%2==0){
		return false;
	}

	for(ll i=3;i*i<=n;i+=2){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
bool isPrime2(ll n){
	if(n==1){
		return false;
	}
	if(n>2 && n%2==0){
		return false;
	}

	if(n>3 && n%3==0){
		return false;
	}

	for(ll i=5;i*i<=n;i+=6){
		if(n%i==0 || n%(i+2)==0){
			return false;
		}
	}
	return true;
}
int main(){
	ll n;
	cin>>n;
	cout<<isPrime2(n);
	return 0;
}