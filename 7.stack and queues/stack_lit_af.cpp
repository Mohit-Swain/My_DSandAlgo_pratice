#include<bits/stdc++.h>
using namespace std;
int preference(char c){
    if(c=='+'||c=='-'){
        return 0;
    }
    else{
        return 1;
    }
}
void intopost(){
    string s;
    cout<<"enter expression ";
    cin>>s;
    cout<<s;
    stack<char> opr,opd;
    for(int i=0;i<s.length();i++){
        char o = s[i];
        if(o>='0' && o<='9'){
            opd.push(o);
        }
        else{
            while(!opr.empty() && preference(o)<=preference(opr.top())){
                opd.push(opr.top());
                opr.pop();
            }
            opr.push(o);

        }
    }
    while(!opr.empty()){
        opd.push(opr.top());
        opr.pop();
    }

    s.clear();
    while(!opd.empty()){
        //this is why this is called reverse polish notation
        s.push_back(opd.top());
        opd.pop();
    }
    cout<<endl<<s<<endl;
}
int main(){
    intopost();
    return 0;
}