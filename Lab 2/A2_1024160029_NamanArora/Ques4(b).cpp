#include <iostream>
using namespace std;

void reverse(string arr)
{
    string brr;
    int length = arr.length();
    for (int i = length - 1; i >= 0; i--)
    {
        brr += arr[i];
    }
    cout << "The Reverse of the string is : " << brr << endl;
}

int main()
{
    string arr = "America";
    reverse(arr);
    return 0;
}