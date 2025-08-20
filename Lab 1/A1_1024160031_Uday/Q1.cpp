#include <iostream>
using namespace std;
int arr[100], n=0;

void create(){
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];
}
void display(){
    cout<<"Array: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<"\n";
}
void insert(){
    int pos, val;
    cout<<"Enter position & value: ";
    cin>>pos>>val;
    for(int i=n;i>pos;i--) arr[i]=arr[i-1];
    arr[pos]=val; n++;
}
void del(){
    int pos;
    cout<<"Enter position: ";
    cin>>pos;
    for(int i=pos;i<n-1;i++) arr[i]=arr[i+1];
    n--;
}
void linear_search(){
    int val, flag=0;
    cout<<"Enter value to search: ";
    cin>>val;
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            cout<<"Found at "<<i<<"\n";
            flag=1;
        }
    }
    if(!flag) cout<<"Not found\n";
}

int main(){
    int ch;
    while(1){
        cout<<"\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cin>>ch;
        switch(ch){
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: del(); break;
            case 5: linear_search(); break;
            case 6: return 0;
            default: cout<<"Invalid choice\n";
        }
    }
}