#include"iostream"
using namespace std;

void bubble(int a[],int n,int j){
	if(n==0){
		return;
	}

	if(j==n-1){
		return bubble(a,n-1,0);
	}
	//rec case
	if(a[j]>a[j+1])
		swap(a[j],a[j+1]);

	bubble(a,n,j+1);
}

int main(){
	int a[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	
		cin>>a[i];
	for(int i=0;i<n;i++)	
		cout<<a[i]<<" ";
	cout<<"\n";
	bubble(a,n,0);
	for(int i=0;i<n;i++)	
		cout<<a[i]<<" ";
	cout<<"\n";
}