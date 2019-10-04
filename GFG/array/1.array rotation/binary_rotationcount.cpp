//Remember that the rotation count of an array is same as 
//index of smallest element in the array.
// Here we are finding the smallest element in the array.

#include"iostream"
using namespace std;
int findMin(int a[],int low,int high){
	if(high<low){			//see the return statement in findMin(a,low,m-1); note that if m==low
							//the next line can have high <low for UNrotated sorted array as in arr4[]
		return a[0];
	}

	if(high==low){
		return a[low];
	}

	int m = (high + low)/2;

	if(m<high && a[m+1]<a[m]){
		return a[m+1];
	}

	if(low < m && a[m]<a[m-1]){
		return a[m];
	}


	if(a[m]<a[high]){
		return findMin(a,low,m-1);
	}

	return findMin(a,m+1,high);
}

int main(){
	int arr1[] = {5, 6, 1, 2, 3, 4};  
    int n1 = sizeof(arr1)/sizeof(arr1[0]);  
    cout << "The minimum element is " << findMin(arr1, 0, n1-1) << endl;  
  
    int arr2[] = {1, 2, 3, 4};  
    int n2 = sizeof(arr2)/sizeof(arr2[0]);  
    cout << "The minimum element is " << findMin(arr2, 0, n2-1) << endl;  
  
    int arr3[] = {1};  
    int n3 = sizeof(arr3)/sizeof(arr3[0]);  
    cout<<"The minimum element is "<<findMin(arr3, 0, n3-1)<<endl;  
  
    int arr4[] = {1, 2};  
    int n4 = sizeof(arr4)/sizeof(arr4[0]);  
    cout<<"The minimum element is "<<findMin(arr4, 0, n4-1)<<endl;  
  
    int arr5[] = {2, 1};  
    int n5 = sizeof(arr5)/sizeof(arr5[0]);  
    cout<<"The minimum element is "<<findMin(arr5, 0, n5-1)<<endl;  
  
    int arr6[] = {5, 6, 7, 1, 2, 3, 4};  
    int n6 = sizeof(arr6)/sizeof(arr6[0]);  
    cout<<"The minimum element is "<<findMin(arr6, 0, n6-1)<<endl;  
  
    int arr7[] = {1, 2, 3, 4, 5, 6, 7};  
    int n7 = sizeof(arr7)/sizeof(arr7[0]);  
    cout << "The minimum element is " << findMin(arr7, 0, n7-1) << endl;  
  
    int arr8[] = {2, 3, 4, 5, 6, 7, 8, 1};  
    int n8 = sizeof(arr8)/sizeof(arr8[0]);  
    cout << "The minimum element is " << findMin(arr8, 0, n8-1) << endl;  
  
    int arr9[] = {3, 4, 5, 1, 2};  
    int n9 = sizeof(arr9)/sizeof(arr9[0]);  
    cout << "The minimum element is " << findMin(arr9, 0, n9-1) << endl;  
  
    return 0;  	
}












