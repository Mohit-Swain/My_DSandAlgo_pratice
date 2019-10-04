#include"iostream"
#include"string"
#include"algorithm"
using namespace std;
bool compare(string a,string b){
	//SEXY logic
	string AB = a.append(b);
	string BA = b.append(a);

	return AB>BA;
}

void maxno(string s[],int n){
	sort(s,s+n,compare);
	for(int i=0;i<n;i++){
		cout<<s[i];
	}
}

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		string s[n];
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		maxno(s,n);
		cout<<endl;
	}
	return 0;
}