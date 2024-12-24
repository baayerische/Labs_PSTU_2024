#include <iostream>
using namespace std;
#include <cmath>
int main()
{
	setlocale(LC_ALL, "Rus");
	int tmp, next;
	bool ordered = true;
	cin >> tmp;
	while (tmp != 0)
	{
		cin >> next;
		if (next != 0 && tmp > next)
		{
			ordered = false;
		}
		tmp = next;
	}
	if (ordered)
	{
		cout << "ѕоследовательность упор€дочена по возрастанию" << endl;
	}
	else
	{
		cout << "ѕоследовательность не упор€дочена по возрастанию" <<endl;
	}
}