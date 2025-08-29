// ques1
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (numbers[middle] == target) {
            return middle;
        }

        if (numbers[middle] < target) {
            left = middle + 1;
        } 
        else {
            right = middle - 1;
        }
    }

    return -1;
}

int main() {
    std::vector<int> values = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    
    int searchKey1 = 23;
    int searchKey2 = 15;

    int index1 = binarySearch(values, searchKey1);

    if (index1 != -1) {
        std::cout << "Element " << searchKey1 << " found at index: " << index1 << std::endl;
    } else {
        std::cout << "Element " << searchKey1 << " not found." << std::endl;
    }

    int index2 = binarySearch(values, searchKey2);

    if (index2 != -1) {
        std::cout << "Element " << searchKey2 << " found at index: " << index2 << std::endl;
    } else {
        std::cout << "Element " << searchKey2 << " not found." << std::endl;
    }

    return 0;
}

// ques2
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

// ques 3
#include <iostream>
#include <vector>

int findMissingLinear(const std::vector<int>& sequence) {
    int totalCount = sequence.size() + 1; 
    for (int index = 0; index < sequence.size(); ++index) {
        if (sequence[index] != index + 1) {
            return index + 1;
        }
    }
    return totalCount;
}

int findMissingBinary(const std::vector<int>& sequence) {
    int left = 0;
    int right = sequence.size() - 1;
    int missingVal = sequence.size() + 1; 

    while (left <= right) {
        int midIndex = left + (right - left) / 2;

        if (sequence[midIndex] == midIndex + 1) {
            left = midIndex + 1;
        } 
        else {
            missingVal = midIndex + 1;
            right = midIndex - 1;
        }
    }
    return missingVal;
}

int main() {
    std::vector<int> dataset = {1, 2, 3, 4, 6, 7, 8, 9, 10};

    std::cout << "Array: ";
    for (int element : dataset) {
        std::cout << element << " ";
    }
    std::cout << std::endl << std::endl;

    int resultLinear = findMissingLinear(dataset);
    std::cout << "Using Linear Search (O(n)): " << std::endl;
    std::cout << "The missing number is: " << resultLinear << std::endl;

    std::cout << "---------------------------------" << std::endl;

    int resultBinary = findMissingBinary(dataset);
    std::cout << "Using Binary Search (O(log n)): " << std::endl;
    std::cout << "The missing number is: " << resultBinary << std::endl;

    return 0;
}

// ques 4
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

    // Method 1: Using std::reverse (The easy way) 
    std::string text_to_reverse1 = text; 
    std::reverse(text_to_reverse1.begin(), text_to_reverse1.end());

    std::cout << "Method 1 (std::reverse):" << std::endl;
    std::cout << "Reversed string: " << text_to_reverse1 << std::endl;

    std::cout << "\n---------------------------------\n" << std::endl;

    // Method 2: Manual swap with two pointers 
    std::string text_to_reverse2 = text;
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
//  ques 5
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& numbers, int searchValue) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (numbers[middle] == searchValue) {
            return middle;
        }

        if (numbers[middle] < searchValue) {
            left = middle + 1;
        } 
        else {
            right = middle - 1;
        }
    }

    return -1;
}

int main() {
    std::vector<int> values = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    
    int search1 = 23;
    int search2 = 15;

    int index1 = binarySearch(values, search1);

    if (index1 != -1) {
        std::cout << "Element " << search1 << " found at index: " << index1 << std::endl;
    } else {
        std::cout << "Element " << search1 << " not found." << std::endl;
    }

    int index2 = binarySearch(values, search2);

    if (index2 != -1) {
        std::cout << "Element " << search2 << " found at index: " << index2 << std::endl;
    } else {
        std::cout << "Element " << search2 << " not found." << std::endl;
    }

    return 0;
}

// ques 6
#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    int rowIndex;
    int colIndex;
    int data;
};

class SparseMatrix {
public:
    int totalRows;
    int totalCols;
    std::vector<Node> terms;

    SparseMatrix(int r, int c) : totalRows(r), totalCols(c) {}

    void insert(int r, int c, int val) {
        if (val != 0) {
            terms.push_back({r, c, val});
        }
    }

    void display() const {
        int pos = 0;
        for (int r = 0; r < totalRows; ++r) {
            for (int c = 0; c < totalCols; ++c) {
                if (pos < terms.size() && terms[pos].rowIndex == r && terms[pos].colIndex == c) {
                    std::cout << terms[pos++].data << "\t";
                } else {
                    std::cout << "0\t";
                }
            }
            std::cout << std::endl;
        }
    }
};

