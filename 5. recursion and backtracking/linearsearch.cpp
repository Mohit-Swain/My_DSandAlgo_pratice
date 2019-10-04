#include"iostream"
using namespace std;
int lsearch(int a[],int n,int key){
	if(n==0){
		return -1;
	}
	if(a[0]==key){
		return 0;
	}
	int found= lsearch(a+1,n-1,key);
	if(found==-1)
		return -1;
	return found +1;
}

int main(){
	int a[]={1,2,3,4,6,7,8,10};
	int n = sizeof(a)/sizeof(a[0]);
	int key;
	cin>>key;
	cout<<lsearch(a,n,key);
}