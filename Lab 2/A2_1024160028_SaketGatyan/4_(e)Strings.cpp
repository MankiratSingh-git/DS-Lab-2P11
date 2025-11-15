#include<iostream>
using namespace std;
int main(){
    string name = "SAKET";
    string ans="";
    int size = name.length();
    for(int i=0;i<size;i++){
        ans= ans+char(name[i]+32);
    }
    cout<<ans;
    return 0;
}