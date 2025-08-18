#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 100;


// Solves Question 1
void menuDrivenArrayOperations();
void create(int arr[], int& size);
void display(const int arr[], int size);
void insert(int arr[], int& size);
void deleteElement(int arr[], int& size);
void linearSearch(const int arr[], int size);

// Solves Question 2
void removeDuplicates();

// Solves Question 4a
void reverseArray();

// Solves Question 4b
void matrixMultiplication();

// Solves Question 4c
void transposeMatrix();

// Solves Question 5
void sumRowsAndColumns();

// Helper functions for matrix input/output
void getMatrixInput(int matrix[][MAX_SIZE], int& rows, int& cols, const string& matrixName);
void displayMatrix(const int matrix[][MAX_SIZE], int rows, int cols);


// Main Function 

int main() {
     int choice;
     do {
          cout << "\n\n--- UCS301 DATA STRUCTURES: LAB ASSIGNMENT 1 ---";
          cout << "\nSelect the program you want to run:";
          cout << "\n\n1. Menu-Driven Array Operations (Question 1)";
          cout << "\n2. Remove Duplicates from an Array (Question 2)";
          cout << "\n3. Predict the Output (Question 3)";
          cout << "\n4. Reverse Array Elements (Question 4a)";
          cout << "\n5. Matrix Multiplication (Question 4b)";
          cout << "\n6. Transpose of a Matrix (Question 4c)";
          cout << "\n7. Sum of Rows and Columns of a Matrix (Question 5)";
          cout << "\n8. Exit";
          cout << "\nEnter your choice: ";
          cin >> choice;

          switch (choice) {
               case 1:
                    menuDrivenArrayOperations();
                    break;
               case 2:
                    removeDuplicates();
                    break;
               case 3:
                    cout << "\n--- Question 3: Predict the Output ---" << endl;
                    cout << "C Code Snippet:" << endl;
                    cout << "int main() {" << endl;
                    cout << "    int i;" << endl;
                    cout << "    int arr[5] = {1};" << endl;
                    cout << "    for (i = 0; i < 5; i++)" << endl;
                    cout << "        printf(\"%d\", arr[i]);" << endl;
                    cout << "    return 0;" << endl;
                    cout << "}" << endl;
                    cout << "\nPredicted Output: 10000" << endl;
                    cout << "\nReasoning: When a C-style array is partially initialized, the compiler automatically initializes all remaining elements to zero. Here, arr[0] is set to 1, and arr[1] through arr[4] become 0. The loop prints these elements without any spaces, resulting in '10000'." << endl;
                    break;
               case 4:
                    reverseArray();
                    break;
               case 5:
                    matrixMultiplication();
                    break;
               case 6:
                    transposeMatrix();
                    break;
               case 7:
                    sumRowsAndColumns();
                    break;
               case 8:
                    cout << "Exiting program. Goodbye!" << endl;
                    break;
               default:
                    cout << "Invalid choice. Please try again." << endl;
          }
     } while (choice != 8);

     return 0;
}

// Question 1

void menuDrivenArrayOperations() {
     int arr[MAX_SIZE];
     int size = 0;
     int choice;

     do {
          cout << "\n\n--- Array Operations MENU ---";
          cout << "\n1. CREATE";
          cout << "\n2. DISPLAY";
          cout << "\n3. INSERT";
          cout << "\n4. DELETE";
          cout << "\n5. LINEAR SEARCH";
          cout << "\n6. EXIT to Main Menu";
          cout << "\n---------------------------";
          cout << "\nEnter your choice: ";
          cin >> choice;

          switch (choice) {
               case 1:
                    create(arr, size);
                    break;
               case 2:
                    display(arr, size);
                    break;
               case 3:
                    insert(arr, size);
                    break;
               case 4:
                    deleteElement(arr, size);
                    break;
               case 5:
                    linearSearch(arr, size);
                    break;
               case 6:
                    cout << "Returning to main menu..." << endl;
                    break;
               default:
                    cout << "Invalid choice. Please try again." << endl;
          }
     } while (choice != 6);
}