// (a) Transpose of a matrix
SparseMatrix transpose(const SparseMatrix& mat) {
    SparseMatrix trans(mat.totalCols, mat.totalRows);
    trans.terms.resize(mat.terms.size());

    for (size_t i = 0; i < mat.terms.size(); ++i) {
        trans.terms[i].rowIndex = mat.terms[i].colIndex;
        trans.terms[i].colIndex = mat.terms[i].rowIndex;
        trans.terms[i].data = mat.terms[i].data;
    }

    std::sort(trans.terms.begin(), trans.terms.end(), [](const Node& a, const Node& b) {
        if (a.rowIndex != b.rowIndex) return a.rowIndex < b.rowIndex;
        return a.colIndex < b.colIndex;
    });

    return trans;
}

// (b) Addition of two matrices
SparseMatrix add(const SparseMatrix& mat1, const SparseMatrix& mat2) {
    if (mat1.totalRows != mat2.totalRows || mat1.totalCols != mat2.totalCols) {
        return SparseMatrix(0, 0); 
    }

    SparseMatrix sumMat(mat1.totalRows, mat1.totalCols);
    size_t i = 0, j = 0;

    while (i < mat1.terms.size() && j < mat2.terms.size()) {
        if (mat1.terms[i].rowIndex < mat2.terms[j].rowIndex ||
           (mat1.terms[i].rowIndex == mat2.terms[j].rowIndex && mat1.terms[i].colIndex < mat2.terms[j].colIndex)) {
            sumMat.terms.push_back(mat1.terms[i++]);
        } else if (mat2.terms[j].rowIndex < mat1.terms[i].rowIndex ||
                  (mat2.terms[j].rowIndex == mat1.terms[i].rowIndex && mat2.terms[j].colIndex < mat1.terms[i].colIndex)) {
            sumMat.terms.push_back(mat2.terms[j++]);
        } else {
            int total = mat1.terms[i].data + mat2.terms[j].data;
            if (total != 0) {
                sumMat.insert(mat1.terms[i].rowIndex, mat1.terms[i].colIndex, total);
            }
            i++;
            j++;
        }
    }

    while (i < mat1.terms.size()) sumMat.terms.push_back(mat1.terms[i++]);
    while (j < mat2.terms.size()) sumMat.terms.push_back(mat2.terms[j++]);

    return sumMat;
}

// (c) Multiplication of two matrices
SparseMatrix multiply(const SparseMatrix& mat1, const SparseMatrix& mat2) {
    if (mat1.totalCols != mat2.totalRows) {
        return SparseMatrix(0, 0);
    }

    SparseMatrix product(mat1.totalRows, mat2.totalCols);
    SparseMatrix mat2_T = transpose(mat2);
    
    for (size_t i = 0; i < mat1.terms.size(); ) {
        for (size_t j = 0; j < mat2_T.terms.size(); ) {
            
            int currentRow = mat1.terms[i].rowIndex;
            int currentCol = mat2_T.terms[j].rowIndex;

            int sum = 0;
            size_t temp_i = i;
            size_t temp_j = j;

            while (temp_i < mat1.terms.size() && mat1.terms[temp_i].rowIndex == currentRow &&
                   temp_j < mat2_T.terms.size() && mat2_T.terms[temp_j].rowIndex == currentCol) {
                
                if (mat1.terms[temp_i].colIndex < mat2_T.terms[temp_j].colIndex) {
                    temp_i++;
                } else if (mat2_T.terms[temp_j].colIndex < mat1.terms[temp_i].colIndex) {
                    temp_j++;
                } else {
                    sum += mat1.terms[temp_i].data * mat2_T.terms[temp_j].data;
                    temp_i++;
                    temp_j++;
                }
            }
            
            if (sum != 0) {
                product.insert(currentRow, currentCol, sum);
            }

            size_t next_j = j;
            while(next_j < mat2_T.terms.size() && mat2_T.terms[next_j].rowIndex == currentCol) next_j++;
            if(next_j == mat2_T.terms.size()) {
                size_t next_i = i;
                while(next_i < mat1.terms.size() && mat1.terms[next_i].rowIndex == currentRow) next_i++;
                i = next_i;
                j = 0;
            } else {
                j = next_j;
            }
        }
    }
     std::sort(product.terms.begin(), product.terms.end(), [](const Node& a, const Node& b) {
        if (a.rowIndex != b.rowIndex) return a.rowIndex < b.rowIndex;
        return a.colIndex < b.colIndex;
    });
    return product;
}

