#include<iostream>
using namespace std;
int main(){
	int matrix1[4][3]={
	{0,1,3},
	{1,0,2},
	{1,2,4},
	{2,3,1}
};
int n=4;
int matrix2[4][3]={
{0,2,5},
{1,0,1},
{2,1,3},
{3,3,2}
};
int m=4;
int tmatrix2[50][3];
int p=0;
for(int col=0;col<4;++col){
	for(int i=0;i<m;++i){
		if(matrix2[i][1]==col){
			tmatrix2[p][0]=matrix2[i][1];
			tmatrix2[p][1]=matrix2[i][0];
			tmatrix2[p][2]=matrix2[i][2];
			p++;
		}
	}
}

int rmatrix[50][3];
int k=0;
for(int i=0;i<n;++i){
	for(int j=0;j<p;++j){
		if (matrix1[i][1]==tmatrix2[j][0]){
			int sum=matrix1[i][2]*tmatrix2[j][2];
			bool found =false;
			for(int i=0;i<k;++i){
				if (rmatrix[1][0]==matrix1[i][0]&& rmatrix[i][1]==tmatrix2[j][1]){
					rmatrix[1][2]+=sum;
					found=true;
					break;
				}
			}
			if(!found && sum!=0){
				rmatrix[k][0]=matrix1[i][0];
				rmatrix[k][1]=tmatrix2[j][1];
				rmatrix[k][2]=sum;
				k++;
			}
		}
	}
}
cout<<"resultant matrix"<<endl;
for(int i=0;i<k;++i){
	cout<<rmatrix[1][0]<<" "<<rmatrix[i][1]<<" "<<rmatrix[i][2]<<endl;
}
return 0;
}


