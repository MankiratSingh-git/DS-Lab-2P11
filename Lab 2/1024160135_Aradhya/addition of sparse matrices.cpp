#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

struct Sparse {
    int rows, cols, num; // dimensions + number of non-zero
    Element *e;          // array of elements
};

Sparse add(Sparse s1, Sparse s2) {
    if (s1.rows != s2.rows || s1.cols != s2.cols) {
        cout << "Addition not possible\n";
        return {0,0,0,nullptr};
    }

    Sparse sum;
    sum.rows = s1.rows;
    sum.cols = s1.cols;
    sum.e = new Element[s1.num + s2.num];

    int i=0, j=0, k=0;
    while (i < s1.num && j < s2.num) {
        if (s1.e[i].row < s2.e[j].row || 
            (s1.e[i].row == s2.e[j].row && s1.e[i].col < s2.e[j].col))
            sum.e[k++] = s1.e[i++];
        else if (s2.e[j].row < s1.e[i].row || 
                 (s2.e[j].row == s1.e[i].row && s2.e[j].col < s1.e[i].col))
            sum.e[k++] = s2.e[j++];
        else {
            sum.e[k] = s1.e[i];
            sum.e[k++].val = s1.e[i++].val + s2.e[j++].val;
        }
    }
    for (; i < s1.num; i++) sum.e[k++] = s1.e[i];
    for (; j < s2.num; j++) sum.e[k++] = s2.e[j];

    sum.num = k;
    return sum;
}
