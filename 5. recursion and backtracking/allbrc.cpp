#include"iostream"
#include"string"
using namespace std;

void brac(int n,string s,int o,int c){
	//cout<<s<<endl;
	if(s.length()==n && o==c){
		cout<<s<<endl;
		return;
	}

	if(2*o < n){
		brac(n,s+"(",o+1,c);
	}

	if(c<o){
		brac(n,s+")",o,c+1);
	}

}

int main(){
	int n;
	cin>>n;
	string s="";
	brac(2*n,s,0,0);
}