#include <iostream>
#include<algorithm>
#include<utility>
#define ll long long
using namespace std;
bool my(pair<int,int> a,pair<int,int> b){
    return a.second>b.second;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k,x;
	    cin>>n;
	    pair<int,int> p[n];
	    for(int i=0;i<n;i++){
	    	cin>>p[i].first;
	    }
	    cin>>k>>x;
	    for(int i=0;i<n;i++){
	    	p[i].second = (p[i].first ^ x) - p[i].first;
	    }
	    sort(p,p+n,my);
	    while(1){
	    	int d=0;
	    	for(int i=0;i<k;i++){
	    		d+=p[i].second;	
	    	}
	    	if(d>0){
	    		for(int i=0;i<k;i++){
	    			p[i].first = (p[i].first ^ x);
	    			p[i].second = (p[i].first ^ x) - p[i].first;
	    		}
	    		sort(p,p+n,my);
	    	}
	    	else{
	    		break;
	    	}
	    	ll s=0;
	    	for(int i=0;i<n;i++){
	    		s+=p[i].first;
	    	}
	    	cout<<s<<endl;
	    }
	}
	return 0;
}
