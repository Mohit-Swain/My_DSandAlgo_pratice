#include"iostream"
using namespace std;

int main(){
	int a[] = {0,2,1,3,0,1,2,1,2,1},i,llarge[10]={0},rlarge[10]={0},ans[10],m=0;
	for(i=0;i<10;i++){
		if(a[i]>m){
			m=a[i];
		}

		llarge[i]=m;
	}

	m=0;
	for(i=9;i>=0;i--){
		if(a[i]>m){
			m=a[i];
		}

		rlarge[i]=m;
	}

	m=0;
	for(i=0;i<10;i++){
		ans[i] = min(llarge[i],rlarge[i]) - a[i];
	}

	for (i = 0; i < 10; i++)
	{
		m+= ans[i];
	}

	cout<<m<<endl;
}