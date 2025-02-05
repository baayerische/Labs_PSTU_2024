#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int r, range_min, range_max, key;
	int arr[10];
	range_min = 2;
	range_max = 280000;
	int n = 10;
	for (int i = 0; i < 10; i++)
	{
		arr[i] = ((double)rand() / RAND_MAX) * (range_max -
			range_min) + range_min;
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		key = arr[i];
		cout << "key : " << key << endl;
		int j = i - 1;
		cout << "Entered in cycle:\n";
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			cout << "need an exchange:\n";
			j--;
		}
		arr[j + 1] = key;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}