//I shall swap it.
#include"iostream"
using namespace std;
void fix(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		if(arr[i]==-1)
			continue;

		if(arr[i]==i)
			continue;

		swap(arr[i],arr[arr[i]]);
	}
}

int main() 
{ 
    int A[] = { -1, -1, 6, 1, 9, 3, 2, -1, 4, -1 }; 
  
    int len = sizeof(A) / sizeof(A[0]); 
    fix(A, len); 
  
    for (int i = 0; i < len; i++) 
        cout << A[i] << " "; 
} 
