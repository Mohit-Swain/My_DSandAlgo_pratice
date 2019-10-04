// Prints max at first position, min at second position 
// second max at third position, second min at fourth 
// position and so on. 

#include"iostream"
using namespace std;

void rearrange(int arr[],int n){
	int i,min_idx = 0,max_idx=n-1,max_elm = arr[n-1]+1;

	for(i=0;i<n;i++){
		if(i&1){
			arr[i] += (arr[min_idx]%max_elm)*max_elm;
			min_idx++;
		}
		else{
			arr[i] += (arr[max_idx]%max_elm)*max_elm;
			max_idx--;
		}
	}

	for(i=0;i<n;i++){
		arr[i] = arr[i] / max_elm;
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[]={1,2,3,4,5,6,7};
	int n= sizeof(arr)/sizeof(int);
	rearrange(arr,n);

}
