#include<iostream>
using namespace std;

void createArray(int arr[] ,int n)
{
   

    cout<<"enter the elements of array" <<endl;
    for(int i= 0;i<n;i++)
    {
        cin>>arr[i];
    }


}

void displayArray(int arr[],int n)
{
    cout<<"the elements of array are" <<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertElement(int arr[],int n,int value,int pos)
{
    if(pos < 0 || pos > n) {
        cout << "Invalid position!" << endl;
        return;
    }
    
    for(int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos-1] = value;
    n++;
    cout<<"the value of n"<<n<<endl;
}
void deleteElement(int arr[], int n, int pos) {
    if(pos < 0 || pos >= n) {
        cout << "Invalid position!" << endl;
        return;
    }
    
    for(int i = pos-1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}
void linearSearch(int arr[],int n,int value)
{
   bool found = false;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==value)
        {
            cout<<"element found at position "<<i+1<<endl;
            found = true;
            break;
        }
    }
    if(found == false)
    {
        cout<<"element not found"<<endl;
    }
}
int main()
{
     int n;
     int arr[100];
    cout<<"enter the size of array" <<endl;
    cin>>n;
    
    createArray(arr,n);
    displayArray(arr,n);
    cout<<"enter the element to be inserted" <<endl;
    int value;
    cin>>value;
    cout<<"enter the position at which to insert the element" <<endl;
    int pos;
    cin>>pos;
    insertElement(arr, n, value, pos);
    n++; 
    displayArray(arr, n);


    return 0;
}
  