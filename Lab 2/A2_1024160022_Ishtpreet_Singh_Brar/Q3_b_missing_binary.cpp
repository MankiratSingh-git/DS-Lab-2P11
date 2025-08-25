#include <iostream>
using namespace std;

int main()
{
    int mid, low, high;
    int array1[] = {1, 3, 5, 7, 8, 10, 15};
    int n = sizeof(array1) / sizeof(array1[0]);
    int last=array1[n-1];
    
    cout<<endl;
    cout << "Missing nums :" << endl;
    
    for (int j=0; j < last;j++)
    {
        int find =j+1;

    //     Binary search
    {
        low = 0;
        high = n - 1;
        bool label = false;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (array1[mid] == find)
            {
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
        if (label == false)
            cout << find<< " ";
        
    }}

    cout<<endl;
    cout<<endl;
}