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

int main() {
   create1();
   display1();
   cout<<endl;
   cout<<endl;
   //summing the array rows
   int arr[3][1];
   for(int i=0;i<3;i++){
       for(int j=0;j<1;j++){
           arr[i][j]=0;
           for(int k=0;k<3;k++){
            arr[i][j]+=arr1[i][k];
           }
          cout<<"The sum of the "<<i+1<<" row is "<<arr[i][j];
          cout<<endl;
       }
   }
   cout<<endl;
    //summing the array columns
   int arr2[1][3];
   for(int i=0;i<1;i++){
       for(int j=0;j<3;j++){
           arr2[i][j]=0;
           for(int k=0;k<3;k++){
            arr2[i][j]+=arr1[k][j];
           }
          cout<<"The sum of the "<<j+1<<" column is "<<arr2[i][j];
          cout<<endl;
       }
   }

    return 0;
}
