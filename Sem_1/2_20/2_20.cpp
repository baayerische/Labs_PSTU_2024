#include <iostream>
using namespace std;
#include <cmath>
int main()
{
	setlocale(LC_ALL, "Rus");
	float n, s, a;
	int i = 1;
	bool flag = false;
	cout << "������� n, s:" << endl;
	cin >> n >> s;
	while (i <= n && !flag)
	{
		a = sin(n + i / n);
		a = round(a * 10) / 10;
		cout << n + i / n << "|" << a << endl;
		if (a == s) 
		{
			flag = true; 
		}
		else 
		{
			i++; 
		}
	}
	if (flag)
	{
		cout << "������� ������!" << endl;
	}
	else
	{
		cout << "������� �� ������!" << endl;
	}
	return 0;
}