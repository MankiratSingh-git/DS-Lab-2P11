#include<iostream>
using namespace std;

void caseChange(char ch)
{

    if( ch>='A'&& ch<='Z')
    {
        ch+=32;
    }
    cout<<"the new character is :"<< ch;

}

int main()
{
    char a= 'A';
    caseChange(a);
}   