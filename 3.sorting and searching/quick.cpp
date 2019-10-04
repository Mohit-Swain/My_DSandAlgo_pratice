#include"iostream"
using namespace std;
void print_array(int arr[],int n){
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
void quickSort(int a[],int s,int e){
	if(s>=e)
		return;

	int mid =s;
	for(int i=s+1;i<=e;i++){
		if(a[i]<a[s])
			mid++;
	}
	swap(a[s],a[mid]);
	int i=s,j=e;
	while(i<mid && j>mid){
		while(i<mid && a[i]<a[mid]){
			i++;
		}
		while(j>mid && a[j]>=a[mid]){
			j--;
		}

		swap(a[i],a[j]);
	}
	quickSort(a,s,mid-1);
	quickSort(a,mid+1,e);
}
int main(){
	int arr[]={5,4,3,2,1,8,3,4,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	print_array(arr,n);
	quickSort(arr,0,n-1);
	print_array(arr,n);
}