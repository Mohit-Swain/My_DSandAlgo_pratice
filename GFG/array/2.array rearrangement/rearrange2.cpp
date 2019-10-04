// Rearrange the array elements so that positive and negative numbers are placed alternatively. 
// If there are more positive or negetive numbers they appear at the end of the array. 
//made with <3 by Mohit
#include"iostream"
using namespace std;
void GFG :: rearrange(int arr[], int n) 
{ 
    // The following few lines are  
    // similar to partition process 
    // of QuickSort. The idea is to  
    // consider 0 as pivot and 
    // divide the array around it. 
    int i = -1; 
    for (int j = 0; j < n; j++) 
    { 
        if (arr[j] < 0) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
  
    // Now all positive numbers are at  
    // end and negative numbers at the 
    // beginning of array. Initialize  
    // indexes for starting point of 
    // positive and negative numbers  
    // to be swapped 
    int pos = i + 1, neg = 0; 
  
    // Increment the negative index by  
    // 2 and positive index by 1, 
    // i.e., swap every alternate negative  
    // number with next positive number 
    while (pos < n && neg < pos &&  
                     arr[neg] < 0) 
    { 
        swap(&arr[neg], &arr[pos]); 
        pos++; 
        neg += 2; 
    } 
} 
  
void Arr(int arr[],int n){
	int i=0,j=1;	//plan to keep the positive nos at even place
		while(1){
			while(arr[i]>=0 && i<n){
				i+=2;
			}
			while(arr[j]<0 && j<n){
				j+=2;
			}
			if(i>=n || j>=n)
				break;
			swap(arr[i],arr[j]);
		}

}

int main(){
	int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  	Arr(arr,n);

  	for(int i=0;i<n;i++){
  		cout<<arr[i]<<" ";
  	}
}