void create(int arr[], int& size) {
     cout << "Enter the number of elements for the array (max " << MAX_SIZE << "): ";
     cin >> size;
     if (size > MAX_SIZE || size < 0) {
          cout << "Invalid size. Setting size to 0." << endl;
          size = 0;
          return;
     }
     cout << "Enter " << size << " elements:" << endl;
     for (int i = 0; i < size; ++i) {
          cin >> arr[i];
     }
     cout << "Array created successfully." << endl;
}

void display(const int arr[], int size) {
     if (size == 0) {
          cout << "Array is empty." << endl;
          return;
     }
     cout << "Array elements: ";
     for (int i = 0; i < size; ++i) {
          cout << arr[i] << " ";
     }
     cout << endl;
}

void insert(int arr[], int& size) {
     if (size >= MAX_SIZE) {
          cout << "Array is full. Cannot insert." << endl;
          return;
     }
     int pos, value;
     cout << "Enter position (1 to " << size + 1 << ") to insert: ";
     cin >> pos;
     cout << "Enter value to insert: ";
     cin >> value;

     if (pos < 1 || pos > size + 1) {
          cout << "Invalid position." << endl;
          return;
     }

     for (int i = size; i >= pos; --i) {
          arr[i] = arr[i - 1];
     }
     arr[pos - 1] = value;
     size++;
     cout << "Element inserted successfully." << endl;
}

void deleteElement(int arr[], int& size) {
     if (size == 0) {
          cout << "Array is empty. Cannot delete." << endl;
          return;
     }
     int pos;
     cout << "Enter position (1 to " << size << ") to delete: ";
     cin >> pos;

     if (pos < 1 || pos > size) {
          cout << "Invalid position." << endl;
          return;
     }

     for (int i = pos - 1; i < size - 1; ++i) {
          arr[i] = arr[i + 1];
     }
     size--;
     cout << "Element deleted successfully." << endl;
}

void linearSearch(const int arr[], int size) {
     if (size == 0) {
          cout << "Array is empty." << endl;
          return;
     }
     int value;
     cout << "Enter element to search for: ";
     cin >> value;

     for (int i = 0; i < size; ++i) {
          if (arr[i] == value) {
               cout << "Element " << value << " found at position " << i + 1 << "." << endl;
               return;
          }
     }
     cout << "Element " << value << " not found in the array." << endl;
}


// Question 2

void removeDuplicates() {
     int arr[MAX_SIZE];
     int size;

     cout << "\n--- Remove Duplicates from Array ---" << endl;
     cout << "Enter the number of elements for the array (max " << MAX_SIZE << "): ";
     cin >> size;
          if (size > MAX_SIZE || size < 0) {
          cout << "Invalid size. Aborting." << endl;
          return;
     }
     cout << "Enter " << size << " elements:" << endl;
     for (int i = 0; i < size; ++i) {
          cin >> arr[i];
     }
     
     cout << "Original array: ";
     display(arr, size);

     int newSize = 0;
     for (int i = 0; i < size; i++) {
          bool isDuplicate = false;
          for (int j = 0; j < newSize; j++) {
               if (arr[i] == arr[j]) {
                    isDuplicate = true;
                    break;
               }
          }
          if (!isDuplicate) {
               arr[newSize] = arr[i];
               newSize++;
          }
     }
     size = newSize;

     cout << "Array after removing duplicates: ";
     display(arr, size);
}

// Question 4

