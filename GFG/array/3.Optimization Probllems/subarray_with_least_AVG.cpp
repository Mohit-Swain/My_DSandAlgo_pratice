//to find the subarray with the least avg in the arr given an int k denoting the sizeof the subarray
#include"iostream"
using namespace std;

void findMinAvgSubarray(int a[],int n,int k){
	int sum=0,minsum=0,start_index=0;
	for(int i=0;i<k;i++){
		sum+=a[i];
	}
	minsum = sum;
	for(int i=k;i<n;i++){
		sum += a[i]-a[i-k];
		if(sum<minsum){
			minsum = sum;
			start_index = (i - k +1);	//coz the series includes the element a[i] as well
		}
	}

	cout<<"the range is [ "<<start_index<<", "<<start_index+k-1<<"]"<<endl;

}
int main() 
{ 
    int arr[] = { 3, 7, 90, 20, 10, 50, 40 }; 
    int k = 3; // Subarray size 
    int n = sizeof arr / sizeof arr[0]; 
    findMinAvgSubarray(arr, n, k); 
    return 0; 
} 