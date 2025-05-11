#include <iostream>
#include "Object.h"
#include "Triad.h"
#include "Date.h"
#include "Vector.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    Triad t1;
    cout << "������� ������ ��� Triad:\n";
    cin >> t1;
    cout << "Triad � ������� operator<<:\n" << t1;
    Object* p = &t1;
    cout << "Triad � ������� Show():\n";
    p->Show();

    Date d1;
    cout << "\n������� ������ ��� Date (���, �����, ����):\n";
    cin >> d1;
    cout << "Date � ������� operator<<:\n" << d1;
    p = &d1;
    cout << "Date � ������� Show():\n";
    p->Show();

    Date d2(2023, 5, 10);
    cout << "\n��������� ���:\n";
    if (d1 == d2) cout << "���� �����\n";
    else if (d1 < d2) cout << "������ ���� ������\n";
    else cout << "������ ���� �����\n";

    Vector v(5);
    v.Add(&t1);
    v.Add(&d1);
    cout << "\n���������� �������:\n" << v;

    return 0;
}