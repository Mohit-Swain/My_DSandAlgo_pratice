#include<iostream>
using namespace std;
int merge(int*,int,int,int,int*);
int _mergeSort(int*,int,int,int*);

int mergeSort(int arr[],int n){
    int temp[n];
    return _mergeSort(arr,0,n-1,temp);
}

int _mergeSort(int arr[],int low,int high,int temp[]){
    //base case
    if(low>=high){
        return 0;
    }
    int mid = (low+high)/2;
    int inv_count = 0;

    inv_count = _mergeSort(arr,low,mid,temp);
    inv_count += _mergeSort(arr,mid+1,high,temp);

    inv_count += merge(arr,low,mid+1,high,temp);

    return inv_count;
}

int merge(int a[],int low,int mid ,int high,int temp[]){
    int inv_count =0;

    int i = low;
    int j = mid;
    int k = low;

    while(i<=(mid-1) && (j<=high)){
        if(a[i]<=a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];

            inv_count += (mid - i);
        }
    }

    while(i<=(mid-1)){
        temp[k++] = a[i++];
    }

    while(j<=high){
        temp[k++] = a[j++];
    }

    return inv_count;
}
int main(){
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = mergeSort(arr, n);
    cout << " Number of inversions are " << ans;
    return 0;
}