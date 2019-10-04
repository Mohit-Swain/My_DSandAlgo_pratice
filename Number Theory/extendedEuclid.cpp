#include"iostream"
using namespace std;
int gcd(int a,int b,int &x1,int &x2){
	if(b==0){
		x1 = 1;
		x2 = 0;
		return a;
	}
	int g = gcd(b,a%b,x1,x2);
	int c1 = x2;
	int c2 = x1 - (a/b)*x2;
	x1 = c1;x2 = c2;
	return g;
}
void modInverse(int a,int m){
	int x,y;
	int g = gcd(a,b,x,y);
	if(g!=1){
		cout<<"can't be found"<<endl;
	}
	else{
		int res = (x%m + x)%m; 
		cout<<res<<endl;
	}
}
int main(){
	int a,b;
	int x1,x2;
	cin>>a>>b;
	cout<<gcd(a,b,x1,x2)<<endl;
	cout<<x1<<" "<<x2<<endl;
	return 0;
}