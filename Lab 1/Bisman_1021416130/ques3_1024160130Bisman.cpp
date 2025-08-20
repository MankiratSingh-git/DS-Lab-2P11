/*
Name: Bisman Singh Rai
Roll No: 1024160130
Program: Predict the output of given array initialization program
*/

#include <stdio.h>

int main() {
    int i;
    int arr[5] = {1}; // First element set to 1, rest default to 0
    for (i = 0; i < 5; i++)
        printf("%d", arr[i]);
    return 0;
}

/*
Explanation:
- `int arr[5] = {1};` means arr[0] = 1, all others = 0 by default.
- Loop prints each element without spaces.
- Output: 10000
*/
