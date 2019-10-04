#include <iostream>
using namespace std;
/*//////////////My Solution////////////////*/
int main()
{
	int a[] = {1, 20, 2, 10},t,n=sizeof(a)/sizeof(a[0]);
	int *c = new int[n],i,j,m=0;
 	for(i=0;i<n;i++){
 		j=0;
 		int s=0;
 		while(j<n){
 			s += j*a[(i+j)%n];
 			j++;
 		}
 		if(s>m){
 			m=s;
 			int k=i,y=0;
 			while(y<n){
 				c[y]= a[(k+y)%n];
 				y++;
 			}
 		}
 	}
 	for(i=0;i<n;i++){
 		cout<<c[i]<<",";
 	}
 	delete c;

 	cout<<"\nmax value is "<<m;
	return 0;
}