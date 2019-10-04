#include"iostream"
using namespace std;

int main(){
	int a[10]={5,2,7,1,9,4,8,6,3,10},i,j,k,temp;
	for(i=1;i<10;i++){
		j = i;
		k = a[j];
		j--;
		while(j>=0 && a[j]>=k){
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
			j--;
		}

		a[j+1]=k;
	}
	for(i=0;i<10;i++){
		cout<<a[i]<<",";
	}
}