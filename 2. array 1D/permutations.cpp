#include"iostream"
#include<cstring>
using namespace std;
void per(char a[], char b[], int n){		//My Way
	int i, j;
	bool ans= true;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i]==b[j]){
				b[j]= '*';
				break;
			}
		}
		if(j==n){
			ans = false;
		}
	}
	if(ans){
		cout<<"\nPermutations";
	}
	else 
		cout<<"\nNot Permutations";
}

void perfreq(char a[],char b[],int n){		//Sky Way
	int f[128]={0};
	for(int i=0;i<n;i++){
		f[a[i]]++;
		f[b[i]]--;
	}

	int s =0;
	for(int i=0;i<128;i++){
		if(f[i]!=0){
			s=1;
			break;
		}
	}

	if(s==0){
		cout<<"\nPermutations";
	}
	else
		cout<<"\nNot Permutaions";
}
int main(){
	char a[100],b[100];
	cin>>a;
	cin>>b;
	int n = strlen(a);
	if(n!=strlen(b))
		cout<<"Bye Bye"<<endl;
	else{
		perfreq(a,b,n);
		per(a,b,n);
	}
}