//Given an array of size n where all elements are distinct and in range from 0 to n-1,
//change contents of arr[] so that arr[i] = j is changed to arr[j] = i.
#include"iostream"
using namespace std;
//note: easy way will be to solve using a temp array but not here.
void print_array(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void rearrange(int arr[],int n){
	
	for(int i =0;i<n;i++){
		arr[arr[i]%n] += i*n;
		print_array(arr,n);
	}

	for(int i=0;i<n;i++){
		arr[i] = arr[i]/n ;
	}

}

int main(){
	int arr[]  = {1, 3, 0, 2};
	rearrange(arr,sizeof(arr)/sizeof(arr[0]));
}