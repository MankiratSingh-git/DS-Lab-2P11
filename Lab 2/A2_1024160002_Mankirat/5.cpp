#include <iostream>
using namespace std;

void storeDiagonal(int n);
void storeTriDiagonal(int n);
void storeLowerTriangular(int n);
void storeUpperTriangular(int n);
void storeSymmetric(int n);

int main(){
    int n;
    cout << "Enter size of matrix (n x n): ";
    cin >> n;

    storeDiagonal(n);
    storeTriDiagonal(n);
    storeLowerTriangular(n);
    storeUpperTriangular(n);
    storeSymmetric(n);

    return 0;
}

void storeDiagonal(int n){
    int *diag = new int[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int val;
            cin >> val;
            if(i == j) diag[i] = val;
        }
    }
    for(int i = 0; i < n; i++) cout << diag[i] << " ";
    cout << endl;
    delete[] diag;
}

void storeTriDiagonal(int n){
    int size = 3 * n - 2;
    int *tri = new int[size];
    int k = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int val;
            cin >> val;
            if(abs(i - j) <= 1) tri[k++] = val;
        }
    }
    for(int i = 0; i < size; i++) cout << tri[i] << " ";
    cout << endl;
    delete[] tri;
}

void storeLowerTriangular(int n){
    int size = n * (n + 1) / 2;
    int *low = new int[size];
    int k = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int val;
            cin >> val;
            if(i >= j) low[k++] = val;
        }
    }
    for(int i = 0; i < size; i++) cout << low[i] << " ";
    cout << endl;
    delete[] low;
}

void storeUpperTriangular(int n){
    int size = n * (n + 1) / 2;
    int *up = new int[size];
    int k = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int val;
            cin >> val;
            if(i <= j) up[k++] = val;
        }
    }
    for(int i = 0; i < size; i++) cout << up[i] << " ";
    cout << endl;
    delete[] up;
}

void storeSymmetric(int n){
    int size = n * (n + 1) / 2;
    int *sym = new int[size];
    int k = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int val;
            cin >> val;
            if(i >= j) sym[k++] = val;
        }
    }
    for(int i = 0; i < size; i++) cout << sym[i] << " ";
    cout << endl;
    delete[] sym;
}
