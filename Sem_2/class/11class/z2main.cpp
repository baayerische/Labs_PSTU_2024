#include <iostream>
#include <vector>
#include "Money.h"
using namespace std;

typedef vector<Money> Vec;

// Формирование вектора
Vec make_vector(int n) {
    Vec v;
    for (int i = 0; i < n; i++) {
        Money m;
        cout << "Enter money " << i + 1 << " (rub,kop): ";
        cin >> m;
        v.push_back(m);
    }
    return v;
}

// Печать вектора
void print_vector(const Vec& v) {
    for (const Money& m : v) {
        cout << m << " ";
    }
    cout << endl;
}

// Поиск элемента с заданным ключом
vector<Money>::iterator find_key(Vec& v, const Money& key) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (*it == key) {
            return it;
        }
    }
    return v.end();
}

// Добавление элемента с заданным ключом на заданную позицию
void add_key_at_position(Vec& v, const Money& key, int pos) {
    v.insert(v.begin() + pos, key);
}

// Удаление элемента с заданным ключом
void remove_key(Vec& v, const Money& key) {
    auto it = find_key(v, key);
    if (it != v.end()) {
        v.erase(it);
    }
}

// Вычисление разницы между максимальным и минимальным элементами
Money compute_max_min_diff(const Vec& v) {
    if (v.empty()) return Money(0, 0);
    Money max_val = v[0], min_val = v[0];
    for (const Money& m : v) {
        if (m > max_val) max_val = m;
        if (m < min_val) min_val = m;
    }
    long rub_diff = max_val.getRub() - min_val.getRub();
    int kop_diff = max_val.getKop() - min_val.getKop();
    if (kop_diff < 0) {
        rub_diff--;
        kop_diff += 100;
    }
    return Money(rub_diff, kop_diff);
}

// Вычитание разницы из каждого элемента
void subtract_diff(Vec& v) {
    Money diff = compute_max_min_diff(v);
    Vec temp;
    for (const Money& m : v) {
        long new_rub = m.getRub() - diff.getRub();
        int new_kop = m.getKop() - diff.getKop();
        if (new_kop < 0) {
            new_rub--;
            new_kop += 100;
        }
        temp.push_back(Money(new_rub, new_kop));
    }
    v = temp;
}

int main() {
    int n;
    cout << "Enter the number of elements (n): ";
    cin >> n;

    Vec v = make_vector(n);
    cout << "Initial vector: ";
    print_vector(v);

    // Задание 3: Добавить элемент с заданным ключом на заданную позицию
    Money key;
    int pos;
    cout << "Enter key to find and add (rub,kop): ";
    cin >> key;
    cout << "Enter position to add (0 to " << n << "): ";
    cin >> pos;
    auto it = find_key(v, key);
    if (it != v.end()) {
        add_key_at_position(v, key, pos);
        cout << "Vector after adding key at position: ";
        print_vector(v);
    }
    else {
        cout << "Key not found!" << endl;
    }

    // Задание 4: Удалить элемент с заданным ключом
    cout << "Enter key to remove (rub,kop): ";
    cin >> key;
    remove_key(v, key);
    cout << "Vector after removing key: ";
    print_vector(v);

    // Задание 5: Вычесть разницу между максимальным и минимальным
    subtract_diff(v);
    cout << "Vector after subtracting max-min difference: ";
    print_vector(v);

    return 0;
}