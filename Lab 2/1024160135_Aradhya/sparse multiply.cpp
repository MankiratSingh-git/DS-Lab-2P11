#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

struct Sparse {
    int rows, cols, num; // dimensions + number of non-zero
    Element *e;          // array of elements
};

Sparse multiply(Sparse s1, Sparse s2) {
    if (s1.cols != s2.rows) {
        cout << "Multiplication not possible\n";
        return {0,0,0,nullptr};
    }

    Sparse product;
    product.rows = s1.rows;
    product.cols = s2.cols;
    product.e = new Element[s1.num * s2.num]; // max possible
    product.num = 0;

    for (int i = 0; i < s1.num; i++) {
        for (int j = 0; j < s2.num; j++) {
            if (s1.e[i].col == s2.e[j].row) {
                int r = s1.e[i].row;
                int c = s2.e[j].col;
                int val = s1.e[i].val * s2.e[j].val;

                // check if (r,c) already exists
                int found = 0;
                for (int k = 0; k < product.num; k++) {
                    if (product.e[k].row == r && product.e[k].col == c) {
                        product.e[k].val += val;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    product.e[product.num].row = r;
                    product.e[product.num].col = c;
                    product.e[product.num].val = val;
                    product.num++;
                }
            }
        }
    }
    return product;
}
