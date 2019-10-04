#include<bits/stdc++.h>
using namespace std;

int MakeEqual(string &a,string &b){
	int l1 = a.size();
	int l2 = b.size();
	if(l1<l2){
		for(int i=0;i<(l2 - l1);i++){
			a = '0' + a;
		}
		return l2;
	}
	else{
		for(int i=0;i<(l1 - l2);i++){
			b = '0' +b;
		}
		return l1;
	}
}
int digit(char ch){
	return (int)(ch - '0');
}

char str(int n){
	return (char)(n + '0');
}
string addBitStrings(string a, string b){
	int n = MakeEqual(a,b);
	string res;

	int carry =0;

	for(int i=n-1 ;i>=0;i--){
		int firstbit = digit(a[i]);
		int secondbit = digit(b[i]);

		int sum = firstbit ^ secondbit ^carry;

		res = str(sum) + res;

		carry = firstbit & secondbit | secondbit & carry | firstbit & carry ;
	}

	if(carry>0)
		res = '1' + res;

	return res;
}

int main(){
	string str1 = "1100011"; 
    string str2 = "10"; 
  
    cout << "Sum is " << addBitStrings(str1, str2); 
    //cout<<str1<<" "<<str2;
    return 0; 
}