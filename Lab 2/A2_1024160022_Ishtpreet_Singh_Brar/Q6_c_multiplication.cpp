#include <iostream>
using namespace std;

int main() {
    int mat1[3][3] = {
        {1, 0, 2},
        {0, 3, 0},
        {4, 0, 5}
    };

    int mat2[3][3] = {
        {7, 0, 0},
        {0, 8, 0},
        {0, 0, 9}
    };

    int res[3][3] = {0};

    // Multiply mat1 * mat2
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Convert result into triplet
    int triplet[20][3];
    int t=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(res[i][j]!=0){
                triplet[t][0]=i;
                triplet[t][1]=j;
                triplet[t][2]=res[i][j];
                t++;
            }
        }
    }
    triplet[0][0]=3; triplet[0][1]=3; triplet[0][2]=t-1;

    // Print
    cout<<"Matrix 1:\n";
    for(int i=0;i<3;i++){ for(int j=0;j<3;j++) cout<<mat1[i][j]<<" "; cout<<endl; }

    cout<<"\nMatrix 2:\n";
    for(int i=0;i<3;i++){ for(int j=0;j<3;j++) cout<<mat2[i][j]<<" "; cout<<endl; }

    cout<<"\nTriplet Result (Multiplication):\n";
    for(int i=0;i<t;i++){
        cout<<triplet[i][0]<<" "<<triplet[i][1]<<" "<<triplet[i][2]<<endl;
    }

    cout<<"\nMultiplied Matrix:\n";
    for(int i=0;i<3;i++){ for(int j=0;j<3;j++) cout<<res[i][j]<<" "; cout<<endl; }

    return 0;
}
