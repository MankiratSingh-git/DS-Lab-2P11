#include<iostream>
using namespace std;

//q1
// int main(){
//     int arr[1000];
//     int n;
//     cout <<"Enter the size of array";
//     cin>> n;
//     cout << "Enter elements of array";
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }

//     int key;
//     cout<<"enter element to search";
//     cin >> key;

//     int start =0;
//     int end=n-1;
//     while(start<=end){
//         int mid=start + (end-start)/2;
//         if(arr[mid]==key){
//             cout << "Element found at index " << mid << endl;
//             break;
//         }

//         else if(arr[mid]<key){
//             start=mid +1;
//         }

//         else{
//             end=mid -1;
//         }

//     }
//     return 0;

// }


//q2
// int main(){
//     int arr[7]={24,34,25,12,22,11,90};
//     int n=7;
//     for(int i=n-2;i>=0;i--){
//         bool swapped =0;
//         for(int j=0;j<=i;j++){
//             if(arr[j]>arr[j+1]){
//                 swap(arr[j],arr[j+1]);
//             }
//             swapped =1;
//         }
//         if(!swapped){
//             break;
//         }
//     }
//     cout << "Sorted array: ";
//     for (int i=0;i<n;i++){
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

//q3(a)
// int MissingNo(int arr[],int n){
//     for(int i=0;i<n-1;i++){
//         if(arr[i]!=i+1){
//             return i+1;
//         }
//     }
//     return n;
// }

// int main(){
//     int arr[]={1,2,3,4,5,7,8};
//     int n= sizeof(arr)/sizeof(arr[0]);
//     cout << "Missing number is: " << MissingNo(arr,n) << endl;
//     return 0;
// }

//q3(b)
// int MissingNo(int arr[],int n){
//     int start=0,end=n-2;
//     while(start<=end){
//         int mid = start+(end-start)/2;
//         if(arr[mid]==mid + 1){
//             start=mid+1;

//         }
        
//         else{
//             end=mid-1;
//         }


//     }
//     return start + 1;
// }

// int main(){
//     int arr[]={1,2,3,4,5,7,8};
//     int n= sizeof(arr)/sizeof(arr[0]);
//     cout << "Missing number is: " << MissingNo(arr,n) << endl;
//     return 0;
// }

//q4(a)
// int main(){
//     string str1="hello";
//     string str2=" world";
//     string str3=str1+str2;
//     cout << "Concatenated string: " << str3 << endl;
//     return 0;
// }


//q4(b)
// int main(){
//     string str="Nidhish";
//     int start=0,end=str.size()-1;
//     while(start<end){
//         swap(str[start], str[end]);
//         start++,end--;
//     }

//     cout << "reversed string" << str <<endl;
//     return 0;
// }

//q4(c)

// int main(){
//     string str="nidhish";
// int j=0;
// for(int i=0;i<str.size();i++){
//     if(str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u'){
//         str[j]=str[i];
//         j++;
//     }

// }
// cout<<"Vowels Removed String: "<<str<<endl;
// }

//q4(d)
// int main(){
//     int n;
//     cout<<"Enter the number of strings: ";
//     cin>>n;
//     char str[100][100]; // 2D array for up to 100 strings of length 99
//     for(int i=0;i<n;i++){
//         cout<<"Enter string "<<i+1<<": ";
//         cin>>str[i];
//     }
//     // alphabetically sort the strings
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(strcmp(str[i],str[j])>0){
//                swap(str[i],str[j]);
//             }
//         }
//     }
//     cout << "Sorted strings:" << endl;
//     for(int i=0;i<n;i++){
//         cout << str[i] << endl;
//     }
//     return 0;
// }

//q4(e)
int main(){
    char ch;
    cout << "enter a character ";
    cin >> ch;

    if(ch >=  'A' && ch<='Z'){
        ch=ch+32;
        cout << "lowercase is " << ch << endl;

    }
    else{ 
        cout << "already lowercase" ;
    }
    return 0;
    
}

// Q5. Matrix Representation

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

// Q6. Sparse Matrix Representation

#include <iostream>
#include <vector>
using namespace std;

struct Element {
    int row, col, val;
};

struct Sparse {
    int rows, cols, num;
    vector<Element> data;
};

Sparse transpose(Sparse &s) {
    Sparse t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.num = s.num;
    t.data.resize(s.num);

    int k = 0;
    for (int i = 0; i < s.cols; i++) {
        for (int j = 0; j < s.num; j++) {
            if (s.data[j].col == i) {
                t.data[k++] = {s.data[j].col, s.data[j].row, s.data[j].val};
            }
        }
    }
    return t;
}

Sparse add(Sparse &a, Sparse &b) {
    Sparse c;
    if (a.rows != b.rows || a.cols != b.cols) {
        cout << "Incompatible dimensions\n";
        return c;
    }
    c.rows = a.rows; c.cols = a.cols;
    int i=0,j=0;
    while(i<a.num && j<b.num) {
        if(a.data[i].row < b.data[j].row ||
          (a.data[i].row==b.data[j].row && a.data[i].col < b.data[j].col)) {
            c.data.push_back(a.data[i++]);
        }
        else if(b.data[j].row < a.data[i].row ||
          (b.data[j].row==a.data[i].row && b.data[j].col < a.data[i].col)) {
            c.data.push_back(b.data[j++]);
        }
        else {
            c.data.push_back({a.data[i].row,a.data[i].col,a.data[i].val+b.data[j].val});
            i++; j++;
        }
    }
    while(i<a.num) c.data.push_back(a.data[i++]);
    while(j<b.num) c.data.push_back(b.data[j++]);
    c.num = c.data.size();
    return c;
}

Sparse multiply(Sparse &a, Sparse &b) {
    Sparse c;
    if (a.cols != b.rows) {
        cout << "Incompatible dimensions\n";
        return c;
    }
    c.rows = a.rows; c.cols = b.cols;

    for(int i=0;i<a.num;i++) {
        for(int j=0;j<b.num;j++) {
            if(a.data[i].col == b.data[j].row) {
                int r = a.data[i].row;
                int ccol = b.data[j].col;
                int val = a.data[i].val * b.data[j].val;

                bool found=false;
                for(auto &e : c.data) {
                    if(e.row==r && e.col==ccol) {
                        e.val += val;
                        found=true;
                        break;
                    }
                }
                if(!found) c.data.push_back({r,ccol,val});
            }
        }
    }
    c.num = c.data.size();
    return c;
}


int main() {
    Sparse A{3,3,3, {{0,2,5},{1,0,2},{2,1,7}}};
    Sparse B{3,3,3, {{0,2,1},{1,1,4},{2,0,3}}};

    cout<<"Matrix A:\n"; display(A);
    cout<<"Matrix B:\n"; display(B);

    cout<<"\nTranspose of A:\n";
    Sparse T = transpose(A);
    display(T);

    cout<<"\nAddition (A+B):\n";
    Sparse C = add(A,B);
    display(C);

    cout<<"\nMultiplication (A*B):\n";
    Sparse M = multiply(A,B);
    display(M);

    return 0;
}



// Q7. Count inversions in an array
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

// Q8
#include<iostream>
using namespace std;

int main(){
    int arr[6]={1,2,3,4,3,2};
    int count =0;
    for(int i=0;i<6;i++){
        bool duplicate=0;
        for(int j=0;j<i;j++){
            if (arr[i]==arr[j]){
                duplicate=1;
                break;
            }
        }
        if(duplicate==0){
            count++;
        }
    }
    cout<<count;
}