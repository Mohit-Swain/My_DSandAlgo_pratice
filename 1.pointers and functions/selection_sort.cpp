#include"iostream"
using namespace std;
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int main(){
	int a[10]={6,3,5,2,4,1,10,8,9,7},i,j,minidx;
	for(i=0;i<9;i++){
		minidx = i;
		for(j=i+1;j<10;j++){
			if(a[j] < a[minidx]){
				minidx=j;
			}
		}
		swap(&a[i],&a[minidx]);
	}

	for(i=0;i<10;i++){
		cout<<a[i]<<" ";
	}
}