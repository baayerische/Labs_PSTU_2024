#include <iostream>
using namespace std;
int main()
{
	float a, b;
	cout << "num1: ";
	cin >> a;
	cout << "num2: ";
	cin >> b;
	float* ptr1;
	float* ptr2;
	ptr1 = &a;
	ptr2 = &b;
	cout << *ptr1 + *ptr2 << endl;
	return 0;
}