#include"iostream"
using namespace std;
int power(int a,int b){
	int res =1;
	while(b>0){
		if(b&1){
			res = res*a;
		}
		a = a*a;
		b = b>>1;
	}
	return res;
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<power(a,b)<<endl;
	return 0;
}