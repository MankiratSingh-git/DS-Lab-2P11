#include <iostream>
using namespace std;

int arr[5], arr_rev[5];

//creating the array
void create(){
    cout<<"Enter 5 elements of the array\n";
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
}

void display(){
    cout<<"Your array is ";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void rev(){
    for (int j=0;j<5;j++){
        arr_rev[j]=arr[4-j];
    }
}

void display_new(){
    cout<<"Your reversed array is ";
    for(int i=0;i<5;i++){
        cout<<arr_rev[i]<<" ";
    }
}

int main() {
    create();
    display();
    rev();
    display_new();
    

    return 0;
}
