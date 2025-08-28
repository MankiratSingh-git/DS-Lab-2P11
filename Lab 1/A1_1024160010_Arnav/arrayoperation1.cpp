#include <iostream>
using namespace std;

int data[100], size = 0;
void make_array() {
    cout << "enter number of elements: ";
    cin >> size;
    cout << "enter elements: ";
    for (int i = 0; i < size; i++) cin >> data[i];
}
void show() {
    cout << "array: ";
    for (int i = 0; i < size; i++) cout << data[i] << " ";
    cout << "\n";
}
void insert_elem() {
    int pos, val;
    cout << "enter position and value: ";
    cin >> pos >> val;
    for (int i = size; i > pos; i--) data[i] = data[i - 1];
    data[pos] = val;
    size++;
}
void erase_elem() {
    int pos;
    cout << "enter position: ";
    cin >> pos;
    for (int i = pos; i < size - 1; i++) data[i] = data[i + 1];
    size--;
}
void search_linear() {
    int key, found = 0;
    cout << "enter value to search: ";
    cin >> key;
    for (int i = 0; i < size; i++) {
        if (data[i] == key) {
            cout << "found at position " << i << "\n";
            found = 1;
        }
    }
    if (!found) cout << "not found\n";
}
int main() {
    int choice;
    while (true) {
        cout << "\n1. create\n2. display\n3. insert\n4. delete\n5. linear search\n6. exit\n";
        cin >> choice;
        switch (choice) {
            case 1: make_array(); break;
            case 2: show(); break;
            case 3: insert_elem(); break;
            case 4: erase_elem(); break;
            case 5: search_linear(); break;
            case 6: return 0;
            default: cout << "invalid choice\n";
        }
    }
}
