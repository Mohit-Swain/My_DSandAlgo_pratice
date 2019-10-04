/*Step 1 : Copy the entire array two times in temp[0..2n-1] array.
Step 2 : Starting position of array after k rotations in temp[] will be k % n. We do k
Step 3 : Print temp[] array from k % n to k % n + n.*/
#include"iostream"
using namespace std;
void preprocess(int arr[],int n,int temp[]){
	for(int i=0;i<n;i++){
		temp[i]=temp[n+i]=arr[i];		// ek teer do nishana.
	}
}

void leftRotate(int arr[],int n,int k,int temp[]){

	int start = k%n; // see this is because rotation is a periodic function

	for(int i = start; i < start+n; i++){
		cout<<temp[i]<<",";
	}

	cout<<endl;
}

void leftRotate(int arr[], int n, int k) 	///////THE BEST METHOD SO FAR///////////
{ 
    // Print array after k rotations 
    for (int i = k; i < k + n; i++) 
        cout << arr[i%n] << " "; 
} 

int main(){
	int arr[] = {1, 3, 5, 7, 9};
	int n = sizeof(arr)/sizeof(arr[0]);

	int temp[2*n];

	preprocess(arr,n,temp);		//to copy the elements of the array twice in temp.

	int k = 2; 
    leftRotate(arr, n, k, temp); 
  
    k = 3; 
    leftRotate(arr, n, k, temp); 
  
    k = 4; 
    leftRotate(arr, n, k, temp); 
  
}