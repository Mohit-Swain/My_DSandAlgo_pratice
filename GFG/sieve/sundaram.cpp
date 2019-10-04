#include<iostream>
#include <cstring>
using namespace std;
void sieve(int n){
	int nNew = (n-2)/2;
	bool marked[nNew + 1];
	memset(marked,false,sizeof(marked));

	
	for(int i=1;i<=nNew;i++){
		for(int j=i; i + j + 2*i*j <=nNew;j++){
			marked[i + j + 2*i*j] = true;
		}
	}

	cout<<"2 ";
	for(int i=1;i<=nNew;i++){
		if(marked[i]==false)
			cout<<2*i+1<<" ";
	}
}
int main(){
	int n;
	cin>>n;
	sieve(n);

	return 0;
}