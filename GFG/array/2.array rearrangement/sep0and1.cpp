#include"iostream"
using namespace std;
void sep0and1(int arr[],int size){
	int left=0,right=size -1;
	while(left<right){
		while(arr[left]==0 and left<right){
			left++;
		}
		while(arr[right]==1 and left<right){
			right--;
		}
		if(left<right){
			swap(arr[left],arr[right]);
			left++;
			right--;
		}
	}
}
void anothersep0and1(int arr[],int size){
	int type0=0,type1= size -1;
	while(type0<type1){
		if(arr[type0]==1){
			swap(arr[type0],arr[type1]);
			type1--;
		}
		else{
			type0++;
		}
	}
}
int main(){
	int arr[] = {0, 1, 0, 1, 1, 1}; 
    int i, arr_size = sizeof(arr) / sizeof(arr[0]); 
    sep0and1(arr,arr_size);

    for(int i=0;i<arr_size;i++){
    	cout<<arr[i]<<" ";
    }
}