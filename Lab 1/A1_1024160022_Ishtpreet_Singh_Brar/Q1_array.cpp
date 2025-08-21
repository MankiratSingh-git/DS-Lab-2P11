#include <iostream>
#include <vector>
using namespace std;

int create(vector<int> &arr);
void display(vector<int> &arr, int);
void Insert(vector<int> &arr, int);
void Delete(vector<int> &arr, int);
void Search(vector<int> &arr, int);

int main()
{
    int size;
    vector<int> arr; // initially empty

    size =create(arr);

    int operation = 2;
    while (operation != 1)
    {
        cout << endl
             << R"(   --MENU--
        1.EXIT
        2. DISPLAY
        3. INSERT
        4. DELETE
        5. LINEAR SEARCH
        :  )";

        cin >> operation;
        if (operation < 1 || operation > 5)
        {
            cout << "Invalid try again" << endl;
            continue;
        }
        else if (operation == 1)
        {
            cout << "END" << endl;
            break;
        }
        else if (operation == 2)
        {
            display(arr, size);
        }
        else if (operation == 3)
        {
            size++;
            Insert(arr, size);
        }
        else if (operation == 4)
        {
            Delete(arr, size);
            size--;
        }
        else if (operation == 5)
        {
            Search(arr, size);
        }
        else
        {
            cout << "NOpE";
            break;
        }
    }

    return 0;
}
int create(vector<int> &arr)
{   int size=-1;
    cout << "Enter elements , till -999 "
         << endl;
    int temp;
    for (int i = 0;temp!=-999 && size <100; i++)
    {
        cin >> temp;
        arr.push_back(temp); // adds element at the end
        size ++;
    }
    return size;
}

void display(vector<int> &arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
void Insert(vector<int> &arr, int size)
{
    cout << "ENter location to add : ";
    int location;
    cin >> location;
    cout << "ENter the number : ";
    int num;
    cin >> num;
    int i = size;
    for (i; i > location - 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[i] = num;
}
void Delete(vector<int> &arr, int size)
{
    cout << "Enter location of element to delete : ";
    int location;
    cin >> location;
    for (int i = location-1; i < size-1; i++)
    {   
        arr[i] = arr[i+1];
    }
    cout<<"Done";
}
void Search(vector<int> &arr, int size)
{
    cout<<"Enter number to find : ";
    int num;
    cin>>num;
    bool label= false;
    for (int i=0;i<size;i++){
        if(num== arr[i]){
            cout<<"Foud at location :"<<i+1<<endl;
            label = true;
        }
    }
    if (label == false){
        cout<<"not found"<<endl;
    }
}