#include"iostream"
using namespace std;

int pair_search(int a[],int sum,int n){
	int i,low=0,high = n-1;
	for(i=0;i<n-1;i++){	//see n-1
		if(a[i] > a[i+1])
			break;
	}
	high = i;
	low = (i+1)%n;

	while(low!=high){		//see here low!=high not low<high. GOT it??
		if(a[low]+a[high]==sum){
			return 1;
		}
		if(a[low]+a[high]<sum){
			low=(low+1)%n;
		}
		else{
			high = (n + high-1)%n;		//note this is to see that hight always remain <n.
		}
	}
	return 0;

}

int main() 
{ 
    int arr[] = {11, 15, 6, 8, 9, 10}; 
    int sum = 16; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout<<pair_search(arr,sum,n);
 }








