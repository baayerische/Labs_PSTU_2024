#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cout << "num1: ";
	cin >> a;
	cout << "num2: ";
	cin >> b;
	int* ptr1, *ptr2;
	ptr1 = &a;
	ptr2 = &b;
	cout << *ptr1 + *ptr2 << endl;
	return 0;
}
