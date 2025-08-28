#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

struct Sparse {
    int rows, cols, num; // dimensions + number of non-zero
    Element *e;          // array of elements
};

Sparse transpose(Sparse s) {
    Sparse t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.num = s.num;
    t.e = new Element[t.num];

    int k = 0;
    for (int i = 0; i < s.cols; i++) {
        for (int j = 0; j < s.num; j++) {
            if (s.e[j].col == i) {
                t.e[k].row = s.e[j].col;
                t.e[k].col = s.e[j].row;
                t.e[k].val = s.e[j].val;
                k++;
            }
        }
    }
    return t;
}

void display(Sparse s) {
    cout << "Row Col Val\n";
    for (int i = 0; i < s.num; i++) {
        cout << s.e[i].row << "   " << s.e[i].col << "   " << s.e[i].val << endl;
    }
}
