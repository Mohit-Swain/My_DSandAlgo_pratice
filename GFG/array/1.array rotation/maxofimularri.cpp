#include"iostream"
using namespace std;
int maxSum(int a[],int n){
	int arrSum=0,j;
	for(j=0;j<n;j++)
		arrSum += a[j];

	int currSum=0,maxSum;

	for(j=0;j<n;j++)
		currSum += j*a[j];

	maxSum = currSum;

	for(j=1;j<n;j++){
		currSum = currSum + arrSum - (n)*a[n-j];

		if(currSum > maxSum)
			maxSum = currSum;
	}

	return maxSum;
}
int main(){
	int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "\nMax sum is " << maxSum(arr, n); 
    return 0; 
}
