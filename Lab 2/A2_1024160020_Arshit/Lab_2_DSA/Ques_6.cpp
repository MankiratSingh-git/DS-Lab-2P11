#include <iostream>
using namespace std;

#define MAX 100

struct Element {
    int row, col, val;
};

struct Sparse {
    int rows, cols, terms;
    Element data[MAX];
};

void printSparse(Sparse s) {
    for (int i = 0; i < s.terms; i++) {
        cout << s.data[i].row << " " << s.data[i].col << " " << s.data[i].val << endl;
    }
}

int main() {
    Sparse s1 = {3, 3, 3, {{0,0,1}, {1,1,2}, {2,2,3}}};
    Sparse s2 = {3, 3, 3, {{0,0,4}, {1,1,5}, {2,2,6}}};

    // (a) Transpose
    Sparse t;
    t.rows = s1.cols;
    t.cols = s1.rows;
    t.terms = s1.terms;
    for (int i = 0; i < s1.terms; i++) {
        t.data[i].row = s1.data[i].col;
        t.data[i].col = s1.data[i].row;
        t.data[i].val = s1.data[i].val;
    }
    cout << "Transpose of Matrix:\n";
    printSparse(t);

    // (b) Addition (same positions)
    Sparse add = s1;
    for (int i = 0; i < s2.terms; i++) {
        add.data[i].val += s2.data[i].val;
    }
    cout << "Addition of Matrices:\n";
    printSparse(add);

    return 0;
}
