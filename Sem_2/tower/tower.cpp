#include <iostream>
using namespace std;

void hanoi(int n, char start, char temp, char point)
{
    setlocale(LC_ALL, "rus");
    if (n == 1) 
    {
        cout << "����������� �������� 1 � " << start << " �� " << temp << endl;
        return;
    }
    hanoi(n - 1, start, point, temp);
    cout << "����������� �������� " << n << " � " << start << " �� " << temp << endl;
    hanoi(n - 1, point, temp, start);
}

int main() 
{
    setlocale(LC_ALL, "rus");
    int n;
    cout << "������� ���������� �������: ";
    cin >> n;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}