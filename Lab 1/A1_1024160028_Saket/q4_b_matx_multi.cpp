#include <iostream>
using namespace std;

int multiplyMatrix(int A[3][3], int B[3][3], int C[3][3])
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int sum = 0;
            for (int k = 0; k < 3; k++)
            {
                sum = sum + A[i][k] * B[k][j];
            }
            C[i][j] = sum;
            // cout << "\t";
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << C[i][j] << "\t";
        }
        cout<<"\n";
    }
    cout << "Your matrix is this " << endl;

    return 0;
}

int main()
{
    cout << "Welcome to multiplication of matrix program" << endl;
    cout << "Do you want to generate two generate two matrix?(Y/N)" << endl;
    char my_choice;
    cin >> my_choice;

    int a[3][3] = {{0, 1, 2}, {4, 2, 3}, {2, 1, 1}};
    int b[3][3] = {{0, 2, 2}, {5, 2, 1}, {9, 8, 1}};
    int c[3][3];

    if (my_choice == 'Y' || my_choice == 'y')
    {
        cout << "Generating two random 3X3 matrixs" << endl;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << a[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "this is your matrix A" << endl;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << b[i][j] << "\t";
            }
            cout <<"\n";
        }
        cout << "this is your matrix B" << endl;
    }

    else
    {
        cout << "No matrix is generated" << endl;
        cout << "Exiting Program......" << endl;
        return 0;
    }

    cout << "Do you want to multiply these matrixs?(Y/N)" << endl;
    char my_choice2;
    cin >> my_choice2;
    if (my_choice2 == 'Y' || my_choice2 == 'y')
    {
        cout << "Multiplying matrixs A and B" << endl;
        multiplyMatrix(a, b, c);
    }
    else
    {
        cout << "Exiting Program...." << endl;
        return 0;
    }
}