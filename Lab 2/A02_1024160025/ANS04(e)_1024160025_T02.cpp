#include<iostream>
#include<cctype>
using namespace std;
int main(){
	char chr;
	cout<<"Enter a uppercase character";
	cin>>chr;
	if(chr>='A' && chr<='Z'){
		char chrlowercase=tolower(chr);
		cout<<"The lowercase character for given character is:"<<chrlowercase<<endl;
	}else
	{
		cout<<"The character entered is laready in lowercase."<<endl;
	}
	return 0;
	}
	
