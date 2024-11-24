#include <iostream>
using namespace std;
int main()
{
	float a;
	cin >> a;
	if (a<5)
	{
		cout << a*3 << endl;
		return 0;
	}
	else if (a > 7)
	{
		cout << a+3 << endl;
		return 0;
	}
	else
	{
		cout << a/10 << endl;
		return 0;
	}
}
