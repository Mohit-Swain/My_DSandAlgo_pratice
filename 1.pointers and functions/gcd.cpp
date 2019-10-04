#include"iostream"
using namespace std;

int gcd(int a,int b){
	int r = b%a;
	if(r==0){
		return a;
	}
	
	return gcd(r,a);
}

int main(){
	int a,b;
	cout<<"enter two numbers ";
	cin>>a>>b;
	cout<<"\nit's gcd is "<<gcd(a,b);
}
