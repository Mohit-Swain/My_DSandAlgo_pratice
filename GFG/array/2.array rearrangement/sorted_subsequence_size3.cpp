//subsequence bole to not continuous
//Input:  arr[] = {12, 11, 10, 5, 6, 2, 30}
// Output: 5, 6, 30

// Input:  arr[] = {1, 2, 3, 4}
// Output: 1, 2, 3 OR 1, 2, 4 OR 2, 3, 4

// Input:  arr[] = {4, 3, 2, 1}
// Output: No such triplet
#include"iostream"
using namespace std;

void sort_subsequence(int a[],int n){
	int smaller[n],greater[n];
	smaller[0]=-1;
	int min=0;
	for(int i=1;i<n;i++){
		if(a[i]<=a[min]){
			min = i;
			smaller[i]=-1;
		}
		else{
			smaller[i] =  min;
		}
	}

	greater[n-1]=-1;
	int max = n-1;
	for(int i=n-2;i>=0;i--){
		if(a[i]>=a[max]){
			max = i;
			greater[i]=-1;
		}
		else{
			greater[i] = max;
		}
	}

	for(int i=0;i<n;i++){
		if(smaller[i]!= -1 and greater[i]!=-1){
			cout<<a[smaller[i]]<<" "<<a[i]<<" "<<a[greater[i]]<<endl;
		}
	}
	cout<<"\n\n";
}
int main(){	
	int a[]={12,11,10,5,6,2,30};
	sort_subsequence(a,sizeof(a)/sizeof(a[0]));
	int arr[] = {1, 2, 3, 4};
	sort_subsequence(arr,sizeof(arr)/sizeof(arr[0]));
}