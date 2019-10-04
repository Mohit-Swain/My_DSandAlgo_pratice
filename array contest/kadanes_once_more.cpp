#include"iostream"
using namespace std;
void kadanes(int arr[],int n){
	int currMax =0,totalMax=0;
	for(int i=0;i<n;i++){
		currMax += arr[i];
		if(currMax<0){
			currMax =0;
		}
		if(currMax>totalMax){
			totalMax = currMax;
		}
	}
	cout<<totalMax<<endl;
}
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		kadanes(a,n);
	}
}