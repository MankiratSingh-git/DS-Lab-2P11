#include <iostream>
using namespace std;

void bubblesort(int arr[], int n)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "The sorted array is :-> " << endl;
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << "  ";
    }
}

int main()
{
    int n = 7;
    int arr[n] = {64, 34, 25, 12, 22, 11, 90};
    bubblesort(arr, n);
    return 0;
}