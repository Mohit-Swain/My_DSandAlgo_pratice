#include<iostream>
#define uul long long int
using namespace std;
int main() {
    uul n;
    cin>>n;
    int a[100000000]={0},b[100000000]={0};
    

    uul c1=0,c2=0;
    for(uul  i=0;i<n;i++){
        uul x,y;
        cin>>x>>y;
        a[x]=1;b[y]=1;
        if(x>c1)
            c1=x;
        if(y>c2)
            c2=y;
    }
    uul c=0,x2=0,x1=0,mx=0;
    while(a[x2]!=1 && x2<=c1)
    {
        x2++;
    }
    mx=x2;
    for(;x2<=c1;){
        x1=x2++;
        while(a[x2]!=1 && x2<=c1){
            x2++;
        }
        if(mx > (x2-x1-1))
            mx = (x2-x1-1);
    }
    uul  y2=0,y1=0,my=0;
    while(b[y2]!=1 && y2<=c2){
        y2++;
    }
    my = y2;
    for(;y2<=c2;){
        y1=y2++;
        while(y2<=c2 && b[y2]!=1){
            y2++;
        }
        if(my>(y2-y1-1)){
            my = (y2-y1-1);
        }
    }
    cout<<mx*my;
    return 0;
}