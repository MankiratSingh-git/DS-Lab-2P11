#include<iostream>
using namespace std;

constexpr int max_arr_len = 100;
int arr[max_arr_len];   // max size of the array i will create during runtime..

int arrayDuplicate(int array[],int &size){
    // int count = 0;
    for (int i = 0 ; i<size ; i++){
        // int compare_data = array[i];
        for (int j = i+1 ; j<size ;){
            if(array[i] == array[j]){
                for (int k = j ; k<size-1 ; k++){
                    array[k] = array[k+1];

                }
                // array[j] = 0 ;
                size--;
                   // count++; counted the duplicate values..
            }
            else{
                j++;
            }
        }
        
    }

    return 0;

}
int main(){

    cout<<"What is size of array you want? (0-"<<max_arr_len<<")" <<endl;
    int arr_len;
    cin>>arr_len;
    for(int i = 0 ; i<arr_len ; i++){
        cout<<"Enter "<<i+1<<" element"<<endl;
        cin>>arr[i];
    }
    cout<<"array is successfully made"<<endl;

    cout<<"Now do you want find duplicate elements in same array and remove them? (Y/N)"<<endl;

    char choice;
    cin>>choice;

    if(choice == 'Y' || choice == 'y'){
        int result =arrayDuplicate(arr,arr_len);
        cout<<"removing duplicates...."<<endl;
        cout<<"Array after removing duplicates: "<<endl;
        for(int l = 0 ; l<arr_len ; l++){
            cout<<arr[l]<<endl;
        }
    }
        else{
            return 0 ;
    }

    
}