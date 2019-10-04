#include"iostream"
using namespace std;
void mix(int a[],int b[],int al,int bl){
	int *m = new int[al+bl],ml = al+bl,i=0,j=0,k=0;
	while(i<al && j<bl){
		if(a[i]<b[j]){
			m[k]=a[i];
			i++;k++;
		}
		else{
			m[k]=b[j];
			j++;k++;
		}
	}
	while(i<al){
		m[k]=a[i];
		i++;k++;
	}
	while(j<bl){
		m[k]=b[j];
		j++;k++;
	}
	//Display the array;
	for(k=0;k<ml;k++){
		cout<<m[k]<<" ";
	}

	delete []m;
}
int main(){
	int a[] = {0,1,3,5,7,9,10,12,13,14,15,20},b[]={0,2,3,4,6,8,9,11,12},al,bl;
	al= sizeof(a)/sizeof(a[0]);
	bl = sizeof(b)/sizeof(b[0]);
	mix(a,b,al,bl);
}