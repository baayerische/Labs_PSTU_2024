#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low >= high) return;
	int pI = partition(arr, low, high);
	quickSort(arr, low, pI - 1);
	quickSort(arr, pI + 1, high);
}

int main()
{
	setlocale(LC_ALL, "RU");
	int arr[] = { 29, 25, 3, 49, 9, 37, 21, 43 };

	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	quickSort(arr, 0, 4);

	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}