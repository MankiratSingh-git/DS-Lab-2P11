#include <iostream>
using namespace std;
#define MAX_SIZE 20
int arr[MAX_SIZE], n=0;

//create the array
void create(){
    cout<<"Number of elements (between 1 and 20): ";
    cin>>n;
    if (n>MAX_SIZE){
        cout<<"Maximum size exceeded. Please enter value between 1 and 20.";
        n=0;
        return;
    }
    cout<<"Enter values of the elements\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

//display array
void display() {
    if (n==0){
        cout<<"Array is empty\n";
        return;
    }
    cout<<"Your array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//insert element
void insert(){
    int pos, elem;
    cout<<"Enter position: ";
    cin>>pos;
    if(pos>n || pos<0){
        cout<<"Invalid value of position. Enter a value between 0 and"<<n<<": ";
        return;
    }
    cout<<"Enter element to be inserted: ";
    cin>>elem;
    for(int i=n; i>pos;i--){
        arr[i]=arr[i-1];
    }
        arr[pos]=elem;
        n++;
        cout<<"Element inserted\n";
    }
    
    //delete element
    void del(){
        if (n==0){
            cout<<"Array is empty";
            return;
        }
        int pos;
        cout<<"Enter postion to delete (0 to "<<n-1<<"): ";
        cin>>pos;
        if (pos<0 || pos>n-1){
            cout<<"Invalid postion. \n";
            return;
        }
        for(int i=pos; i<n-1; i++){
            arr[i]=arr[i+1];
        }
        n--;
        cout<<"Element deleted.\n";
    }
    
    //linear search
    void search(){
        if (n==0){
            cout<<"Empty array";
            return;
        }
        int val, found=0;
        cout<<"Enter value of element to be searched ";
        cin>>val;
        for (int i=0; i<n-1; i++){
            if(arr[i]==val){
                cout<<"The position of the element is "<<i<<endl;
                found=1;
                break;
            }
        }
        if(found!=1){
        cout<<"Element not found\n";
            }
    }

int main() {
    int choice;
    do{
   cout<<"MENU\n";
   cout<<"1.Create\n2.Display\n3.Insert\n4.Delete\n5.Linear search\n6.Exit\n";
   cout<<"Enter number of task: ";
   cin>>choice;
   switch (choice){
       case 1: create(); break;
       case 2: display(); break;
       case 3: insert(); break;
       case 4: del(); break;
       case 5: search(); break;
       case 6: cout<<"Exiting program\n"; break;
       default: "Invalid input";
   }
   cout<<endl;
   }while(choice!=6);
return 0;
}
