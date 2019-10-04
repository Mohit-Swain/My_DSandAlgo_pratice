//Our task is to write a program to rearrange the array such that elements at even positions are greater 
//than all elements before it and elements at odd positions are less than all elements before it.
#include"iostream"
using namespace std;
void sort(int arr[],int n){
	int i,j;
	for(i=0;i<n;i++){	//bubbly
		for(j=i+1;j<n;j++){
			if(arr[i]>arr[j]){	
				swap(arr[i],arr[j]);
			}
		}
	}
}

void Arr(int arr[],int n){
	int copy[n],i;
	for(i=0;i<n;i++){
		copy[i] = arr[i];
	}

	sort(copy,n);

	int evenn = n/2;
	int oddn = n - evenn;

	i=0;	//for odd places starting from 1st
	int j = oddn -1;
	while(j >= 0){	//for odd places
		arr[i] = copy[j];
		j--; 
		i+=2;
	}

	i=1;
	j= oddn;
	while(j<n){
		arr[i] = copy[j];
		j++;
		i+=2;
	}
}

int main(){
	int arr[]= {0,1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	Arr(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}