void reverseArray() {
    int arr[MAX_SIZE];
    int size;

    cout << "\n--- Reverse Array Elements ---" << endl;
    cout << "Enter the number of elements for the array (max " << MAX_SIZE << "): ";
    cin >> size;
     if (size > MAX_SIZE || size < 0) {
        cout << "Invalid size. Aborting." << endl;
        return;
    }
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    display(arr, size);

    int start = 0;
    int end = size - 1;
    while (start < end) {
        // Swap elements
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    cout << "Reversed array: ";
    display(arr, size);
}

void matrixMultiplication() {
     int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
     int r1, c1, r2, c2;

     cout << "\n--- Matrix Multiplication ---" << endl;
     getMatrixInput(mat1, r1, c1, "first");
     getMatrixInput(mat2, r2, c2, "second");

     if (c1 != r2) {
          cout << "Matrix multiplication not possible. Columns of first matrix must equal rows of second matrix." << endl;
          return;
     }

     for (int i = 0; i < r1; ++i) {
          for (int j = 0; j < c2; ++j) {
               result[i][j] = 0;
          }
     }

     for (int i = 0; i < r1; ++i) {
          for (int j = 0; j < c2; ++j) {
               for (int k = 0; k < c1; ++k) {
                    result[i][j] += mat1[i][k] * mat2[k][j];
               }
          }
     }

     cout << "\nResultant Matrix:" << endl;
     displayMatrix(result, r1, c2);
     }

void transposeMatrix() {
     int matrix[MAX_SIZE][MAX_SIZE], transpose[MAX_SIZE][MAX_SIZE];
     int rows, cols;
     
     cout << "\n--- Transpose of a Matrix ---" << endl;
     getMatrixInput(matrix, rows, cols, "source");

     for (int i = 0; i < rows; ++i) {
          for (int j = 0; j < cols; ++j) {
               transpose[j][i] = matrix[i][j];
          }
     }
     
     cout << "\nOriginal Matrix:" << endl;
     displayMatrix(matrix, rows, cols);

     cout << "\nTransposed Matrix:" << endl;

     displayMatrix(transpose, cols, rows);
}


// Question 5

void sumRowsAndColumns() {
     int matrix[MAX_SIZE][MAX_SIZE];
     int rows, cols;

     cout << "\n--- Sum of Rows and Columns ---" << endl;
     getMatrixInput(matrix, rows, cols, "");

     cout << "\nEntered Matrix:" << endl;
     displayMatrix(matrix, rows, cols);

     cout << "\nSum of every row:" << endl;
     for (int i = 0; i < rows; i++) {
          int rowSum = 0;
          for (int j = 0; j < cols; j++) {
               rowSum += matrix[i][j];
          }
          cout << "Sum of row " << i + 1 << ": " << rowSum << endl;
     }

     cout << "\nSum of every column:" << endl;
     for (int j = 0; j < cols; j++) {
          int colSum = 0;
          for (int i = 0; i < rows; i++) {
               colSum += matrix[i][j];
          }
          cout << "Sum of column " << j + 1 << ": " << colSum << endl;
     }
}

// Helper Functions for Matrix Operations 

void getMatrixInput(int matrix[][MAX_SIZE], int& rows, int& cols, const string& matrixName) {
     cout << "\nEnter details for the " << matrixName << " matrix:" << endl;
     cout << "Enter number of rows: ";
     cin >> rows;
     cout << "Enter number of columns: ";
     cin >> cols;

     if (rows > MAX_SIZE || cols > MAX_SIZE || rows <=0 || cols <=0) {
          cout << "Invalid dimensions. Aborting." << endl;
          rows = 0; cols = 0;
          return;
     }

     cout << "Enter the " << rows * cols << " elements:" << endl;
     for (int i = 0; i < rows; ++i) {
          for (int j = 0; j < cols; ++j) {
               cin >> matrix[i][j];
          }
     }
}

void displayMatrix(const int matrix[][MAX_SIZE], int rows, int cols) {
     for (int i = 0; i < rows; ++i) {
          for (int j = 0; j < cols; ++j) {
               cout << matrix[i][j] << "\t";
          }
          cout << endl;
     }
}