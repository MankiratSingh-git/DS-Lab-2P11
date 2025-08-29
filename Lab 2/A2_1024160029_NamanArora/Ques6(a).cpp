#include <iostream>
using namespace std;

int main(){
    int sampleSparseMatrix[3][3] = {
        {5, 2, 3},
        {14, 78, 87},
        {27, 8, 7}
    };
    int zeroes = 0, non_zeroes;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(sampleSparseMatrix[i][j] == 0){
                zeroes++;
            }
        }
    }
    non_zeroes = 9 - zeroes;
    int compactMatrix[non_zeroes + 1][3] = {
        {3, 3, zeroes}
    };
    int k = 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(sampleSparseMatrix[i][j] != 0){
                compactMatrix[k][0] = i;
                compactMatrix[k][1] = j;
                compactMatrix[k][2] = sampleSparseMatrix[i][j];
                k++;
            }
        }
    }
    cout<<"Compact Matrix:\nR C V"<<endl;
    for(int i = 0; i < non_zeroes + 1; i++){
        for(int j = 0; j < 3; j++){
            cout<<compactMatrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i = 1; i < non_zeroes; i++){
        int temp = compactMatrix[i][0];
        compactMatrix[i][0] = compactMatrix[i][1];
        compactMatrix[i][1] = temp; 
        }
    cout<<"\nTransposed Compact Matrix:\nR C V"<<endl;
    for(int i = 0; i < non_zeroes + 1; i++){
        for(int j = 0; j < 3; j++){
            cout<<compactMatrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}