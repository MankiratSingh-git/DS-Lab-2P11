//Q1
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int key) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    std::vector<int> data = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    
    int target1 = 23;
    int target2 = 15;

    int result1 = binarySearch(data, target1);

    if (result1 != -1) {
        std::cout << "Element " << target1 << " found at index: " << result1 << std::endl;
    } else {
        std::cout << "Element " << target1 << " not found." << std::endl;
    }

    int result2 = binarySearch(data, target2);

    if (result2 != -1) {
        std::cout << "Element " << target2 << " found at index: " << result2 << std::endl;
    } else {
        std::cout << "Element " << target2 << " not found." << std::endl;
    }

    return 0;
}



//Q2


#include <iostream>
#include <vector>
#include <utility>

void printArray(const std::vector<int>& arr) {
    for (int element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }

        std::cout << "After pass " << i + 1 << ": ";
        printArray(arr);
    }
}

int main() {
    std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Original array: ";
    printArray(numbers);
    std::cout << "---------------------------------" << std::endl;

    bubbleSort(numbers);

    std::cout << "---------------------------------" << std::endl;
    std::cout << "Final sorted array: ";
    printArray(numbers);

    return 0;
}


//Q3


#include <iostream>
#include <vector>


int findMissingLinear(const std::vector<int>& arr) {
    int n = arr.size() + 1; 
    for (int i = 0; i < arr.size(); ++i) {
       
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
   
    return n;
}

int findMissingBinary(const std::vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;
    int missingNumber = arr.size() + 1; 

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == mid + 1) {
            low = mid + 1;
        } 
     
        else {
            missingNumber = mid + 1;
            high = mid - 1;
        }
    }
    return missingNumber;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 6, 7, 8, 9, 10};

    std::cout << "Array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;

    int missing1 = findMissingLinear(numbers);
    std::cout << "Using Linear Search (O(n)): " << std::endl;
    std::cout << "The missing number is: " << missing1 << std::endl;

    std::cout << "---------------------------------" << std::endl;

  
    int missing2 = findMissingBinary(numbers);
    std::cout << "Using Binary Search (O(log n)): " << std::endl;
    std::cout << "The missing number is: " << missing2 << std::endl;

    return 0;
}


//Q4
//(A)
#include <iostream>
#include <string>

int main() {
    std::string firstName = "John";
    std::string lastName = " Doe";
    std::string fullName_method1 = firstName + lastName;

    std::cout << "Method 1 (+ operator):" << std::endl;
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Full Name: " << fullName_method1 << std::endl;

    std::cout << "\n---------------------------------\n" << std::endl;

    std::string part1 = "Hello, ";
    std::string part2 = "World!";
    std::string message = part1; 
    message.append(part2);

    std::cout << "Method 2 (.append()):" << std::endl;
    std::cout << "Part 1: " << part1 << std::endl;
    std::cout << "Part 2: " << part2 << std::endl;
    std::cout << "Combined Message: " << message << std::endl;

    return 0;
}
//(B)
int main() {
    std::string text = "Hello World";

    std::cout << "Original string: " << text << std::endl;
    std::cout << "\n---------------------------------\n" << std::endl;

    // --- Method 1: Using std::reverse (The easy way) ---
    std::string text_to_reverse1 = text; // Make a copy
    std::reverse(text_to_reverse1.begin(), text_to_reverse1.end());

    std::cout << "Method 1 (std::reverse):" << std::endl;
    std::cout << "Reversed string: " << text_to_reverse1 << std::endl;

    std::cout << "\n---------------------------------\n" << std::endl;

    // --- Method 2: Manual swap with two pointers ---
    std::string text_to_reverse2 = text; // Make another copy
    int left = 0;
    int right = text_to_reverse2.length() - 1;

    while (left < right) {
        std::swap(text_to_reverse2[left], text_to_reverse2[right]);
        left++;
        right--;
    }

    std::cout << "Method 2 (Manual Swap):" << std::endl;
    std::cout << "Reversed string: " << text_to_reverse2 << std::endl;

    return 0;
}
//(C)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

// (c) Function to delete vowels from a string
void deleteVowels() {
    std::cout << "(c) Deleting vowels from a string:" << std::endl;
    std::string text = "This is a sample sentence.";
    std::string result = "";

    std::cout << "Original: " << text << std::endl;

    for (char c : text) {
        char lower_c = std::tolower(c);
        if (lower_c != 'a' && lower_c != 'e' && lower_c != 'i' && lower_c != 'o' && lower_c != 'u') {
            result += c;
        }
    }
    std::cout << "Without Vowels: " << result << std::endl;
}

// (d) Function to sort strings alphabetically
void sortStrings() {
    std::cout << "\n(d) Sorting strings in alphabetical order:" << std::endl;
    std::vector<std::string> fruits = {"Banana", "Apple", "Cherry", "Date"};

    std::cout << "Original order: ";
    for (const std::string& fruit : fruits) {
        std::cout << fruit << " ";
    }
    std::cout << std::endl;

    std::sort(fruits.begin(), fruits.end());

    std::cout << "Sorted order:   ";
    for (const std::string& fruit : fruits) {
        std::cout << fruit << " ";
    }
    std::cout << std::endl;
}

