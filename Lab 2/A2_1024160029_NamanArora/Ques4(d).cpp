#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int NUM_WORDS = 5;
    string words[NUM_WORDS] = {"Banana", "Apple", "Cherry", "Date", "Fig"};
    cout << "Original list of strings:" << endl;
    for (int i = 0; i < NUM_WORDS; i++)
    {
        cout << words[i] << endl;
    }
    for (int i = 0; i < NUM_WORDS - 1; i++)
    {
        for (int j = 0; j < NUM_WORDS - i - 1; j++)
        {
            if (words[j] > words[j + 1])
            {
                string temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
    cout << "\nSorted list of strings:" << endl;
    for (int i = 0; i < NUM_WORDS; i++)
    {
        cout << words[i] << endl;
    }
    return 0;
}
