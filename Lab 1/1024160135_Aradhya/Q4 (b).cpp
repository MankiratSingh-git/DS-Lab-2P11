#include <iostream>
using namespace std;

int arr1[3][3], arr2[3][3];

//creating the first array
void create1(){
    cout<<"Enter 9 elements of the first array\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr1[i][j];
        }
    }
}

//displaying the first array
void display1(){
cout<<"Your first array is";
    for(int i=0;i<3;i++){
        cout<<endl;
        for(int j=0;j<3;j++){
            cout<<arr1[i][j]<<" ";
        }
    }
}

//creating the second array
void create2(){
    cout<<"Enter 9 elements of the second array\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr2[i][j];
        }
    }
}

//displaying the second array
void display2(){
cout<<"Your second array is";
    for(int i=0;i<3;i++){
        cout<<endl;
        for(int j=0;j<3;j++){
            cout<<arr2[i][j]<<" ";
        }
    }
}

int main() {
    int arr3[3][3];
    create1();
    display1();
    cout<<endl;
    create2();
    display2();
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            arr3[i][j]=0;
            for(int k=0;k<3;k++){
             arr3[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }
cout<<endl;    
    
cout<<"Your multiplied array is";
    for(int a=0;a<3;a++){
        cout<<endl;
        for(int b=0;b<3;b++){
            cout<<arr3[a][b]<<" ";
        }
    }
    return 0;
}
