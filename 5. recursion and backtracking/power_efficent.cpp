#include"iostream"
using namespace std;

int power(int a,int b){
	if(b==0){
		return 1;
	}

	int ans;
	if(b&1){
		ans = a * power(a,b/2) * power(a,b/2);
	}
	else{
		ans = power(a,b/2) * power(a,b/2);
	}

	return ans;
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<power(a,b)<<endl;
}