#include <iostream>
using namespace std;
int main() {
   int n = 4;
    int smatrix[n + 1][3] = {
        {4, 5, 4},
        {0, 3, 8}, 
        {1, 1, 2}, 
        {3, 0, 5}, 
        {3, 4, 9}, 
    };
    int tmatrix[n + 1][3];
    tmatrix[0][0] = smatrix[0][1]; 
    tmatrix[0][1] = smatrix[0][0]; 
    tmatrix[0][2] = smatrix[0][2]; 
    for (int i = 1; i <=n; ++i) {
        tmatrix[i][0] = smatrix[i][1]; 
        tmatrix[i][1] = smatrix[i][0];
        tmatrix[i][2] = smatrix[i][2]; 
    }
    cout << "Original Sparse Matrix:" << endl;
    for (int i = 0; i <=n; ++i) {
        cout << smatrix[i][0] << " " << smatrix[i][1] << " " << smatrix[i][2] << endl;
    }
    cout << "\nTransposed Sparse Matrix:" << endl;
    for (int i = 0; i <= n; ++i) {
        cout << tmatrix[i][0] << " " << tmatrix[i][1] << " " << tmatrix[i][2] <<endl;
    }

    return 0;
}
