#include<iostream>
#include<string>
#include<vector>
using namespace std;
string multiply(string s1,string s2){
    int n1 = s1.length();
    int n2 = s2.length();   
    if(n1==0 || n2 ==0){
        return "0";
    }
    
    string s;
    vector<int> res(n1+n2,0);
    int i,j;
    int n_i=0,n_j=0;
    for(i=n2-1;i>=0;i--){
        int x = s2[i]-'0';
        int c=0;
        n_j = 0;
        for(j=n1-1;j>=0;j--){
            int y = s1[j]-'0';
            int sum = res[n_i+n_j]+ y*x + c;
            res[n_i+n_j] += sum%10;
            c = sum/10;
            n_j++;
        }

        if(c>0){
            res[n_i + n_j] += c;
        }
        n_i++;
    }
    
    while(res.back()==0){
        res.pop_back();
    }

    if(res.empty()){
        return "0";
    }

    for(int i=0;i<res.size();i++){
        s = s + to_string(res[i]);
    }

    return s;
}
int main(){
    string s1 = "98475743985789720593";
    string s2 = "4984539082598437098";
    cout<<multiply(s1,s2);
    return 0;
}