#include <iostream>
using namespace std;

int arr[100], n = 0; // Array and current size

// Function to create array
void createArray() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Array created successfully!\n";
}

// Function to display array
void displayArray() {
    if (n == 0) {
        cout << "Array is empty!\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to insert element
void insertElement() {
    if (n == 100) {
        cout << "Array is full! Cannot insert.\n";
        return;
    }
    int pos, val;
    cout << "Enter position (0 to " << n << "): ";
    cin >> pos;
    if (pos < 0 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }
    cout << "Enter value: ";
    cin >> val;

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;
    cout << "Element inserted successfully!\n";
}

// Function to delete element
void deleteElement() {
    if (n == 0) {
        cout << "Array is empty! Cannot delete.\n";
        return;
    }
    int pos;
    cout << "Enter position (0 to " << n - 1 << "): ";
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted successfully!\n";
}

// Function for linear search
void linearSearch() {
    if (n == 0) {
        cout << "Array is empty!\n";
        return;
    }
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i << endl;
            return;
        }
    }
    cout << "Element not found!\n";
}

int main() {
    int choice;
    do {
        cout << "\n MENU\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: createArray(); break;
        case 2: displayArray(); break;
        case 3: insertElement(); break;
        case 4: deleteElement(); break;
        case 5: linearSearch(); break;
        case 6: cout << "Exiting program...\n"; break;
        default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
