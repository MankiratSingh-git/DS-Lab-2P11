#include <iostream>
using namespace std;

int main()
{
    int i, n, mid, low, high, find;
    cout << "Enter length of set :";
    cin >> n;
    int array1[n];
    cout << "Enter %d no.'s\n", n;
    for (i = 0; i < n; i++)
    {
        cin >> array1[i];
    }
    cout << "Enter Number to find : ";
    cin >> find;
    //     Binary search
    low = 0;
    high = n - 1;
    bool label = false;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array1[mid] == find)
        {
            cout << "The number " << find << " is at location " << mid + 1;
            label = true;
            break;
        }
        else if (find > array1[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << " \n";
    if (label == false)
        cout << "NOT found" << endl;
}