//Given an array of integers of size n. Assume ‘0’ as invalid number and all other as valid number.
//Convert the array in such a way that if next valid number is same as current number,
//double its value and replace the next number with 0.
//After the modification, rearrange the array such that all 0’s are shifted to the end.

//Examples:

//Input : arr[] = {2, 2, 0, 4, 0, 8}
//Output : 4 4 8 0 0 0

//Input : arr[] = {0, 2, 2, 2, 0, 6, 6, 0, 0, 8}
//Output :  4 2 12 8 0 0 0 0 0 0

#include"iostream"
using namespace std;

//done by Mohit Swain
void printarray(int arr[],int n){
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void arraydouble(int arr[],int n){
	for(int i=0;i<n-1;i++){
		if(arr[i]==0){
			continue;
		}
		if(arr[i]==arr[i+1]){
			arr[i]= 2*arr[i];
			arr[i+1]=0;
			i++;
		}
	}
}
void zeroend(int arr[],int n){
	int count =0;
	for (int i = 0; i < n; ++i)
	{
		if(arr[i]!=0){
			arr[count++]=arr[i];
		}
	}

	while(count < n){
		arr[count++]=0;
	}
}

void wrap(int arr[],int n){
	printarray(arr,n);
	arraydouble(arr,n);
	printarray(arr,n);
	zeroend(arr,n);
	printarray(arr,n);
	cout<<endl;
}

int main(){
	int arr[] ={2, 2, 0, 4, 0, 8};
	int n = sizeof(arr)/sizeof(int);
	wrap(arr,n);

	int arr2[]={0, 2, 2, 2, 0, 6, 6, 0, 0, 8};
	int n2 = sizeof(arr2)/sizeof(int);
	wrap(arr2,n2);


}