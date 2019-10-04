#include <bits/stdc++.h> 
using namespace std;

// Returns minimum number of jumps  
// to reach arr[h] from arr[l] 
int minJumps(int arr[], int l, int h) 
{ 
      
// Base case: when source and  
// destination are same 
if (h == l) 
    return 0; 
  
// When nothing is reachable from  
// the given source 
if (arr[l] == 0) 
    return -1; 
  
// Traverse through all the points  
// reachable from arr[l]. Recursively  
// get the minimum number of jumps  
// needed to reach arr[h] from these 
// reachable points. 
int min = INT_MAX; 
for (int i = l + 1; i <= h && 
         i <= l + arr[l]; i++) 
{ 
    int jumps = minJumps(arr, i, h); 
    if(jumps != -1 && jumps + 1 < min) 
        min = jumps + 1; 	//+1 to include this jump also.
} 
  
return min; 
} 


int main() 
{ 
    int arr[] = {1, 3, 6, 3, 2,  
                 3, 6, 8, 9, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Minimum number of jumps to reach end is " 
         << minJumps(arr, 0, n-1); 
    return 0; 
} 

int minimumJumps(int a[],int l,int h){
	if(l==h)
		return 0;

	if(a[l]==0)
		return -1;

	int min = INT_MAX;
	for(int i=l+1;i<=l+a[l] && i<=h;i++){
		int jumps = min(a,i,h);		//include the jump made here
		if(jumps + 1< min && jumps != -1){
			min = jumps+1;
		}
	}
	return min;
}