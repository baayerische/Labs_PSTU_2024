#include <iostream>

using namespace std;

void shellSort(int arr[], int n)
{
	for (int h = n / 2; h >= 1; h /= 2)
	{
		for (int i = h; i < n; i++)
		{
			int key = arr[i];
			int j;

			for (j = i; j >= h && arr[j - h] > key; j -= h)
			{
				arr[j] = arr[j - h];
			}

			arr[j] = key;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RU");
	int arr[] = { 29, 25, 3, 49, 9, 37, 21, 43 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Исходный массив: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	shellSort(arr, n);

	cout << "Отсортированный массив: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}