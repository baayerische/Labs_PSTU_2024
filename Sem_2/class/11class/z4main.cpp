#include <iostream>
#include <queue>
#include <vector>
#include "Money.h"
using namespace std;

typedef priority_queue<Money> PQueue;
typedef vector<Money> Vec;

// Копирование очереди в вектор
Vec copy_queue_to_vector(PQueue q) {
    Vec v;
    while (!q.empty()) {
        v.push_back(q.top());
        q.pop();
    }
    return v;
}

// Копирование вектора в очередь
PQueue copy_vector_to_queue(const Vec& v) {
    PQueue q;
    for (const Money& m : v) {
        q.push(m);
    }
    return q;
}

// Формирование очереди
PQueue make_queue(int n) {
    PQueue q;
    Money m;
    for (int i = 0; i < n; i++) {
        cout << "Enter money " << i + 1 << " (rub,kop): ";
        cin >> m;
        q.push(m);
    }
    return q;
}

// Печать очереди
void print_queue(PQueue q) {
    Vec v = copy_queue_to_vector(q);
    for (const Money& m : v) {
        cout << m << " ";
    }
    cout << endl;
}

// Поиск элемента с заданным ключом в очереди
bool find_key(const PQueue& q, const Money& key) {
    Vec v = copy_queue_to_vector(q);
    for (const Money& m : v) {
        if (m == key) return true;
    }
    return false;
}

// Добавление элемента на заданную позицию
void add_key_at_position(PQueue& q, const Money& key, int pos) {
    Vec v = copy_queue_to_vector(q);
    v.insert(v.begin() + pos, key);
    q = copy_vector_to_queue(v);
}

// Удаление элемента с заданным ключом
void remove_key(PQueue& q, const Money& key) {
    Vec v;
    while (!q.empty()) {
        Money m = q.top();
        if (!(m == key)) v.push_back(m);
        q.pop();
    }
    q = copy_vector_to_queue(v);
}

// Вычисление разницы между максимальным и минимальным элементами
Money compute_max_min_diff(const PQueue& q) {
    if (q.empty()) return Money(0, 0);
    Vec v = copy_queue_to_vector(q);
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
void subtract_diff(PQueue& q) {
    Money diff = compute_max_min_diff(q);
    Vec v;
    while (!q.empty()) {
        Money m = q.top();
        long new_rub = m.getRub() - diff.getRub();
        int new_kop = m.getKop() - diff.getKop();
        if (new_kop < 0) {
            new_rub--;
            new_kop += 100;
        }
        v.push_back(Money(new_rub, new_kop));
        q.pop();
    }
    q = copy_vector_to_queue(v);
}

int main() {
    int n;
    cout << "Enter the number of elements (n): ";
    cin >> n;

    PQueue q = make_queue(n);
    cout << "Initial queue: ";
    print_queue(q);

    // Задание 3: Добавить элемент с заданным ключом на заданную позицию
    Money key;
    int pos;
    cout << "Enter key to find and add (rub,kop): ";
    cin >> key;
    cout << "Enter position to add (0 to " << n << "): ";
    cin >> pos;
    if (find_key(q, key)) {
        add_key_at_position(q, key, pos);
        cout << "Queue after adding key at position: ";
        print_queue(q);
    }
    else {
        cout << "Key not found!" << endl;
    }

    // Задание 4: Удалить элемент с заданным ключом
    cout << "Enter key to remove (rub,kop): ";
    cin >> key;
    remove_key(q, key);
    cout << "Queue after removing key: ";
    print_queue(q);

    // Задание 5: Вычесть разницу между максимальным и минимальным
    subtract_diff(q);
    cout << "Queue after subtracting max-min difference: ";
    print_queue(q);

    return 0;
}