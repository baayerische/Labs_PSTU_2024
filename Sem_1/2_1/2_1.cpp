#include <iostream>
using namespace std;
int main()
{
	int a, sum;
	cin >> a;
	int i = 0;
	sum = 0;
	while (i <= a)
	{
		sum += i;
		i++;
	}
	cout << sum << endl;
	return 0;
}