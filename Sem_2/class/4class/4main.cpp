#include <iostream>
#include "Triad.h"
#include "Date.h"

using namespace std;

void compare_triad(Triad& t) {
    Triad ref(2023, 1, 1);
    if (t == ref) cout << "\nTriad равен (2023, 1, 1)\n";
    else if (t < ref) cout << "\nTriad меньше (2023, 1, 1)\n";
    else cout << "\nTriad больше (2023, 1, 1)\n";
}

Triad create_triad() {
    Date d(2024, 12, 31);
    return d;
}

int main() {
    setlocale(LC_ALL, "RU");
    Triad t1;
    cout << "Введите данные для Triad:\n";
    cin >> t1;
    cout << "Triad:\n" << t1;

    Triad t2(1, 2, 3);
    cout << "Triad t2(1, 2, 3):\n" << t2;
    t1 = t2;
    cout << "Triad t1 после присваивания t2:\n" << t1;

    Date d1;
    cout << "\nВведите данные для Date (год, месяц, день):\n";
    cin >> d1;
    cout << "Date:\n" << d1;

    Date d2(2023, 5, 10);
    cout << "Date d2(2023, 5, 10):\n" << d2;

    cout << "\nСравнение дат d1 и d2:\n";
    if (d1 == d2) cout << "Даты равны\n";
    else if (d1 < d2) cout << "d1 раньше d2\n";
    else cout << "d1 позже d2\n";

    cout << "\nПринцип подстановки:\n";
    compare_triad(d1); 
    t1 = create_triad();
    cout << "Triad после возврата Date:\n" << t1;

    return 0;
}