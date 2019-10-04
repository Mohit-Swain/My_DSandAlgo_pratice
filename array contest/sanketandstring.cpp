#include<iostream>
#include<cstring>
using namespace std;

int find(char s[],int k,char ch){
    int end =0,start =0;
    int t=k,n = strlen(s);
    int m=0,cm;
    for(start=0;start<n;start++){
        end = start;
        while(end<n){
            if(s[end]==ch){
                t--;
            }
            if(t<0){
                break;
            }
            end++;
        }
        cm= end - start;
        //cout<<cm<<" ";
        if(cm>m){
            m = cm;
        }
    }
    return m;
}

int main(){
    int k;
    char s[100005];
    cin>>k;
    cin>>s;

    cout<<max(find(s,k,'a'),find(s,k,'b'));
}