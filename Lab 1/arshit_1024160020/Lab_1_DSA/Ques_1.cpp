#include<iostream>
#include<climits>
using namespace std;

int arr[100];
int n=0;

void create()
{
    cout<<"Enter the number of elements:"<<endl;
    cin>>n;
    if(n>100)
    {
        cout<<"Array size exceeded"<<endl;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
    }

}
void display()
{
    cout<<"Array's elements are:";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void insert()
{
    if(n>=100)
    {
        cout<<"Array is full"<<endl;
    }
    int pos, val;
    cout<<"Enter Positon where u want to add element:"<<endl;
    cin>>pos;
    if(pos<1||pos>100)
    {
        cout<<"Invalid position"<<endl;
    }
    cout<<"Enter Value:"<<endl;
    cin>>val;
    for(int i=n;i>pos;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos - 1] = val;
    n++;
}

void deleteelemnt()
{
    int pos;
    cout<<"Enter element you want to delete"<<endl;
    cin>>pos;
    if (pos < 0 || pos >= n) 
    {
            cout << "Invalid position!" << endl;
            return;
    }

    for(int i=pos;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
}

void linearSearch()
{
    int ele;
    cout<<"Entetr the element"<<endl;
    cin>>ele;

    for(int i=0;i<n;i++)
    {
        if(arr[ele] == ele)
        {
            cout<<"Element found at "<<i<<endl;
        }
    }    
        {
            cout<<"Element not  found"<<endl;
        }
    
}

int main() 
{
    int choice;
    do{                      
        cout << "\n——— MENU ———\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1: create(); 
            break;
            case 2: display(); 
            break;
            case 3: insert(); 
            break;
            case 4: deleteelemnt(); 
            break;
            case 5: linearSearch(); 
            break;
            case 6: cout << "Exiting program..." << endl;
            default: cout << "Invalid choice!" << endl;
        }
    }
    while(choice != 6);
}



