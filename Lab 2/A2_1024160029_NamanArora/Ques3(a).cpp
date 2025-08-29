#include <iostream>
using namespace std;

int search(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    int n = 10;
    int arr[n] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11};
    int misingNumber = search(arr, n);
    cout << "The Missing number the array is : " << misingNumber << endl;
    return 0;
}