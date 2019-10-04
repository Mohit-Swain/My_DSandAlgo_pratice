//it aint much but its honest work
#include<iostream>
using namespace std;
float getMedian(int a1[],int a2[],int n1 , int n2){
	int n = n1 + n2;
	int m1 =0,m2 =0;
	// if odd then (n-1)/2 == n/2;
	// else if even then 2 ta - n/2 and n/2-1
	int i=0,j=0,c=0,t = n/2;
	while(i<n1 && j<n2){
		//cout<<m1<<" "<<m2<<endl;
		if(c>t)
			break;
		if(a1[i]<a2[j]){
			m1=m2;
			m2 = a1[i++];
		}
		else{
			m1 = m2;
			m2 = a2[j++];
		}
		c++;
	}

	while(i<n1 && c<=t){
		m1 = m2;
		m2 = a1[i++];
		c++;
	}

	while(j<n2 && c<=t){
		m1 = m2;
		m2 = a2[j++];
		c++;
	}

	if(n&1)
		return m2;
	else 
		return (m1 + m2)/2;
}

int main(){
	int arr1[] = {1 ,3 ,5 ,7};
	int arr2[] = {2  };
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	int n2 = sizeof(arr2)/sizeof(arr2[0]);

	cout<<getMedian(arr1,arr2,n1,n2);

}