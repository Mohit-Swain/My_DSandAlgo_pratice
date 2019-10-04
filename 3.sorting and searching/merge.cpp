#include"iostream"
using namespace std;
void print_array(int arr[],int n){
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
void mergeSort(int arr[],int s,int e){
	if(s>=e)
		return;
	int mid =(s+e)/2;
	mergeSort(arr,s,mid);
	mergeSort(arr,mid+1,e);

	int b[(e-s+1)];
	int i=s,k=0,j=mid+1;
	while(j<=e && i<=mid){
		if(arr[i]<arr[j]){
			b[k]=arr[i];
			k++;i++;
		}
		else{
			b[k] = arr[j];
			k++;j++;
		}
	}
	while(j<=e){
		b[k] = arr[j];
		k++;j++;
	}

	while(i<=mid){
		b[k]=arr[i];
		k++;i++;
	}
	for(int i=0;i<(e-s+1);i++){
		arr[i+s]=b[i];
	}
}
int main(){
	int arr[]={5,4,3,2,1,8,3,4,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	mergeSort(arr,0,n-1);
	print_array(arr,n);
}