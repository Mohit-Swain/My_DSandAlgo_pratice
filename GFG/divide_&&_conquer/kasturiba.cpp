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
long int bitMultiply(string a,string b){
	return (a[0] - '0')*(b[0] - '0');
}
string add(string a,string b){
	string res;

	int n = MakeEqual(a,b);
	int carry =0;
	for(int i = n-1;i>=0;i--){
		int firstBit = (a[i] - '0'),secondBit = (b[i] - '0');
		int sum = (firstBit ^ secondBit ^ carry);
		res = (char)(sum + '0') + res;

		carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry) ;
	}

	if(carry > 0){
		res = '1' + res;
	}

	return res;
}
long int multiply(string a , string b){
	string res;
	int n = MakeEqual(a,b);
	//base case 
	if(n==0){ return 0;}
	if(n==1){ return bitMultiply(a,b);}
	int n1 = n/2;	//floor
	int n2 = n - n1;	//ceil

	string a0 = a.substr(0,n1);
	string a1 = a.substr(n1 , n2);
	string b0 = b.substr(0,n1);
	string b1 = b.substr(n1,n2);

	long int a0b0 = multiply(a0,b0);
	long int a1b1 = multiply(a1,b1);
	long int P = multiply(add(a0,a1),add(b0,b1));

	return (1<<(2*n2))*a0b0 + (1<<n2)*(P - a0b0 - a1b1) + a1b1;
}

int main(){
	printf ("%ld\n", multiply("1100", "1010")); 
    printf ("%ld\n", multiply("110", "1010")); 
    printf ("%ld\n", multiply("11", "1010")); 
    printf ("%ld\n", multiply("1", "1010")); 
    printf ("%ld\n", multiply("0", "1010")); 
    printf ("%ld\n", multiply("111", "111")); 
    printf ("%ld\n", multiply("11", "11")); 
}