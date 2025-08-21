// Bubble Sort is the simplest sorting algorithm that works by
// repeatedly swapping the adjacent elements
// if they are in
// wrong order. Code the Bubble sort with the
// following elements:
// 64 34 25 12 22 11 90

#include <iostream>
using namespace std;

int main()
{

    int arr[7] = {64, 34, 25, 12, 22, 11, 90};
    int size = 7;
    cout<<endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    //      Bubble sort

    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        bool flag = false;
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = true;
            }
        }
        if (flag == false)
            break;
    }

    //      print the array

    cout << "\nThe array :\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;
    return 0;
}