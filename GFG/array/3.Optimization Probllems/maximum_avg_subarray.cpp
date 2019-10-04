#include"iostream"
using namespace std;
int maxAvgSubarray(int a[],int n,int k){
	if(k>n)
		return -1;

	int end=0;
	int sum=0,currsum=0;
	int end_ans = k-1;
	for(int i=0;i<k;i++){
		currsum += a[i];
	}

	sum = currsum;
	end=k;
	while(end<n){
		currsum = currsum + a[end]-a[end -k];
		if(currsum>sum){
			sum=currsum;
			end_ans = end;
		}
		end++;
	}
	return end_ans-k+1;
}
int findMaxAverage(int arr[], int n, int k) 
{ 
    // Check if 'k' is valid 
    if (k > n) 
        return -1; 
  
    // Compute sum of first 'k' elements 
    int sum = arr[0]; 
    for (int i=1; i<k; i++) 
        sum += arr[i]; 
  
    int max_sum = sum, max_end = k-1; 
  
    // Compute sum of remaining subarrays 
    for (int i=k; i<n; i++) 
    { 
        int sum = sum + arr[i] - arr[i-k]; 
        if (sum > max_sum) 
        { 
            max_sum = sum; 
            max_end = i; 
        } 
    } 
  
    // Return starting index 
    return max_end - k + 1; 
} 
int main() 
{ 
    int arr[] = {1, 12, -5, -6, 50, 3}; 
    int k = 4; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "The maximum average subarray of "
         "length "<< k << " begins at index "
         << maxAvgSubarray(arr, n, k); 
    return 0; 
} 