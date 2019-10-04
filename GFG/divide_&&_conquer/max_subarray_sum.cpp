#include<iostream>
#include<climits>
using namespace std;
int maxCrossing(int arr[],int l,int m,int h){
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}
int maxSubArraySum(int a[],int s,int e){
    if(s>=e){
        return 0;
    }

    int mid = (s+e)/2;

    int c1 = maxSubArraySum(a,s,mid);
    int c2 = maxSubArraySum(a,mid+1,e);
    int c = max(c1,c2);

    int c3 = maxCrossing(a,s,mid,e);
}
int main(){
    int arr[] = {2, 3, 4, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, 0, n - 1);
    printf("Maximum contiguous sum is %d", max_sum);
    return 0;
}