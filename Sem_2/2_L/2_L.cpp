#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");

	bool simm = 1;
	int tmp;
	const int n = 5;
	int a[n][n] =
	{
	{1, 1, 1, 1, 1},
	{1, 2, 2, 2, 2},
	{1, 2, 3, 3, 3},
	{1, 2, 3, 4, 4},
	{1, 2, 3, 4, 5}
	};

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i][j] != a[j][i])
				simm = 0;
			tmp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = tmp;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	if (simm == 0)
		cout << "матрица не симметрична" << endl;
	
	else
		cout << "матрица симметрична" << endl;
	return 0;
}