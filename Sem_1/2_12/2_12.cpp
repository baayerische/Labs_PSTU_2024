#include <iostream>
using namespace std;
int main()
{
	int n, tmp, max, min;
	cout << "enter length:" << endl;
	cin >> n;
	cout << "num 1:" << endl;
	cin >> tmp;
	max = tmp;
	min = tmp;
	for (int i = 2; i <= n; i++)
	{
		cout << "next num:" << endl;
		cin >> tmp;
		if (tmp > max)
		{
			max = tmp;
		}
		else if (tmp < min)
		{
			min = tmp;
		}
	}
	cout << "min + max = " << (max + min) << endl;
	return 0;
}