// (e) Function to convert uppercase to lowercase
void convertCase() {
    std::cout << "\n(e) Converting a character from uppercase to lowercase:" << std::endl;
    char upperChar = 'Q';
    std::cout << "Original character: " << upperChar << std::endl;

    char lowerChar = std::tolower(upperChar);
    std::cout << "Lowercase character: " << lowerChar << std::endl;
}


int main() {
    deleteVowels();
    std::cout << "---------------------------------" << std::endl;
    sortStrings();
    std::cout << "---------------------------------" << std::endl;
    convertCase();

    return 0;
}

//5 

#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int key) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    std::vector<int> data = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    
    int target1 = 23;
    int target2 = 15;

    int result1 = binarySearch(data, target1);

    if (result1 != -1) {
        std::cout << "Element " << target1 << " found at index: " << result1 << std::endl;
    } else {
        std::cout << "Element " << target1 << " not found." << std::endl;
    }

    int result2 = binarySearch(data, target2);

    if (result2 != -1) {
        std::cout << "Element " << target2 << " found at index: " << result2 << std::endl;
    } else {
        std::cout << "Element " << target2 << " not found." << std::endl;
    }

    return 0;
}

//6
#include <iostream>
#include <vector>
#include <algorithm>

struct Triplet {
    int row;
    int col;
    int value;
};

class SparseMatrix {
public:
    int rows;
    int cols;
    std::vector<Triplet> elements;

    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    void addElement(int r, int c, int val) {
        if (val != 0) {
            elements.push_back({r, c, val});
        }
    }

    void display() const {
        int k = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (k < elements.size() && elements[k].row == i && elements[k].col == j) {
                    std::cout << elements[k++].value << "\t";
                } else {
                    std::cout << "0\t";
                }
            }
            std::cout << std::endl;
        }
    }
};

// (a) Transpose of a matrix
SparseMatrix transpose(const SparseMatrix& A) {
    SparseMatrix B(A.cols, A.rows);
    B.elements.resize(A.elements.size());

    for (size_t i = 0; i < A.elements.size(); ++i) {
        B.elements[i].row = A.elements[i].col;
        B.elements[i].col = A.elements[i].row;
        B.elements[i].value = A.elements[i].value;
    }

    std::sort(B.elements.begin(), B.elements.end(), [](const Triplet& a, const Triplet& b) {
        if (a.row != b.row) return a.row < b.row;
        return a.col < b.col;
    });

    return B;
}

// (b) Addition of two matrices
SparseMatrix add(const SparseMatrix& A, const SparseMatrix& B) {
    if (A.rows != B.rows || A.cols != B.cols) {
        return SparseMatrix(0, 0); 
    }

    SparseMatrix C(A.rows, A.cols);
    size_t i = 0, j = 0;

    while (i < A.elements.size() && j < B.elements.size()) {
        if (A.elements[i].row < B.elements[j].row || (A.elements[i].row == B.elements[j].row && A.elements[i].col < B.elements[j].col)) {
            C.elements.push_back(A.elements[i++]);
        } else if (B.elements[j].row < A.elements[i].row || (B.elements[j].row == A.elements[i].row && B.elements[j].col < A.elements[i].col)) {
            C.elements.push_back(B.elements[j++]);
        } else {
            int sum = A.elements[i].value + B.elements[j].value;
            if (sum != 0) {
                C.addElement(A.elements[i].row, A.elements[i].col, sum);
            }
            i++;
            j++;
        }
    }

    while (i < A.elements.size()) C.elements.push_back(A.elements[i++]);
    while (j < B.elements.size()) C.elements.push_back(B.elements[j++]);

    return C;
}

// (c) Multiplication of two matrices
SparseMatrix multiply(const SparseMatrix& A, const SparseMatrix& B) {
    if (A.cols != B.rows) {
        return SparseMatrix(0, 0);
    }

    SparseMatrix C(A.rows, B.cols);
    SparseMatrix B_T = transpose(B);
    
    for (size_t i = 0; i < A.elements.size(); ) {
        for (size_t j = 0; j < B_T.elements.size(); ) {
            
            int current_A_row = A.elements[i].row;
            int current_BT_row = B_T.elements[j].row;

            int sum = 0;
            size_t temp_i = i;
            size_t temp_j = j;

            while (temp_i < A.elements.size() && A.elements[temp_i].row == current_A_row &&
                   temp_j < B_T.elements.size() && B_T.elements[temp_j].row == current_BT_row) {
                
                if (A.elements[temp_i].col < B_T.elements[temp_j].col) {
                    temp_i++;
                } else if (B_T.elements[temp_j].col < A.elements[temp_i].col) {
                    temp_j++;
                } else {
                    sum += A.elements[temp_i].value * B_T.elements[temp_j].value;
                    temp_i++;
                    temp_j++;
                }
            }
            
            if (sum != 0) {
                C.addElement(current_A_row, current_BT_row, sum);
            }

            size_t next_j = j;
            while(next_j < B_T.elements.size() && B_T.elements[next_j].row == current_BT_row) next_j++;
            if(next_j == B_T.elements.size()) {
                size_t next_i = i;
                while(next_i < A.elements.size() && A.elements[next_i].row == current_A_row) next_i++;
                i = next_i;
                j = 0;
            } else {
                j = next_j;
            }
        }
    }
     std::sort(C.elements.begin(), C.elements.end(), [](const Triplet& a, const Triplet& b) {
        if (a.row != b.row) return a.row < b.row;
        return a.col < b.col;
    });
    return C;
}

