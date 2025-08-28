/* 
Name: Bisman Singh Rai
Roll No: 1024160130
Program: Menu-driven program for Array Operations
*/

#include <iostream>
using namespace std;

int arr[100], n = 0;

// CREATE
void createArray() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
}

// DISPLAY
void displayArray() {
    if (n == 0) { cout << "Array is empty.\n"; return; }
    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

// INSERT
void insertElement() {
    if (n >= 100) { cout << "Array full.\n"; return; }
    int pos, val;
    cout << "Enter position: "; cin >> pos;
    if (pos < 1 || pos > n + 1) { cout << "Invalid.\n"; return; }
    cout << "Enter value: "; cin >> val;
    for (int i = n; i >= pos; i--) arr[i] = arr[i - 1];
    arr[pos - 1] = val; n++;
}

// DELETE
void deleteElement() {
    if (n == 0) { cout << "Empty.\n"; return; }
    int pos; cout << "Enter position: "; cin >> pos;
    if (pos < 1 || pos > n) { cout << "Invalid.\n"; return; }
    for (int i = pos - 1; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
}

// LINEAR SEARCH
void linearSearch() {
    if (n == 0) { cout << "Empty.\n"; return; }
    int key; cout << "Enter value: "; cin >> key;
    for (int i = 0; i < n; i++)
        if (arr[i] == key) { cout << "Found at position " << i + 1 << "\n"; return; }
    cout << "Not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- MENU ---\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cout << "Enter choice: "; cin >> choice;
        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);
}
