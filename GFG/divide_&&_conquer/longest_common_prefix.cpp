#include<bits/stdc++.h>
using namespace std;

string merge(string a, string b){
	string res = "";
	int n = min(a.length(),b.length());
	for(int i=0;i<n ; i++){
		if(a[i]!=b[i]){
			return res;
		}
		res.push_back(a[i]);
	}
}
string commonPrefix(string arr[],int s,int e){
	if(s==e){
		return arr[s];
	}

	int mid = (s+e)/2;
	string s1 = commonPrefix(arr,s,mid);
	string s2 = commonPrefix(arr,mid+1,e);

	return merge(s1,s2);
}
int main(){
	string arr[] = {"geeksforgeeks", "geeks", 
                    "geek", "geezer"}; 
    int n = sizeof (arr) / sizeof (arr[0]); 
  
    string ans = commonPrefix(arr, 0, n-1); 
  
    if (ans.length()) 
        cout << "The longest common prefix is "
             << ans; 
    else
        cout << "There is no common prefix"; 
    return (0); 
}