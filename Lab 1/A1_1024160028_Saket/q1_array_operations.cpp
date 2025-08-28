#include <iostream>

using namespace std;
constexpr int max_len = 100; // complie time constant for array.
int array[max_len];
int size_array = 0;

void createArray(int array[], int size) {
    if (size <= 0 || size > max_len) {
        cout << "Size of array is invalid" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << "Enter the " << i + 1 << " element: ";
        cin >> array[i];
    }
    cout << "Array is created successfully" << endl;
}

void displayArray(int array[], int size) {
    if (size <= 0) {
        cout << "Array is empty. Please create it first." << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << "The " << i + 1 << " element of array is " << array[i] << endl;
    }
    
    cout<<'\n';
}

void insertElement() {
    if (size_array >= max_len) {
        cout << "Array is full\n";
        return;
    }

    int pos, value;
    cout << "Enter position to insert (1-" << size_array + 1 << "): ";
    cin >> pos;

    if (pos < 1 || pos > size_array + 1) {
        cout << "Invalid position.\n";
        return;
    }

    cout << "Enter value to insert: ";
    cin >> value;

    for (int i = size_array; i >= pos; i--) {
        array[i] = array[i - 1];   // swaping the digits
    }
    array[pos - 1] = value;
    size_array++;
    cout << "Element inserted successfully.\n";
}
void deleteElement() {
    if (size_array == 0) {
        cout << "Array is empty. Cannot delete.\n";
        return;
    }

    int pos;
    cout << "Enter position to delete (1-" << size_array << "): ";
    cin >> pos;

    if (pos < 1 || pos > size_array) {
        cout << "Invalid position.\n";
        return;
    }

    for (int i = pos - 1; i < size_array - 1; i++) {
        array[i] = array[i + 1];
    }
    size_array--;
    cout << "Element deleted successfully.\n";
}

void linearSearch(){

    cout<<"What element you want to search?"<<endl;
    int element;
    cin>>element;
    for(int j=0 ; j<size_array ; j++){
        if(array[j]==element){
            cout<<"element is found at "<<j+1<<"position"<<endl;
            return;
        }
        else{
            continue;
        }
    }

}

int main() {
    int choice_option;
    do {
         cout<<"Welcome to array operation menu"<<endl;
        cout << "\n-----MENU------\n";
        cout << "1. CREATE" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "3. INSERT" << endl;
        cout << "4. DELETE" << endl;
        cout << "5. LINEAR SEARCH" << endl;
        cout << "6. EXIT" << endl;

        cout << "What do you want to do? (1-6): ";
        cin >> choice_option;

        switch (choice_option) {
            case 1:
                cout << "What is the size of your array? (1-" << max_len << "): ";
                cin >> size_array;
                createArray(array, size_array);
                break;

            case 2:
                displayArray(array, size_array);
                break;
            

            case 3: 
                insertElement();
                break;

            case 4 :
                deleteElement();
                break;

            case 5: 
                linearSearch();
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice_option != 6);

    return 0;
}
