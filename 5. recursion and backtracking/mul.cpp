#include"iostream"
using namespace std;

int mul(int a,int b){
	if(a<b)
		return mul(b,a);

	if(b!=0){
		return a + mul(a,b-1);
	}
	else{
		return 0;
	}
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<mul(a,b);
}