//seperate the -ve numbers to the begging of the array from the +ve nos
#include"iostream"
using namespace std;
void print_array(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void rearrange(int arr[],int n){	//found error it makes the -ve no in seriel wise but not +ve
	int count=0;
	for(int i=0;i<n;i++){
		if(arr[i]<0){
			swap(arr[count++],arr[i]);
		}
	}
	print_array(arr,n);
}
int main(){
	int arr[]={12,11,-13,-5,6,-7,5,-3,-6};
	int n=sizeof(arr)/sizeof(arr[0]);
	rearrange(arr,n);
}