int main() {
    SparseMatrix matA(4, 5);
    matA.insert(0, 2, 3);
    matA.insert(0, 4, 4);
    matA.insert(1, 2, 5);
    matA.insert(1, 3, 7);
    matA.insert(2, 1, 2);
    matA.insert(3, 0, 9);

    SparseMatrix matB(4, 5);
    matB.insert(0, 1, 1);
    matB.insert(1, 2, 3);
    matB.insert(1, 3, 4);
    matB.insert(2, 1, 5);
    matB.insert(3, 4, 2);
    
    std::cout << "(a) Transpose of a Matrix" << std::endl;
    std::cout << "Original Matrix A:" << std::endl;
    matA.display();
    std::cout << "\nTranspose of A:" << std::endl;
    SparseMatrix matA_T = transpose(matA);
    matA_T.display();
    std::cout << "\n---------------------------------\n" << std::endl;

    std::cout << "(b) Addition of two Matrices" << std::endl;
    std::cout << "Matrix A:" << std::endl;
    matA.display();
    std::cout << "\nMatrix B:" << std::endl;
    matB.display();
    std::cout << "\nSum of A and B:" << std::endl;
    SparseMatrix matSum = add(matA, matB);
    matSum.display();
    std::cout << "\n---------------------------------\n" << std::endl;

    SparseMatrix matM1(3, 4);
    matM1.insert(0, 0, 1);
    matM1.insert(0, 3, 5);
    matM1.insert(1, 1, 2);
    matM1.insert(2, 0, 4);
    matM1.insert(2, 2, 3);

    SparseMatrix matM2(4, 2);
    matM2.insert(0, 1, 2);
    matM2.insert(1, 0, 3);
    matM2.insert(2, 1, 4);
    matM2.insert(3, 0, 1);

    std::cout << "(c) Multiplication of two Matrices" << std::endl;
    std::cout << "Matrix M1:" << std::endl;
    matM1.display();
    std::cout << "\nMatrix M2:" << std::endl;
    matM2.display();
    std::cout << "\nProduct of M1 and M2:" << std::endl;
    SparseMatrix matProduct = multiply(matM1, matM2);
    matProduct.display();
    std::cout << "\n---------------------------------\n" << std::endl;

    return 0;
}
// ques 7
#include <iostream>
#include <vector>

long long mergeAndCount(std::vector<int>& numbers, std::vector<int>& buffer, int leftIndex, int midIndex, int rightIndex) {
    int i = leftIndex;
    int j = midIndex + 1;
    int k = leftIndex;
    long long inversionCount = 0;

    while (i <= midIndex && j <= rightIndex) {
        if (numbers[i] <= numbers[j]) {
            buffer[k++] = numbers[i++];
        } else {
            buffer[k++] = numbers[j++];
            inversionCount += (midIndex - i + 1);
        }
    }

    while (i <= midIndex) {
        buffer[k++] = numbers[i++];
    }

    while (j <= rightIndex) {
        buffer[k++] = numbers[j++];
    }

    for (i = leftIndex; i <= rightIndex; i++) {
        numbers[i] = buffer[i];
    }

    return inversionCount;
}

long long mergeSortAndCount(std::vector<int>& numbers, std::vector<int>& buffer, int leftIndex, int rightIndex) {
    long long inversionCount = 0;
    if (rightIndex > leftIndex) {
        int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

        inversionCount += mergeSortAndCount(numbers, buffer, leftIndex, midIndex);
        inversionCount += mergeSortAndCount(numbers, buffer, midIndex + 1, rightIndex);
        inversionCount += mergeAndCount(numbers, buffer, leftIndex, midIndex, rightIndex);
    }
    return inversionCount;
}

long long countInversions(std::vector<int>& numbers) {
    if (numbers.empty()) {
        return 0;
    }
    std::vector<int> buffer(numbers.size());
    return mergeSortAndCount(numbers, buffer, 0, numbers.size() - 1);
}

int main() {
    std::vector<int> array1 = {8, 4, 2, 1};
    
    std::cout << "Array: ";
    for(int element : array1) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    long long invCount1 = countInversions(array1);
    std::cout << "Number of inversions: " << invCount1 << std::endl;

    std::vector<int> array2 = {1, 20, 6, 4, 5};
    std::cout << "\nArray: ";
    for(int element : array2) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    
    long long invCount2 = countInversions(array2);
    std::cout << "Number of inversions: " << invCount2 << std::endl;

    return 0;
}
//  ques 8
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