int main() {
    SparseMatrix A(4, 5);
    A.addElement(0, 2, 3);
    A.addElement(0, 4, 4);
    A.addElement(1, 2, 5);
    A.addElement(1, 3, 7);
    A.addElement(2, 1, 2);
    A.addElement(3, 0, 9);

    SparseMatrix B(4, 5);
    B.addElement(0, 1, 1);
    B.addElement(1, 2, 3);
    B.addElement(1, 3, 4);
    B.addElement(2, 1, 5);
    B.addElement(3, 4, 2);
    
    std::cout << "(a) Transpose of a Matrix" << std::endl;
    std::cout << "Original Matrix A:" << std::endl;
    A.display();
    std::cout << "\nTranspose of A:" << std::endl;
    SparseMatrix A_T = transpose(A);
    A_T.display();
    std::cout << "\n---------------------------------\n" << std::endl;

    std::cout << "(b) Addition of two Matrices" << std::endl;
    std::cout << "Matrix A:" << std::endl;
    A.display();
    std::cout << "\nMatrix B:" << std::endl;
    B.display();
    std::cout << "\nSum of A and B:" << std::endl;
    SparseMatrix C_add = add(A, B);
    C_add.display();
    std::cout << "\n---------------------------------\n" << std::endl;

    SparseMatrix M1(3, 4);
    M1.addElement(0, 0, 1);
    M1.addElement(0, 3, 5);
    M1.addElement(1, 1, 2);
    M1.addElement(2, 0, 4);
    M1.addElement(2, 2, 3);

    SparseMatrix M2(4, 2);
    M2.addElement(0, 1, 2);
    M2.addElement(1, 0, 3);
    M2.addElement(2, 1, 4);
    M2.addElement(3, 0, 1);

    std::cout << "(c) Multiplication of two Matrices" << std::endl;
    std::cout << "Matrix M1:" << std::endl;
    M1.display();
    std::cout << "\nMatrix M2:" << std::endl;
    M2.display();
    std::cout << "\nProduct of M1 and M2:" << std::endl;
    SparseMatrix C_mul = multiply(M1, M2);
    C_mul.display();
    std::cout << "\n---------------------------------\n" << std::endl;

    return 0;
}


//7

#include <iostream>
#include <vector>

long long mergeAndCount(std::vector<int>& arr, std::vector<int>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long inv_count = 0;

    while ((i <= mid) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

long long mergeSortAndCount(std::vector<int>& arr, std::vector<int>& temp, int left, int right) {
    long long inv_count = 0;
    if (right > left) {
        int mid = left + (right - left) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

long long countInversions(std::vector<int>& arr) {
    if (arr.empty()) {
        return 0;
    }
    std::vector<int> temp(arr.size());
    return mergeSortAndCount(arr, temp, 0, arr.size() - 1);
}

int main() {
    std::vector<int> arr = {8, 4, 2, 1};
    
    std::cout << "Array: ";
    for(int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    long long inversions = countInversions(arr);
    std::cout << "Number of inversions: " << inversions << std::endl;

    std::vector<int> arr2 = {1, 20, 6, 4, 5};
    std::cout << "\nArray: ";
    for(int num : arr2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    inversions = countInversions(arr2);
    std::cout << "Number of inversions: " << inversions << std::endl;

    return 0;
}


//8
#include <iostream>
#include <vector>
#include <unordered_set>

int countDistinct(const std::vector<int>& arr) {
    std::unordered_set<int> distinct_elements(arr.begin(), arr.end());
    return distinct_elements.size();
}

int main() {
    std::vector<int> arr = {10, 20, 20, 10, 30, 40, 40, 10, 50};

    std::cout << "Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int distinct_count = countDistinct(arr);
    std::cout << "Total number of distinct elements: " << distinct_count << std::endl;

    std::vector<int> arr2 = {5, 5, 5, 5, 5};
    std::cout << "\nArray: ";
    for (int num : arr2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    distinct_count = countDistinct(arr2);
    std::cout << "Total number of distinct elements: " << distinct_count << std::endl;

    return 0;
}
