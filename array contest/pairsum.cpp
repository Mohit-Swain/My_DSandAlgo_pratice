#include"iostream"
#include<algorithm>
using namespace std;

void pair_sum(int arr[],int n,int t){

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){		//always give i+1 until said the no can repeat itself.
			if(arr[i]+arr[j]==t){
				cout<<arr[i]<<" and "<<arr[j]<<endl;
			}
		}
	}
}
int main(){
	int n,t;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);	//for the shake of matching the ans
	cin>>t;
	pair_sum(arr,n,t);
}