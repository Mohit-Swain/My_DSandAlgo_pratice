#include<iostream>
#include"string"
using namespace std;
int findLen(string& A, int n, int k, char ch) 
{ 
    int maxlen = 1; 
    int cnt = 0; 
    int l = 0, r = 0; 
      
    while (r < n) { 
        if (A[r] != ch) 
            ++cnt; 
        while (cnt > k) { 
            if (A[l] != ch) 
                --cnt; 
            ++l; 
        } 
        maxlen = max(maxlen, r - l + 1); 
        ++r; 
    } 
    return maxlen; 
} 
 
int main() {
    int k;
    string s;
    cin>>k;
    cin>>s;
    cout<<max(findLen(s,s.length(),k,'a'),findLen(s,s.length(),k,'b'));
	return 0;
}