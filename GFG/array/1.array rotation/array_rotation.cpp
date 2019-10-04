#include"iostream"
using namespace std;
void print_arr(int a[], int n);
int gcd(int a,int b){
    if(b==0)
        return a;
    else 
        return gcd(b,a%b);
}

void left_rot3(int arr[], int d, int n)     //by grouping it into gcd(n,d) sets.
{ 
    for (int i = 0; i < gcd(d, n); i++) { 

        int temp = arr[i]; 
        int j = i; 
  
        while (1) { 
            int k = j + d;      //where number of sets is equal to GCD of n and d 
                                //and move the elements within sets.
                                //NOTE : gcd(n,d) is not the no of elements in a set it's the no of set.
    /*If GCD is 1 as is for the above example array (n = 7 and d =2), 
    then elements will be moved within one set only,
    we just start with temp = arr[0] and keep moving arr[I+d] to arr[I] 
    and finally store temp at the right place.*/
            if (k >= n) 
                k = k - n; 
  
            if (k == i) 
                break; 
  
            arr[j] = arr[k]; 
            j = k; 
        } 
        arr[j] = temp;
    } 
} 

void left_rot2(int a[], int d, int n)   //with the help of temp variable
{ 
    for(int i = 0 ;i < d; i++){
        int t = a[0];

        for(int j = 0;j < n-1; j++){
            a[j] = a[j+1];
        }

        a[n-1] = t;
    }
} 

void left_rot1(int a[], int d, int n)   //with the help of temp array
{ 
    int *p = new int[d],i,j;
    for(i=0;i<d;i++){
        p[i] = a[i];
    }

    for(i=0;i<n-d;i++){
        a[i] = a[i+d];
    }

    for(j=0;j<d;j++,i++){   //see increament of two at a time
        a[i] = p[j];
    }

    delete p;
} 
void print_arr(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<",";
    }
}
int main(){
    int a[]={1, 2, 3, 4, 5, 6, 7},n=sizeof(a)/sizeof(a[0]),d=2;
    left_rot1(a,d,n);
    print_arr(a,n);
}