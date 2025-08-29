#include <iostream>
using namespace std;

int mergeCount(int arr[], int temp[], int left, int mid, int right);
int sortCount(int arr[], int temp[], int left, int right);
int countInversions(int arr[], int n);

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << countInversions(arr, n) << endl;
    return 0;
}

int mergeCount(int arr[], int temp[], int left, int mid, int right){
    int i = left, j = mid, k = left, inv_count = 0;
    while(i <= mid - 1 && j <= right){
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else{
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }
    while(i <= mid - 1) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];
    for(i = left; i <= right; i++) arr[i] = temp[i];
    return inv_count;
}

int sortCount(int arr[], int temp[], int left, int right){
    int inv_count = 0;
    if(right > left){
        int mid = (left + right) / 2;
        inv_count += sortCount(arr, temp, left, mid);
        inv_count += sortCount(arr, temp, mid + 1, right);
        inv_count += mergeCount(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int countInversions(int arr[], int n){
    int temp[n];
    return sortCount(arr, temp, 0, n - 1);
}
