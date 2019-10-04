#include"iostream"
using namespace std;

int  binary_search(int a[],int start,int end,int n){
	if(start > end){
		return -1;
	}
	int m = (start + end)/2,i;
	if(a[m]==n){
		return m;
	}
	if(a[m]>n){
		return binary_search(a,0,m-1,n);
	}
	else{
		return binary_search(a,m+1,end,n);
	}
}

int find_pivot(int a[],int n){
	int i,p=-1;				//p=-1 because if the sorted array is not rotated then this function will 
							//return -1. then a simple binary search is sufficent.
	for(i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			p = i;
		}
	}

	return p;
}

int pivoted_binary_search(int a[],int key,int n){
	int pivot = find_pivot(a,n);
	if(pivot==-1)
		return binary_search(a,0,n-1,key);

	
	if(key < a[0]){
		return binary_search(a,pivot+1,n,key);
	}
	else{
		return binary_search(a,0,pivot,key);
	}
}
int main(){
	int a[]= {1,2,3,5, 6, 7, 8, 9, 10}; 
  	int n = sizeof(a)/sizeof(a[0]); 
  	int key ;
  	cin>>key; 
  	cout<<pivoted_binary_search(a,key,n);
}