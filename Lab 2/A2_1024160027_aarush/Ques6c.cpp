#include <iostream>
using namespace std;

int main() {
    const int MAXNZ = 10000;
    int n, p, m;
    int nzA, nzB;

    cout << "Enter dimensions of A (n p): ";
    cin >> n >> p;
    cout << "Enter dimensions of B (p m): ";
    cin >> p >> m;

    cout << "Enter number of non-zero elements in A: ";
    cin >> nzA;
    if (nzA < 0 || nzA > MAXNZ) { cout << "Invalid nzA\n"; return 1; }

    int rowA[MAXNZ], colA[MAXNZ], valA[MAXNZ];

    cout << "Enter A non-zeros as: row col value (1-based indices)\n";
    for (int i = 0; i < nzA; i++) {
        int r, c, v;
        cin >> r >> c >> v;
        r--; c--;
        if (r < 0 || r >= n || c < 0 || c >= p) { cout << "A index out of range\n"; return 1; }
        rowA[i] = r; colA[i] = c; valA[i] = v;
    }

    cout << "Enter number of non-zero elements in B: ";
    cin >> nzB;
    if (nzB < 0 || nzB > MAXNZ) { cout << "Invalid nzB\n"; return 1; }

    int rowB[MAXNZ], colB[MAXNZ], valB[MAXNZ];

    cout << "Enter B non-zeros as: row col value (1-based indices)\n";
    for (int i = 0; i < nzB; i++) {
        int r, c, v;
        cin >> r >> c >> v;
        r--; c--;
        if (r < 0 || r >= p || c < 0 || c >= m) { cout << "B index out of range\n"; return 1; }
        rowB[i] = r; colB[i] = c; valB[i] = v;
    }

    int rowBT[MAXNZ], colBT[MAXNZ], valBT[MAXNZ];
    for (int k = 0; k < nzB; k++) {
        rowBT[k] = colB[k];
        colBT[k] = rowB[k];
        valBT[k] = valB[k];
    }

    int resRow[MAXNZ], resCol[MAXNZ], resVal[MAXNZ];
    int nzC = 0;

    for (int ia = 0; ia < nzA; ia++) {
        int ai = rowA[ia];
        int ak = colA[ia];
        int av = valA[ia];

        for (int ibt = 0; ibt < nzB; ibt++) {
            if (colBT[ibt] == ak) {
                int bj = rowBT[ibt];
                int bv = valBT[ibt];

                bool found = false;
                for (int r = 0; r < nzC; r++) {
                    if (resRow[r] == ai && resCol[r] == bj) {
                        resVal[r] += av * bv;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    if (nzC >= MAXNZ) { cout << "Result capacity exceeded\n"; return 1; }
                    resRow[nzC] = ai;
                    resCol[nzC] = bj;
                    resVal[nzC] = av * bv;
                    nzC++;
                }
            }
        }
    }

    int write = 0;
    for (int r = 0; r < nzC; r++) {
        if (resVal[r] != 0) {
            resRow[write] = resRow[r];
            resCol[write] = resCol[r];
            resVal[write] = resVal[r];
            write++;
        }
    }
    nzC = write;

    cout << "Result C = A * B (as triplets):\n";
    cout << "Row\tCol\tVal\n";
    for (int r = 0; r < nzC; r++) {
        cout << (resRow[r] + 1) << "\t" << (resCol[r] + 1) << "\t" << resVal[r] << "\n";
    }

    return 0;
}
