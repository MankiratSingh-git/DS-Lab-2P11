#include <iostream>
using namespace std;

int main() {
    int mat1[4][4] = {
        {0, 0, 4, 0},
        {3, 0, 0, 0},
        {0, 5, 0, 0},
        {0, 0, 0, 7}
    };

    int mat2[4][4] = {
        {1, 0, 0, 2},
        {0, 0, 6, 0},
        {0, 0, 0, 0},
        {0, 8, 0, 0}
    };

    int triplet1[10][3], triplet2[10][3], result[20][3];
    int k1=1, k2=1;

    // Convert mat1 → triplet1
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(mat1[i][j]!=0){
                triplet1[k1][0]=i;
                triplet1[k1][1]=j;
                triplet1[k1][2]=mat1[i][j];
                k1++;
            }
        }
    }
    triplet1[0][0]=4; triplet1[0][1]=4; triplet1[0][2]=k1-1;

    // Convert mat2 → triplet2
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(mat2[i][j]!=0){
                triplet2[k2][0]=i;
                triplet2[k2][1]=j;
                triplet2[k2][2]=mat2[i][j];
                k2++;
            }
        }
    }
    triplet2[0][0]=4; triplet2[0][1]=4; triplet2[0][2]=k2-1;

    // Add triplets
    int i=1, j=1, k=1;
    while(i<k1 && j<k2){
        if(triplet1[i][0]<triplet2[j][0] || 
           (triplet1[i][0]==triplet2[j][0] && triplet1[i][1]<triplet2[j][1])){
            result[k][0]=triplet1[i][0];
            result[k][1]=triplet1[i][1];
            result[k][2]=triplet1[i][2];
            i++; k++;
        }
        else if(triplet2[j][0]<triplet1[i][0] || 
                (triplet2[j][0]==triplet1[i][0] && triplet2[j][1]<triplet1[i][1])){
            result[k][0]=triplet2[j][0];
            result[k][1]=triplet2[j][1];
            result[k][2]=triplet2[j][2];
            j++; k++;
        }
        else {
            result[k][0]=triplet1[i][0];
            result[k][1]=triplet1[i][1];
            result[k][2]=triplet1[i][2]+triplet2[j][2];
            i++; j++; k++;
        }
    }
    while(i<k1){ result[k][0]=triplet1[i][0]; result[k][1]=triplet1[i][1]; result[k][2]=triplet1[i][2]; i++; k++; }
    while(j<k2){ result[k][0]=triplet2[j][0]; result[k][1]=triplet2[j][1]; result[k][2]=triplet2[j][2]; j++; k++; }
    result[0][0]=4; result[0][1]=4; result[0][2]=k-1;

    // Print
    cout<<"Matrix 1:\n";
    for(int i=0;i<4;i++){ for(int j=0;j<4;j++) cout<<mat1[i][j]<<" "; cout<<endl; }

    cout<<"\nMatrix 2:\n";
    for(int i=0;i<4;i++){ for(int j=0;j<4;j++) cout<<mat2[i][j]<<" "; cout<<endl; }

    cout<<"\nTriplet Result (Addition):\n";
    for(int x=0;x<k;x++){
        cout<<result[x][0]<<" "<<result[x][1]<<" "<<result[x][2]<<endl;
    }

    cout<<"\nAdded Matrix:\n";
    int added[4][4] = {0};
    for(int x=1;x<k;x++){
        added[result[x][0]][result[x][1]]=result[x][2];
    }
    for(int i=0;i<4;i++){ for(int j=0;j<4;j++) cout<<added[i][j]<<" "; cout<<endl; }

    return 0;
}
