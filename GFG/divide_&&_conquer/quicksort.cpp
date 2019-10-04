#include<iostream>
using namespace std;
int partition(int a[],int low,int high){
    int i = low-1;
    for(int j=low;j<high;j++){
        if(a[j]<= a[high]){
            i++;
            swap(a[i],a[j]);
        }
    }

    swap(a[i+1],a[high]);

    return i+1;

}

void quickSort(int a[],int low,int high){
    if(high<=low){
        return;
    }

    int p = partition(a,low,high);

    quickSort(a,low,p-1);
    quickSort(a,p+1,high);
}
int main(){
    int arr[] = {10, 7, 8, 9, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout<<"Sorted array : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}