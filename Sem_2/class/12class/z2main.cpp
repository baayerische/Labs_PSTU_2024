#include <iostream>
#include <map>
#include "Money.h"
using namespace std;

typedef map<int, Money> TMap;
typedef TMap::iterator it;

// Функция для формирования словаря
TMap make_map(int n) {
    TMap m;
    Money a;
    for (int i = 0; i < n; i++) {
        cout << "Enter value for key " << i << " (rub,kop): ";
        cin >> a;
        m.insert(make_pair(i, a));
    }
    return m;
}

// Функция для печати словаря
void print_map(const TMap& m) {
    for (const auto& pair : m) {
        cout << pair.first << " : " << pair.second << endl;
    }
}

// Функция для поиска элемента с заданным ключом
it find_key(TMap& m, const Money& key) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second == key) {
            return it;
        }
    }
    return m.end();
}

// Функция для добавления элемента на заданную позицию
void add_key_at_position(TMap& m, const Money& key, int pos) {
    TMap temp;
    int index = 0;
    auto it = m.begin();
    while (it != m.end() && index < pos) {
        temp.insert(make_pair(index, it->second));
        ++it;
        ++index;
    }
    temp.insert(make_pair(index, key));
    while (it != m.end()) {
        temp.insert(make_pair(index + 1, it->second));
        ++it;
        ++index;
    }
    m = temp;
}

// Функция для удаления элемента с заданным ключом
void remove_key(TMap& m, const Money& key) {
    auto it = find_key(m, key);
    if (it != m.end()) {
        m.erase(it);
    }
}

// Функция для вычисления разницы между максимальным и минимальным элементами
Money compute_max_min_diff(const TMap& m) {
    if (m.empty()) return Money(0, 0);
    Money max_val = m.begin()->second;
    Money min_val = m.begin()->second;
    for (const auto& pair : m) {
        if (pair.second > max_val) max_val = pair.second;
        if (pair.second < min_val) min_val = pair.second;
    }
    return max_val - min_val;
}

// Функция для вычитания разницы из каждого элемента
void subtract_diff(TMap& m) {
    Money diff = compute_max_min_diff(m);
    TMap temp;
    int index = 0;
    for (auto& pair : m) {
        temp.insert(make_pair(index, pair.second - diff));
        ++index;
    }
    m = temp;
}

int main() {
    int n;
    cout << "Enter the number of elements (n): ";
    cin >> n;

    TMap m = make_map(n);
    cout << "Initial map:" << endl;
    print_map(m);

    // Задание 3: Добавить элемент с заданным ключом на заданную позицию
    Money key;
    int pos;
    cout << "Enter key to find and add (rub,kop): ";
    cin >> key;
    cout << "Enter position to add (0 to " << n << "): ";
    cin >> pos;
    auto it = find_key(m, key);
    if (it != m.end()) {
        add_key_at_position(m, key, pos);
        cout << "Map after adding key at position:" << endl;
        print_map(m);
    }
    else {
        cout << "Key not found!" << endl;
    }

    // Задание 4: Удалить элемент с заданным ключом
    cout << "Enter key to remove (rub,kop): ";
    cin >> key;
    remove_key(m, key);
    cout << "Map after removing key:" << endl;
    print_map(m);

    // Задание 5: Вычесть разницу между максимальным и минимальным
    subtract_diff(m);
    cout << "Map after subtracting max-min difference:" << endl;
    print_map(m);

    return 0;
}