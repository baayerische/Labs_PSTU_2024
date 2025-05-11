#include <iostream>
#include "Object.h"
#include "Triad.h"
#include "Date.h"
#include "Vector.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    Triad t1;
    cout << "Введите данные для Triad:\n";
    cin >> t1;
    cout << "Triad с помощью operator<<:\n" << t1;
    Object* p = &t1;
    cout << "Triad с помощью Show():\n";
    p->Show();

    Date d1;
    cout << "\nВведите данные для Date (год, месяц, день):\n";
    cin >> d1;
    cout << "Date с помощью operator<<:\n" << d1;
    p = &d1;
    cout << "Date с помощью Show():\n";
    p->Show();

    Date d2(2023, 5, 10);
    cout << "\nСравнение дат:\n";
    if (d1 == d2) cout << "Даты равны\n";
    else if (d1 < d2) cout << "Первая дата раньше\n";
    else cout << "Первая дата позже\n";

    Vector v(5);
    v.Add(&t1);
    v.Add(&d1);
    cout << "\nСодержимое вектора:\n" << v;

    return 0;
}