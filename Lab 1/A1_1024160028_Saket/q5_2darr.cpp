#include <iostream>
using namespace std;

void SumRowsAndColumns(int A[3][3]) {
    cout << "Here is your matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] << "\t";
        }
        cout << "\n";
    }

   
    cout << "\nSum of each row:" << endl;
    for (int i = 0; i < 3; i++) {
        int rowSum = 0;
        for (int j = 0; j < 3; j++) {
            rowSum += A[i][j];
        }
        cout << "Row " << i + 1 << ": " << rowSum << endl;
    }

    cout << "\nSum of each column:" << endl;
    for (int j = 0; j < 3; j++) {
        int colSum = 0;
        for (int i = 0; i < 3; i++) {
            colSum += A[i][j];
        }
        cout << "Column " << j + 1 << ": " << colSum << endl;
    }
}

int main() {
    cout << "Welcome to Row and Column Sum of Matrix Program!!" << endl;
    cout << "Do you want to generate a random matrix?(Y/N)" << endl;
    char my_choice;
    cin >> my_choice;

    int a[3][3] = {
        {0, 1, 2},
        {4, 2, 3},
        {2, 1, 1}
    };

    if (my_choice == 'Y' || my_choice == 'y') {
        cout << "Generating a random 3X3 matrix..." << endl;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << a[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "This is your matrix A" << endl;
    } else {
        cout << "No matrix is generated" << endl;
        cout << "Exiting Program......" << endl;
        return 0;
    }

    cout << "Do you want to find the sum of every row and column? (Y/N)" << endl;
    char my_choice2;
    cin >> my_choice2;

    if (my_choice2 == 'Y' || my_choice2 == 'y') {
        SumRowsAndColumns(a);
    } else {
        cout << "Exiting Program...." << endl;
        return 0;
    }

    return 0;
}
