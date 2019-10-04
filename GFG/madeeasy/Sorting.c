#include<stdio.h>
//Sorting is an algorithm that arranges the elements of a list in a particular order.
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void print(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
//linear sort
void linearRec(int a[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
            }
        }
    }
}
//Bubble sort (wrost case = O(n^2),best case = O(n^2),stable)
void bubbleRec(int a[],int n){
    int i,j;
    for(i = n-1;i>0;i--){
        for(j=0;j<i;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
            }
        }
    }
}
//Modified Bubble  sort (wc = O(n^2) , bc = O(n))
void modBubbleRec(int a[],int n){
    int i,j,flag;
    for(i=n-1;i>0;i--){
        flag=1;
        for(j=0;j<i;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                flag=0;
            }
        }
        if(flag==1){
            break;
        }
    }
}

//selection sort (wc/bc = O(n^2))
void selectionRec(int a[],int n){
    int i,j,smallIdx;
    for(i=0;i<n-1;i++){
        smallIdx = i;
        for(j = i+1;j<n;j++){
            if(a[j]<a[smallIdx]){
                smallIdx = j;
            }
        } 
        swap(&a[i],&a[smallIdx]);
    }
}
//Insertion sort (stable,adaptive, wc = O(n^2),bc = O(n), space = O(n^2));
void insertionRec(int a[],int n){
    int i,j,v;
    for(i=1;i<n;i++){
        v = a[i];
        for(j=i-1;j>=0 && (a[j]>v);j--){
            a[j+1] = a[j];
        }
        a[j+1]=v;
    }
}
//ShellSort (wc=O(n^2) bc=O(nlog^2(n)) depends on the way you change the gap)
void shellRec(int a[],int n){
    int gap,i,j,temp;
    for(gap = n/2 ;gap>0 ;gap=gap/2){
        for(i=gap;i<n;i++){
            temp = a[i];
            for(j=i-gap;j>=0 && a[j]>temp;j-=gap){
                a[j+gap] = a[j];
             }
            a[j+gap] = temp;
        }
    }
}
//MergeSort (wc/bc = O( nlog(n) ) , stable)
void merge(int a[],int s,int m,int e){
    int n = e-s+1;
    int temp[n];
    int i=s,j=m+1,k=0;
    while(i<=m && j<=e){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
        }
    }

    while(i<=m){
        temp[k++]=a[i++];
    }
    while(j<=e){
        temp[k++]=a[j++];
    }
    for(i=0;i<n;i++){
        a[s+i]=temp[i];
    }
}
void mergeSortHelper(int a[],int s,int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergeSortHelper(a,s,mid);
    mergeSortHelper(a,mid+1,e);
    merge(a,s,mid,e);
}
void mergeSort(int a[],int n){
    mergeSortHelper(a,0,n-1);
}
//QuickSort (wc = O(n^2),bc = O(nlog(n)) ,unstable)
int Partition(int a[],int s,int e){
    int pivot = a[s];
    int i,c=s-1;
    for(i=s;i<=e;i++){
        if(a[i]<=pivot){
            c++;
            swap(&a[c],&a[i]);
        }
    }
    
    swap(&a[s],&a[c]);
    return c;
}
void QuickSortHelper(int a[],int s,int e){
    if(s>=e){
        return;
    }
    //start is the pivot
    int p = Partition(a,s,e);
    QuickSortHelper(a,s,p-1);
    QuickSortHelper(a,p+1,e);
}
void QuickSort(int a[],int n){
    QuickSortHelper(a,0,n-1);
}
//Counting sort O(n)
void CountingSortGFG(int a[],int n){
    int i,count[8],out[n];
    for(int i=0;i<8;i++){
        count[i]=0;
    }
    for(i=0;i<n;i++){
        count[a[i]]++;
    }

    for(i=1;i<8;i++){
        count[i]=count[i]+count[i-1];
    }

    for(i=0;i<n;i++){
        out[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }
    for(i=0;i<n;i++){
        a[i] = out[i];
    }
}

void bucketSort(float arr[], int n)
{
    // 1) Create n empty buckets
    vector<float> b[n];

    // 2) Put array elements in different buckets
    for (int i = 0; i < n; i++)
    {
        int bi = n * arr[i]; // Index in bucket
        b[bi].push_back(arr[i]);
    }

    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

int main(){
    int arr[7] = {7,6,5,4,3,2,1};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    //linearRec(arr,n);
    //bubbleRec(arr,n);
    //selectionRec(arr,n);
    //insertionRec(arr,n);
    //shellRec(arr,n);
    //mergeSort(arr,n);
    //QuickSort(arr,n);
    CountingSortGFG(arr,n);
    print(arr,n);
    return 0;
}