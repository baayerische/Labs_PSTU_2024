#include <iostream>
using namespace std;
int main()
{
	int a, p;
	cin >> a;
	int i = 1;
	p = 1;
	while (i <= a)
	{
		p *= i;
		i++;
	}
	cout << p << endl;
	return 0;
}