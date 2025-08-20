// Q1
// Develop a Menu driven program to demonstrate the following operations of Arrays
// ——MENU——-
// 1.CREATE
// 2. DISPLAY
// 3. INSERT
// 4. DELETE
// 5. LINEAR SEARCH
// 6. EXIT

#include <iostream>
using namespace std;

const int MAX = 100;
int arr[MAX], n = 0; // n = current number of elements

void createArray() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void displayArray() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertElement() {
    int pos, val;
    cout << "Enter position (0-based index): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> val;

    if (pos < 0 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }

    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
}

void deleteElement() {
    int pos;
    cout << "Enter position to delete (0-based index): ";
    cin >> pos;

    if (pos < 0 || pos >= n) {
        cout << "Invalid position!\n";
        return;
    }

    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

void linearSearch() {
    int key, found = 0;
    cout << "Enter element to search: ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i << endl;
            found = 1;
            break;
        }
    }
    if (!found)
        cout << "Element not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

// Q2
// Design the logic to remove the duplicate elements from an Array and after the deletion the array should contain the unique elements

#include <iostream>
using namespace std;

int main() {
    int arr[100], n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; k++)
                    arr[k] = arr[k + 1];
                n--;
            } else {
                j++;
            }
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

//Q3
// Predict the Output of the following program

#include <iostream>
using namespace std;

int main() {
    int i;
    int arr[5] = {1}; // First element = 1, rest automatically = 0
    for (i = 0; i < 5; i++)
        cout << arr[i];
    return 0;
}
//Q4
// Implement the logic to
// a. Reverse the elements of an array

#include <iostream>
using namespace std;

int main() {
    int arr[100], n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n / 2; i++)
        swap(arr[i], arr[n - i - 1]);

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}


// b. Find the matrix multiplication


int main() {
    int a[10][10], b[10][10], c[10][10], r1, c1, r2, c2;
    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible!\n";
        return 0;
    }

    cout << "Enter first matrix:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> a[i][j];

    cout << "Enter second matrix:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> b[i][j];

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }

    cout << "Resultant matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
}

// c. Find the Transpose of a Matrix



int main() {
    int a[10][10], trans[10][10], r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            trans[j][i] = a[i][j];

    cout << "Transpose of matrix:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++)
            cout << trans[i][j] << " ";
        cout << endl;
    }
}

//Q5
// Write a program to find sum of every row and every column in a two-dimensional array.

#include <iostream>
using namespace std;

int main() {
    int a[10][10], r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    for (int i = 0; i < r; i++) {
        int rowSum = 0;
        for (int j = 0; j < c; j++)
            rowSum += a[i][j];
        cout << "Sum of row " << i + 1 << ": " << rowSum << endl;
    }

    for (int j = 0; j < c; j++) {
        int colSum = 0;
        for (int i = 0; i < r; i++)
            colSum += a[i][j];
        cout << "Sum of column " << j + 1 << ": " << colSum << endl;
    }
}



