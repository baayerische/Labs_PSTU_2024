#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cout << "num1: ";
	cin >> a;
	cout << "num2: ";
	cin >> b;
	int* ptr1;
	int* ptr2;
	int* ptr3;
	ptr1 = &a;
	ptr2 = &b;
	ptr3 = ptr1;
	ptr1 = ptr2;
	ptr2 = ptr3;
	cout << "n1:" << *ptr1 << " " << "n2:" << *ptr2 << endl;
	return 0;
}