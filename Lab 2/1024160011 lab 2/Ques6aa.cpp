#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m,i,j,n;
    cout << "Enter the size of the sparse matrix: ";
    cin >> n;
    cout<<"Enter the number of non zero elements: ";
    cin>>m;
    if(m > (n*n)/2) {
        cout << "Number of non-zero elements cannot exceed half of the total elements in a sparse matrix." << endl;
        return 1;
    }
    int arrrow[m],arrcolumn[m],arrvalue[m];
    
    
    cout << "Enter the row column and value of the non zero element: ";
    for ( i = 0; i < m; i++)
    {
        cout << "Element [" << i + 1 << "]: ";
        cin >> arrrow[i] >> arrcolumn[i] >> arrvalue[i];
    }
    for (i = 0; i < m; i++) 
    {
        if(arrrow[i]>n|| arrcolumn[i]>n) {
            cout << "Row and column indices must be less than or equal to " << n << "." << endl;
            return 1;
    }
    }
    cout << "The sparse matrix is: " << endl;
    cout << "Row\tColumn\tValue" << endl;
    for ( i = 0; i < m; i++) {  
        cout << arrrow[i] << "\t" << arrcolumn[i] << "\t" << arrvalue[i] << endl;
    }
    for(i=0; i < m; i++) {
        int temp = arrrow[i];
        arrrow[i] = arrcolumn[i];
        arrcolumn[i] = temp;

    }
    cout << "The transposed sparse matrix is: " << endl;
    cout << "Row\tColumn\tValue" << endl;
    for ( i = 0; i < m; i++) {  
        cout << arrrow[i] << "\t" << arrcolumn[i] << "\t" << arrvalue[i] << endl;
    }
    system("pause");
    return 0;
}

