#include <iostream>
using namespace std;

struct Triple {
    int row, col, val;
};

void readSparse(Triple mat[], int &m, int &n, int &terms);
void printSparse(Triple mat[], int terms);
void transpose(Triple mat[], Triple trans[]);
void addSparse(Triple a[], Triple b[], Triple result[]);
void multiplySparse(Triple a[], Triple b[], Triple result[]);

int main(){
    int m, n, terms;
    Triple mat[100], trans[100];
    cout << "Enter sparse matrix:\n";
    readSparse(mat, m, n, terms);
    transpose(mat, trans);
    cout << "Transpose:\n";
    printSparse(trans, trans[0].val);

    int m1, n1, t1, m2, n2, t2;
    Triple A[100], B[100], sum[100], prod[100];
    cout << "Enter first matrix for addition:\n";
    readSparse(A, m1, n1, t1);
    cout << "Enter second matrix for addition:\n";
    readSparse(B, m2, n2, t2);
    addSparse(A, B, sum);
    cout << "Sum:\n";
    printSparse(sum, sum[0].val);

    cout << "Enter first matrix for multiplication:\n";
    readSparse(A, m1, n1, t1);
    cout << "Enter second matrix for multiplication:\n";
    readSparse(B, m2, n2, t2);
    multiplySparse(A, B, prod);
    cout << "Product:\n";
    printSparse(prod, prod[0].val);

    return 0;
}

void readSparse(Triple mat[], int &m, int &n, int &terms){
    cin >> m >> n >> terms;
    mat[0].row = m;
    mat[0].col = n;
    mat[0].val = terms;
    for(int i = 1; i <= terms; i++)
        cin >> mat[i].row >> mat[i].col >> mat[i].val;
}

void printSparse(Triple mat[], int terms){
    for(int i = 0; i <= terms; i++)
        cout << mat[i].row << " " << mat[i].col << " " << mat[i].val << endl;
}

void transpose(Triple mat[], Triple trans[]){
    int m = mat[0].row, n = mat[0].col, terms = mat[0].val;
    trans[0].row = n;
    trans[0].col = m;
    trans[0].val = terms;
    if(terms > 0){
        int k = 1;
        for(int col = 0; col < n; col++)
            for(int i = 1; i <= terms; i++)
                if(mat[i].col == col){
                    trans[k].row = mat[i].col;
                    trans[k].col = mat[i].row;
                    trans[k].val = mat[i].val;
                    k++;
                }
    }
}

void addSparse(Triple a[], Triple b[], Triple result[]){
    if(a[0].row != b[0].row || a[0].col != b[0].col){
        result[0].val = 0;
        return;
    }
    result[0].row = a[0].row;
    result[0].col = a[0].col;
    int i = 1, j = 1, k = 1;
    while(i <= a[0].val && j <= b[0].val){
        if(a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col))
            result[k++] = a[i++];
        else if(b[j].row < a[i].row || (b[j].row == a[i].row && b[j].col < a[i].col))
            result[k++] = b[j++];
        else{
            result[k] = a[i];
            result[k++].val = a[i++].val + b[j++].val;
        }
    }
    while(i <= a[0].val) result[k++] = a[i++];
    while(j <= b[0].val) result[k++] = b[j++];
    result[0].val = k - 1;
}

void multiplySparse(Triple a[], Triple b[], Triple result[]){
    if(a[0].col != b[0].row){
        result[0].val = 0;
        return;
    }
    Triple bt[100];
    transpose(b, bt);
    result[0].row = a[0].row;
    result[0].col = b[0].col;
    int k = 1;
    for(int i = 1; i <= a[0].val; ){
        int row = a[i].row;
        for(int j = 1; j <= bt[0].val; ){
            int col = bt[j].row;
            int sum = 0;
            int ii = i, jj = j;
            while(ii <= a[0].val && a[ii].row == row && jj <= bt[0].val && bt[jj].row == col){
                if(a[ii].col < bt[jj].col) ii++;
                else if(a[ii].col > bt[jj].col) jj++;
                else sum += a[ii++].val * bt[jj++].val;
            }
            if(sum != 0){
                result[k].row = row;
                result[k].col = col;
                result[k].val = sum;
                k++;
            }
            while(j <= bt[0].val && bt[j].row == col) j++;
        }
        while(i <= a[0].val && a[i].row == row) i++;
    }
    result[0].val = k - 1;
}
