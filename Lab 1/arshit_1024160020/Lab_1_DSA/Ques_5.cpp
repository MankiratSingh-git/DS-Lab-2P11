#include <iostream>
using namespace std;

int main() {
    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int rowSum, colSum;

    // Row sums
    for (int i = 0; i < 3; i++) {
        rowSum = 0;
        for (int j = 0; j < 3; j++) {
            rowSum += a[i][j];
        }
        cout << "Sum of row " << i+1 << " = " << rowSum << endl;
    }

    // Column sums
    for (int j = 0; j < 3; j++) {
        colSum = 0;
        for (int i = 0; i < 3; i++) {
            colSum += a[i][j];
        }
        cout << "Sum of column " << j+1 << " = " << colSum << endl;
    }

    return 0;
}
