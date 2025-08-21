#include <iostream>
#include <vector>
using namespace std;

int create(vector<int> &arr)
{
    int size = -1;
    cout << "Enter elements , till -999 "
         << endl;
    int temp;
    for (int i = 0; temp != -999 && size < 100; i++)
    {
        cin >> temp;
        arr.push_back(temp); // adds element at the end
        size++;
    }
    return size;
}

void Delete(vector<int> &arr, int size, int location)
{
    for (int i = location - 1; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

void display(vector<int> &arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int size;
    vector<int> arr; // initially empty

    size = create(arr);

    int del=size;
    cout<<"Deleted ";
    for (int i = 0; i < size - 1; i++)
    {   
        int temp = arr[i];
        for (int j = i+1; j < size ; j++)
        {
            if (temp == arr[j]){

                Delete(arr, size, j+1);
                j--;
                size--;
            }
        }
    }

        cout<<"Deleted "<<del-size<<endl;
    
    display(arr,size);
    return 0;
}