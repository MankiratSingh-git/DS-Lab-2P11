#include <iostream>
using namespace std;
int main(){
	char string[50];
	cout<<"Enter a string : ";
	cin>>string;
	int n=0;
	for(int i=0;string[i]!='\0';i++){
		char c=string[i];
		if(!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')){
			string[n++]=string[i];
		}
		
	}
	string[n]='\0';
	cout<<"new string : "<<string<<endl;
	return 0;
}
