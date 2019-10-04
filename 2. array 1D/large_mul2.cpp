#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string multiply(string s1,string s2){
    int n1 = s1.length();
    int n2 = s2.length();
    if(n1==0 || n2 ==0){
        return "0";
    }
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    vector<int> v(n1+n2,0);
    int c=0;
    for(int i=0;i<n1;i++){
        int x = s1[i]-'0';
        for(int j=0;j<n2;j++){
            int y = s2[j]-'0';
            int sum = v[i+j] + x*y +c;
            v[i+j] = sum%10;
            c = sum/10;
        }
        if(c>0){
            v[i+n2] += c;
        }

    }

    while(v.back()==0){
        v.pop_back();
    }

    if(v.empty()){
        return "0";
    }
    string s="";
    for(int i : v){
        s = to_string(i)+s;
    }
    return s;
}
int main(){
    string a,b;
    cout<<"enter first number";
    cin>>a;
    cout<<"enter second number";
    cin>>b;
    cout<<multiply(a,b)<<endl;
    return 0;
}