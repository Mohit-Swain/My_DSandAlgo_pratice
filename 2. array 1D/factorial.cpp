#include<iostream>
using namespace std;
void print(int a[],int res_size){
	for(int i=0;i<res_size ;i++){
		cout<<a[i];
	}
	cout<<endl;
}
void reverse(int a[],int res_size){
	int s =0,e = res_size-1;
	while(s<e){
		swap(a[s],a[e]);
		s++;
		e--;
	}
}
void multiply(int a[],int n,int &res_size){
	int c=0;
	for(int i=0;i<res_size;i++){
		int mul = a[i]*n + c;
		a[i] = mul%10;
		c = mul/10;
	}

	while(c>0){
		a[res_size++]=c%10;
		c = c/10;
	}
}
void factorial(int n){
	int a[1005]={1},res_size=1;
	for(int i=2;i<=n;i++){
		multiply(a,i,res_size);
	}
	reverse(a,res_size);
	print(a,res_size);
}
int main(){
	int n;
	cin>>n;
	factorial(n);
	return 0;
}