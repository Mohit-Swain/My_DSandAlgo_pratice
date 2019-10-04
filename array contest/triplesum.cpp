#include"iostream"
#include<algorithm>
using namespace std;

void triple_sum(int arr[],int n,int t){
	int i,j,k;
	for(i=0;i<n-2;i++){
		for(j=i+1;j<n-1;j++){		//always give i+1 until said the no can repeat itself.
			
			for(k=j+1;k<n;k++){
				if(arr[i]+arr[j]+arr[k]==t){
					cout<<arr[i]<<", "<<arr[j]<<" and "<<arr[k]<<endl;
				}
				if(arr[i]+arr[j]+arr[k]>t){
					break;
				}
			}
			if(arr[i]+arr[j]>t)
				break;
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
	sort(arr,arr+n);
	cin>>t;
	triple_sum(arr,n,t);
}
