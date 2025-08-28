#include <iostream>
using namespace std;
constexpr int max_length = 100;
int arr[max_length];
int temp;

void make_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " element of your array" << endl;
        cin >> array[i];
    }
    cout << "array is made successfully" << endl;
}

void reverseArray(int array[], int size)
{
    
    for (int i = 0; i < size/2; i++)
    {
        temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
    cout << "Your array is reversed" << endl;
    for (int j = 0; j < size; j++)
    {
        cout << array[j] << endl;
    }
}

int main()
{
    cout << "Hello , Welcome to Reversing the Array Program" << endl;
    int size_array;
    cout << "What is the size of array you require?" << endl;
    cin >> size_array;
    if (size_array < 0 || size_array > 100)
    {
        cout << "Enter a valid size" << endl;
        return 0;
    }
    else
    {
        make_array(arr, size_array);
    }

    cout << "Do you want to reverse your array (Y/N)" << endl;
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {

        reverseArray(arr, size_array);
    }
    else
    {
        cout << "Thank you for visting us :)" << endl;
        return 0;
    }
}