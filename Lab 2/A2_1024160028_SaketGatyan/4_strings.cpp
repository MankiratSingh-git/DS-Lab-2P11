#include<iostream>
using namespace std;
int deleteElement(int size,int pos,char arr[]){
    for(int i=pos;i<size-1;i++){
        arr[i] = arr[i+1];
    }
    size--;
    arr[size] = '\0';
    return size;
}
int deleteVowel(int size,char arr[]){
    // lets take a vowel array
    char vowel[] = {'a','e','i','o','u','A','E','I','O','U'};
    int vow = sizeof(vowel)/sizeof(char);
    for(int i=0;i<size;i++){
        for(int j=0;j<vow;j++){
            if(arr[i]==vowel[j]){
                size = deleteElement(size,i,arr);
                i--;
                break;
            }
        }
    }
    return size;
}
int main(){
    //(a)

    /*
    string first_name ;
    string last_name;
    cout<<"enter your first name"<<"\n"; cin>>first_name;
    cout<<"enter your last name"<<"\n"; cin>>last_name;
    string name = first_name+ " " + last_name;
    cout<<"Your name is "<<name;

    */
   //(b)

   /*
   string name  = "Saket Gatyan";
   int size = name.length();
   
   for(int i =0;i<size/2;i++){
        //printing
        //cout<<name[i]<<"";
        //swap and print
        
        char temp = name[i];
        name[i] = name[size - i - 1];
        name[size - i - 1] = temp;

    }
    cout<<name;

    */ 
   
    /*(c)
    char str[] = "Saket";
    int size = 6; // including '\0' at end

    size = deleteVowel(size - 1, str); // exclude null terminator

    cout<<"After removing vowels"<<"\n"<<str;

    */



    

}