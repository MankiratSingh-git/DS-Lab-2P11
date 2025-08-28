#include<iostream>
#include<string>
using namespace std;


void vowelDeletion(string s)
{
    int n= s.length();
    string result="";
    for (int i=0;i<n;i++)
    {
        char ch= s[i];
        if( ch != 'a'&& ch != 'e'&& ch != 'i'&& ch != 'o'&& ch != 'u')
        {
            result+=ch;
        };
    }
    cout<<result;
}

int main()
{
    string str="cambridge";
    vowelDeletion(str);
}