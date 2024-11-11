#include <iostream>
using namespace std;
int main()
{
	float a, b;
	cin >> a >> b;
	if (b == 0)
	{
		cout << "Error" << endl;
		return 0;
	}
	else
	{
		cout << a / b << endl;
		return 0;
	}
}