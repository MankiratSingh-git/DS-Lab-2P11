#include <iostream>
using namespace std;

int search(int arr[], int n)
{
    int l = 0;
    int h = n - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] == mid + 1)
        {
            l = mid + 1;
        }
        if (arr[mid] > mid + 1)
        {
            h = mid - 1;
        }
    }
    return l + 1;
}

int main()
{
    int n = 10;
    int arr[n] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11};
    int misingNumber = search(arr, n);
    cout << "The Missing number the array is : " << misingNumber << endl;
    return 0;
}