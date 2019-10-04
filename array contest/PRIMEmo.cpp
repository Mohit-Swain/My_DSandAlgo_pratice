#include"iostream"
#include<cmath>
using namespace std;
int p[1000005]={0};
int main(){
	p[1]=1;
	for(int i=2;i<sqrt(1000005);i++){
		if(p[i]==1)
			continue;
		for(int j=i*i;j<1000005;j++){
			if(p[j]==0 and j%i==0){
				p[j]=1;
			}
		}
	}

	int n,a,b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		int m=0;
		for(int j=a;j<=b;j++)
			if(p[j]==0)
				m++;

		cout<<m<<endl;
	}
}