#include <iostream>
using namespace std;

int arr1[3][3];

//creating the array
void create1(){
    cout<<"Enter 9 elements of the array\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr1[i][j];
        }
    }
}

//displaying the array
void display1(){
cout<<"Your array is";
    for(int i=0;i<3;i++){
        cout<<endl;
        for(int j=0;j<3;j++){
            cout<<arr1[i][j]<<" ";
        }
    }
}


void display2(){
cout<<"Your transposed array is";
    for(int i=0;i<3;i++){
        cout<<endl;
        for(int j=0;j<3;j++){
            cout<<arr1[j][i]<<" ";
        }
    }
}

int main() {
    create1();
    display1();
    cout<<endl;
    display2();

    return 0;
}
