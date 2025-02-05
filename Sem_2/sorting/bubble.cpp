#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{
	int r, range_min, range_max, tmp;
	srand(time(0));
	const int n = 3;
	
	int arr[n][n];
	range_min = 2;
	range_max = 280000;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = n - 2; k >= 0; k--)
			{
				if (arr[j][k] > arr[j][k + 1])
				{
					tmp = arr[j][k];
					arr[j][k] = arr[j][k + 1];
					arr[j][k + 1] = tmp;
				}
			}

		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
