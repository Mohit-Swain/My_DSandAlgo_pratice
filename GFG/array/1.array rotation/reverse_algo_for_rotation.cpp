#include"iostream"
using namespace std;

void print_arr(int a[],int n);

void reverse(int arr[], int start, int end){
	 while (start < end) 
    { 
        int temp = arr[start]; 
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    } 
}

void left_rot_rev(int a[], int d, int n)   //note the peculiar way of the statements
{
	reverse(a,0,d-1);
	reverse(a,d,n-1);
	reverse(a,0,n-1); 
}

void right_rot_rev(int a[],int d,int n){
    reverse(a,0,n-1);
    reverse(a,0,d-1);
    reverse(a,d,n-1);
}
void print_arr(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<",";
    }
    cout<<endl;
}
int main(){
	int a[] ={1,2,3,4,5,6,7};
	left_rot_rev(a,2,sizeof(a)/sizeof(a[0]));
	print_arr(a,sizeof(a)/sizeof(a[0]));
    right_rot_rev(a,2,sizeof(a)/sizeof(a[0]));
    print_arr(a,sizeof(a)/sizeof(a[0]));
}