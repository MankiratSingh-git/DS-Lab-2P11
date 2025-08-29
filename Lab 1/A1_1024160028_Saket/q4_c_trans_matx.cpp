#include <iostream>
using namespace std;


void TransposeMatrix(int A[3][3]){
    for(int i = 0 ; i < 3 ; i++){
        for(int j =  i+1  ; j < 3 ; j++){
            int temp = 0 ; 
            temp = A[i][j];
            A[i][j]=A[j][i];
            A[j][i]=temp;
        }
    }

    cout<<"Matrix is Transposed!"<<endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           cout<<A[i][j]<<"\t";
        }
        cout<<"\n";
    }
    
}



int main()
{
    cout << "Welcome to Generate Transpose of Matrix Program!! " << endl;
    cout << "Do you want to generate a random matrix?(Y/N)" << endl;
    char my_choice;
    cin >> my_choice;

    int a[3][3] = {{0, 1, 2}, {4, 2, 3}, {2, 1, 1}};

    int c[3][3];

    if (my_choice == 'Y' || my_choice == 'y')
    {
        cout << "Generating a random 3X3 matrixs" << endl;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << a[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "this is your matrix A" << endl;
    }

    else
    {
        cout << "No matrix is generated" << endl;
        cout << "Exiting Program......" << endl;
        return 0;
    }

    cout << "Do you want to find the transpose of this matrix?(Y/N)" << endl;
    char my_choice2;
    cin >> my_choice2;
    if (my_choice2 == 'Y' || my_choice2 == 'y')
    {
        cout << "Finding out the transpose of matrixs A " << endl;
        TransposeMatrix(a);
    }
    else{
          cout << "Exiting Program...." << endl;
          return 0;
         
     }
    
    
    
    
}