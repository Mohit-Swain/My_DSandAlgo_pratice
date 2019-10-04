#include"iostream"
using namespace std;
int count_ones(int n){
	int count =0;
	while(n!=0){
		n= n&(n-1);
		count ++;
	}
	return count;
}
int main(){
	int t,n;
	cout<<"Enter no of testcases : ";
	cin>>t;
	while(t--){
		cin>>n;
		cout<<count_ones(n)<<endl;
	}

}