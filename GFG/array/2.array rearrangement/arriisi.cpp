//code by mohit
//bad method by coping the array
#include"iostream"
using namespace std;
void print_array(int arr[],int n);

void rearrange(int arr[],int n){
	int *count,i;
	count = new int[n]{};
	for(i=0;i<n;i++){
	    count[i]=-1;
	}
	for(i=0;i<n;i++){
		if(arr[i]==-1)
			continue;

		count[arr[i]]=arr[i];
	}
	print_array(count,n);
    delete count;
}

void print_array(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
int main(){
	int *arr,t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    arr = new int[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    rearrange(arr,n);
	    delete arr;
	}
	
}