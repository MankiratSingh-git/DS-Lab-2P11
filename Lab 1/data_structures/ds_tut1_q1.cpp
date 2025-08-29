#include <iostream>
using namespace std;

int create(int arr[], int n) {
    cout << "Creating array of size " << n << endl;
    for(int i = 0; i < n; i++) {
        cin>> arr[i]; 
    }
}

int display(int arr[], int n) {
    cout << "Displaying array elements: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int insert(int arr[], int n, int pos, int value) {
    int arr1[n+1];
    for(int i = 0; i < pos; i++) {
        arr1[i] = arr[i];
    }
    arr1[pos] = value; 
    for(int i = pos; i < n; i++) {
        arr1[i + 1] = arr[i];
    }

    for (int i = 0; i < n+1; i++)
    {
        cout<< arr1[i]<< " ";
    }
    cout << "inserted '100' at 2nd position "<< endl;
    
}

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >>n;
    int arr[n];
    cout << endl;
    cout << "MENU- \n1. CREATE\n2. DISPLAY\n3. INSERT\n4. LINEAR SEARCH\n5. Exit" << endl;

    create(arr, n);
    display(arr, n);
    insert(arr, n, 2, 100);   
    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    int index = linearSearch(arr, n, key); 
    if(index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }
    return 0;
}