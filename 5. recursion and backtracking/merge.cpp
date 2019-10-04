#include"iostream"
using namespace std;

void mergesort(int a[],int n){

	if(n==1){
		return;
	}
	
	mergesort(a,n/2);
	mergesort(a+n/2,n - n/2);

	int b[n],i=0,j= n/2,k=0;

	while(i<n/2 && j<n){
		if(a[i]<a[j]){
			b[k++]= a[i++];
		}
		else{
			b[k++] = a[j++];
		}
	}

	while(i<n/2){
		b[k++] = a[i++];
	}

	while(j<n){
		b[k++] = a[j++];
	}

	for(i=0;i<n;i++)
		a[i]=b[i];
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	mergesort(a,n);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}