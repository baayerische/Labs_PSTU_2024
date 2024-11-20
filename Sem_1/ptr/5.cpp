#include <iostream>
using namespace std;
int main()
{
	unsigned int a, * ptr1, * ptr2, fac = 1;
	cout << "number: ";
	cin >> a;
	ptr1 = &a;
	ptr2 = &fac;
	for (int i = 1; i <= a; i++)
	{
		*ptr2 *= i;
	}
	cout << "fac:" << *ptr2 << endl;
	return 0;
}