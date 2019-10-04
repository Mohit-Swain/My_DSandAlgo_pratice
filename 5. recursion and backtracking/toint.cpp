#include"iostream"
#include<string>
#include<cmath>
using namespace std;

int toint(string s){
	if(s.empty()){
		return 0;
	}

	int smallans= toint(s.substr(1));
	int ans= smallans + pow(10,s.length()-1)*(s[0] - '0' );
	return ans;
}

int main(){
	string s;
	cin>>s;
 	int a=toint(s);
 	cout<<a<<endl;
}	