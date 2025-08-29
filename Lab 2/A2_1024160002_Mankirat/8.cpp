#include<iostream>
using namespace std;

int main(){
  int arr[] = {1, 2, 2, 3, 3, 3, 4};
  int n = sizeof(arr)/sizeof(arr[0]);
   int distinct_arr[n];
   int count = 0;

   for(int i = 0 ; i < n ; i++){
    bool duplicate = false;
    for(int j = 0 ; j < count ; j++){
      if(arr[i] == distinct_arr[j]){
        duplicate = true;
        break;
      }
    }
    if(!duplicate){
      distinct_arr[count] = arr[i];
      count++;
    }
   }
   cout << count << endl;
}