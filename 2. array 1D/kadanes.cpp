#include"iostream"
using namespace std;

int kadanes(int a[],int n){
	int i,maxhere=0,maxtotal=0;
	for(i=0;i<n;i++){
		maxhere += a[i];

		if(maxhere<0)
			maxhere =0 ;

		else if(maxhere>maxtotal){
			maxtotal = maxhere;
		}
	}

	return maxtotal;
}
int main(){
	int p[]= {-1, 40, -14, 7, 6, 5, -4, -1} ,i,n,sum=0, candidate1,candidate2;
	n= sizeof(p)/sizeof(p[0]);
	candidate1 = kadanes(p,n);
	for(i=0;i<n;i++){
		sum += p[i];

		p[i]= -p[i];
	}

	candidate2 = sum + kadanes(p,n);	// sum -(-kadanes)

	cout<<max(candidate1,candidate2)<<endl;
}