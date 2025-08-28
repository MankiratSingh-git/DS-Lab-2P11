#include<iostream>
using namespace std;

void caseswitch(string arr){
    for(int i=0;i<arr.length();i++){
        arr[i] += 32;
    }
    cout<<"The string after the case switch is : "<<arr<<endl;
}

int main(){
    string arr = "NAMANARORA";
    caseswitch(arr);
    return 0;
}