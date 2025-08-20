#include<iostream>
#include<string>
using namespace std;

int main()
{
    string A1="cambridge";
    int n= A1.length();

    for(int i=0;i<n/2;i++)
    {
       int temp= A1[i];
       A1[i]=A1[n-1-i];
       A1[n-1-i]=temp;

    }
    cout<< A1;
}