#include <iostream>
using namespace std;
int main(){
    int a[10][10], m, n;
    cin>>m>>n;
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>a[i][j];

    for(int i=0;i<m;i++){
        int rowSum=0;
        for(int j=0;j<n;j++) rowSum+=a[i][j];
        cout<<"Row "<<i<<" sum = "<<rowSum<<"\n";
    }
    for(int j=0;j<n;j++){
        int colSum=0;
        for(int i=0;i<m;i++) colSum+=a[i][j];
        cout<<"Col "<<j<<" sum = "<<colSum<<"\n";
    }
}