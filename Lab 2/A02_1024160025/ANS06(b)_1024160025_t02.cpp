#include <iostream>
using namespace std;
void convertToSparse(int matrix[10][10], int r, int c, int sparse[][3]) {
    int k = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    sparse[0][0] = r;
    sparse[0][1] = c;
    sparse[0][2] = k-1;
}
void addSparse(int A[][3], int B[][3], int C[][3]) {
    int i = 1, j = 1, k = 1;
    

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];
    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0]<B[j][0] || (A[i][0]==B[j][0] && A[i][1]<B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else if (B[j][0] < A[i][0]||(B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
        else { 
            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }

    while (i<=A[0][2]) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }
    while (j <= B[0][2]) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1;
}
void displaySparse(int S[][3]) {
    for (int i = 0; i <= S[0][2]; i++) {
        cout<<S[i][0]<<" "<<S[i][1]<<" "<<S[i][2]<<endl;
    }
}
int main() {
    int matrix1[10][10] = {
        {1, 0, 0},
        {0, 2, 0},
        {0, 0, 3}
    };
    int matrix2[10][10] = {
        {4, 0, 0},
        {0, 0, 5},
        {0, 6, 0}
    };
    int MAX=100;
    int A[MAX][3], B[MAX][3], C[MAX][3];
    convertToSparse(matrix1, 3, 3, A);
    convertToSparse(matrix2, 3, 3, B);
    cout << "Sparse Matrix A :";
    displaySparse(A);
    cout << "Sparse Matrix B :";
    displaySparse(B);
    addSparse(A, B, C);
    cout << "Resultant Sparse Matrix C :";
    displaySparse(C);
    return 0;
}

