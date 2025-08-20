#include <iostream>
using namespace std;

void binaryserach(int arr[], int n, int s)
{
	int mid;
	int l = 0;
	int h = n - 1;
	while (l <= h)
	{
		mid = (l + h) / 2;
		if (arr[mid] == s)
		{
			cout << "Element found at the place : " << mid << endl;
			return;
		}
		else if (arr[mid] < s)
		{
			l = mid + 1;
		}
		else if (arr[mid] > s)
		{
			h = mid - 1;
		}
	}
	cout << "Element not found in the array";
}

int main()
{
	int n = 5;
	int s;
	int arr[5] = {1, 2, 3, 4, 5};
	cout << "Type the number to be serached in the array : ";
	cin >> s;
	binaryserach(arr, n, s);
}
