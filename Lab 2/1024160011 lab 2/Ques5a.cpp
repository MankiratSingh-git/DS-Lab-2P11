#include <iostream>

using namespace std;

int main(){
    int m,n,j,k,l,i;
    cout << "Enter the number of rows and columns for the matrix: ";
    cin >> n;
    int arr[n][n];
    cout << "Enter the elements of the matrix: " << endl;
    for (j = 0; j < n; j++) {
        for (k = 0; k < n; k++) {
            cout << "Element [" << j + 1 << "][" << k + 1 << "]: ";
            cin >> arr[j][k];
        }
    }
    cout << "The matrix is: " << endl;
    for (j = 0; j < n; j++) {
        for (k = 0; k < n; k++) {
            cout << arr[j][k] << " ";
        }
        cout << endl;
    }
    int arr1[k];
    for (i = 0; i < n; i++){
        for(j=0;j<n;j++){
            if(i==j){
                arr1[i]=arr[i][j];
            }
        }
    }
    cout << "The new array is ";
    for (i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }

    cout << endl;
    system("pause");
    return 0;
    

}