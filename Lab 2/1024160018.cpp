// 1. Binary Search O(log n)

#include<iostream>
using namespace std;
void BinarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            cout << "Element found at index: " << mid << endl;
            return;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "Element not found in the array." << endl;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    BinarySearch(arr, size, key);
    return 0;
}

// 2. Bubble Sort

#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

// 3. Logic to find missing number in array

#include <iostream>
using namespace std;
int findMissingNumber(int arr[], int size, int n) { // Linear Search
    for (int i = 0; i < size; i++) {
        if (arr[i] == n) {
            cout << "Number found at index: " << n << endl;
        }
    }
    cout << "Number not found in the array." << endl;
    return -1;
}
int findMissingNumberBinary(int arr[], int size, int n) { // Binary Search
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == n) {
            cout << "Number found at index: " << mid << endl;
            return mid;
        }
        if (arr[mid] < n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "Number not found in the array." << endl;
    return -1;
}

// 4.
// 4.a
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[100], str2[100];
    cout << "Enter first string: ";
    cin.getline(str1, 100);
    cout << "Enter second string: ";
    cin.getline(str2, 100);

    strcat(str1, str2); // Concatenate
    cout << "Concatenated string: " << str1 << endl;
    return 0;
}

// 4.b
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    cout << "Reversed string: " << str << endl;
    return 0;
}

// 4.c
#include <iostream>
#include <cstring>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    char result[100];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isVowel(str[i])) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';

    cout << "String without vowels: " << result << endl;
    return 0;
}

//4.d
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();

    char str[50][100];
    for (int i = 0; i < n; i++) {
        cout << "Enter string " << i+1 << ": ";
        cin.getline(str[i], 100);
    }

    char temp[100];
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }
    return 0;
}

//4.e
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    ch = tolower(ch);
    cout << "Lowercase: " << ch << endl;
    return 0;
}

// 5. Matrix Representation

#include <iostream>
#include <vector>
using namespace std;

class Diagonal {
    vector<int> A; 
    int n;
public:
    Diagonal(int n) : n(n), A(n, 0) {}
    void set(int i, int j, int val) {
        if (i == j) A[i] = val;
    }
    int get(int i, int j) {
        return (i == j) ? A[i] : 0;
    }
    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << get(i, j) << " ";
            cout << endl;
        }
    }
};


class TriDiagonal {
    vector<int> A; 
    int n;
public:
    TriDiagonal(int n) : n(n), A(3*n - 2, 0) {}
    void set(int i, int j, int val) {
        if (i == j) A[i] = val;                     
        else if (i - j == 1) A[n + i - 1] = val;     
        else if (j - i == 1) A[2*n - 1 + i] = val;   
    }
    int get(int i, int j) {
        if (i == j) return A[i];
        else if (i - j == 1) return A[n + i - 1];
        else if (j - i == 1) return A[2*n - 1 + i];
        else return 0;
    }
    void display() {
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++)
                cout<<get(i,j)<<" ";
            cout<<endl;
        }
    }
};

class LowerTriangular {
    vector<int> A; 
    int n;
public:
    LowerTriangular(int n) : n(n), A(n*(n+1)/2, 0) {}
    int index(int i, int j) { return i*(i+1)/2 + j; } 
    void set(int i, int j, int val) {
        if (i >= j) A[index(i, j)] = val;
    }
    int get(int i, int j) {
        if (i >= j) return A[index(i,j)];
        else return 0;
    }
    void display() {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<get(i,j)<<" ";
            cout<<endl;
        }
    }
};

class UpperTriangular {
    vector<int> A; 
    int n;
public:
    UpperTriangular(int n) : n(n), A(n*(n+1)/2, 0) {}
    int index(int i, int j) { return n*i - (i*(i+1))/2 + j - i; }
    void set(int i, int j, int val) {
        if (i <= j) A[index(i,j)] = val;
    }
    int get(int i, int j) {
        if (i <= j) return A[index(i,j)];
        else return 0;
    }
    void display() {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<get(i,j)<<" ";
            cout<<endl;
        }
    }
};

class Symmetric {
    vector<int> A; 
    int n;
public:
    Symmetric(int n) : n(n), A(n*(n+1)/2, 0) {}
    int index(int i, int j) {
        if (i >= j) return i*(i+1)/2 + j;
        else return j*(j+1)/2 + i;
    }
    void set(int i, int j, int val) {
        A[index(i,j)] = val;
    }
    int get(int i, int j) {
        return A[index(i,j)];
    }
    void display() {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<get(i,j)<<" ";
            cout<<endl;
        }
    }
};

int main() {
    cout<<"Diagonal Matrix:\n";
    Diagonal d(3);
    d.set(0,0,1); d.set(1,1,2); d.set(2,2,3);
    d.display();

    cout<<"\nTri-Diagonal Matrix:\n";
    TriDiagonal td(3);
    td.set(0,0,1); td.set(1,1,2); td.set(2,2,3);
    td.set(1,0,4); td.set(2,1,5);
    td.set(0,1,6); td.set(1,2,7);
    td.display();

    cout<<"\nLower Triangular Matrix:\n";
    LowerTriangular lt(3);
    lt.set(0,0,1); lt.set(1,0,2); lt.set(1,1,3); lt.set(2,0,4); lt.set(2,1,5); lt.set(2,2,6);
    lt.display();

    cout<<"\nUpper Triangular Matrix:\n";
    UpperTriangular ut(3);
    ut.set(0,0,1); ut.set(0,1,2); ut.set(0,2,3); ut.set(1,1,4); ut.set(1,2,5); ut.set(2,2,6);
    ut.display();

    cout<<"\nSymmetric Matrix:\n";
    Symmetric sm(3);
    sm.set(0,0,1); sm.set(0,1,2); sm.set(0,2,3); sm.set(1,1,4); sm.set(1,2,5); sm.set(2,2,6);
    sm.display();

    return 0;
}

// 7. Count inversions in an array
#include <iostream>
#include <vector>
using namespace std;

int mergeAndCount(vector<int> &arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l, swaps = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else {
            arr[k++] = right[j++];
            swaps += (left.size() - i);
        }
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
    return swaps;
}

int countInversions(vector<int> &arr, int l, int r) {
    int cnt = 0;
    if (l < r) {
        int m = (l + r) / 2;
        cnt += countInversions(arr, l, m);
        cnt += countInversions(arr, m + 1, r);
        cnt += mergeAndCount(arr, l, m, r);
    }
    return cnt;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int inversions = countInversions(arr, 0, n - 1);
    cout << "Number of inversions: " << inversions << endl;
    return 0;
}



// 8. Count Distinct Elements in an Array

#include <iostream>
#include <algorithm>
using namespace std;

int countDistinct(int arr[], int size) {
    sort(arr, arr + size); 
    if (size == 0) return 0;
    int count = 1; 
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[i - 1]) {
            count++;
        }
    }
    return count;
}

