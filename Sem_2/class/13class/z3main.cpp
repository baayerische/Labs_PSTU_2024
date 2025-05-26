#include <iostream>
#include <map>
#include <algorithm>
#include "Money.h"
using namespace std;

typedef multimap<int, Money> TMultimap;

Money s;

TMultimap make_multimap(int n) {
    TMultimap m;
    Money a;
    for (int i = 0; i < n; i++) {
        cout << "Enter value for key " << i << " (rub,kop): ";
        cin >> a;
        m.insert(make_pair(i, a));
    }
    return m;
}

// Печать мультимножества
void print_multimap(const TMultimap& m) {
    for (const auto& pair : m) {
        cout << pair.first << " : " << pair.second << endl;
    }
    cout << endl;
}

// Предикат для сравнения с заданным значением
struct Equal_s {
    bool operator()(const pair<const int, Money>& p) {
        return p.second == s;
    }
};

// Предикат для сортировки по убыванию
struct Comp_less {
    bool operator()(const pair<const int, Money>& p1, const pair<const int, Money>& p2) {
        return p1.second > p2.second;
    }
};

// Функция для вычисления разницы между максимальным и минимальным элементами
Money compute_max_min_diff(const TMultimap& m) {
    if (m.empty()) return Money(0, 0);
    auto max_it = max_element(m.begin(), m.end(),
        [](const auto& p1, const auto& p2) { return p1.second < p2.second; });
    auto min_it = min_element(m.begin(), m.end(),
        [](const auto& p1, const auto& p2) { return p1.second < p2.second; });
    return max_it->second - min_it->second;
}

// Функция для вычитания разницы
void subtract_diff(pair<const int, Money>& p) {
    static Money diff = Money(0, 0);
    static bool first_call = true;
    static TMultimap* current_map = nullptr;
    if (first_call || current_map != &m) {
        diff = compute_max_min_diff(m);
        first_call = false;
        current_map = const_cast<TMultimap*>(&m);
    }
    p.second = p.second - diff;
}

int main() {
    int n;
    cout << "Enter the number of elements (n): ";
    cin >> n;

    TMultimap m = make_multimap(n);
    cout << "Initial multimap:" << endl;
    print_multimap(m);

    // Задание 3: Найти элемент с заданным ключом и добавить его на заданную позицию
    cout << "Enter value to find and add (rub,kop): ";
    cin >> s;
    int pos;
    cout << "Enter position to add (0 to " << n << "): ";
    cin >> pos;

    auto it = find_if(m.begin(), m.end(), Equal_s());
    if (it != m.end()) {
        TMultimap temp;
        int index = 0;
        auto current = m.begin();
        while (current != m.end() && index < pos) {
            temp.insert(*current);
            ++current;
            ++index;
        }
        temp.insert(make_pair(index, it->second));
        while (current != m.end()) {
            temp.insert(make_pair(index, current->second));
            ++current;
            ++index;
        }
        m = temp;
        cout << "Multimap after adding element at position:" << endl;
        print_multimap(m);
    }
    else {
        cout << "Element not found!" << endl;
    }

    // Задание 4: Найти элемент с заданным ключом и удалить его
    cout << "Enter value to remove (rub,kop): ";
    cin >> s;
    for (auto it = m.begin(); it != m.end();) {
        if (it->second == s) {
            it = m.erase(it);
        }
        else {
            ++it;
        }
    }
    cout << "Multimap after removing element:" << endl;
    print_multimap(m);

    // Сортировка по возрастанию и убыванию (копируем в вектор для сортировки)
    vector<pair<int, Money>> v(m.begin(), m.end());
    cout << "Sort ascending:" << endl;
    sort(v.begin(), v.end(),
        [](const auto& p1, const auto& p2) { return p1.second < p2.second; });
    m.clear();
    for (const auto& p : v) {
        m.insert(p);
    }
    print_multimap(m);
    cout << "Sort descending:" << endl;
    sort(v.begin(), v.end(), Comp_less());
    m.clear();
    for (const auto& p : v) {
        m.insert(p);
    }
    print_multimap(m);

    // Поиск элемента
    cout << "Enter value to find (rub,kop): ";
    cin >> s;
    it = find_if(m.begin(), m.end(), Equal_s());
    if (it != m.end()) {
        cout << "Found: " << it->second << " at key " << it->first << endl;
    }
    else {
        cout << "Not such element!" << endl;
    }

    // Задание 5: Вычесть разницу между максимальным и минимальным
    cout << "Subtracting max-min difference:" << endl;
    for_each(m.begin(), m.end(), subtract_diff);
    print_multimap(m);

    return 0;
}