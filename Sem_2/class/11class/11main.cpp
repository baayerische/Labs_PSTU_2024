#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef list<double> List;

// Формирование списка
List make_list(int n) {
    List lst;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        double a = (rand() % 1000) / 10.0 - 50.0; // Случайные числа от -50 до 49.9
        lst.push_back(a);
    }
    return lst;
}

// Печать списка
void print_list(const List& lst) {
    for (const double& val : lst) {
        cout << val << " ";
    }
    cout << endl;
}

// Поиск элемента с заданным ключом (возвращает итератор)
list<double>::iterator find_key(List& lst, double key) {
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        if (*it == key) {
            return it;
        }
    }
    return lst.end();
}

// Добавление элемента с заданным ключом на заданную позицию
void add_key_at_position(List& lst, double key, int pos) {
    auto it = lst.begin();
    advance(it, pos);
    lst.insert(it, key);
}

// Удаление элемента с заданным ключом
void remove_key(List& lst, double key) {
    auto it = find_key(lst, key);
    if (it != lst.end()) {
        lst.erase(it);
    }
}

// Вычисление разницы между максимальным и минимальным элементами
double compute_max_min_diff(const List& lst) {
    if (lst.empty()) return 0.0;
    double max_val = *lst.begin(), min_val = *lst.begin();
    for (const double& val : lst) {
        if (val > max_val) max_val = val;
        if (val < min_val) min_val = val;
    }
    return max_val - min_val;
}

// Вычитание разницы из каждого элемента
void subtract_diff(List& lst) {
    double diff = compute_max_min_diff(lst);
    List temp;
    for (double val : lst) {
        temp.push_back(val - diff);
    }
    lst = temp;
}

int main() {
    int n;
    cout << "Enter the number of elements (n): ";
    cin >> n;

    List lst = make_list(n);
    cout << "Initial list: ";
    print_list(lst);

    // Задание 3: Добавить элемент с заданным ключом на заданную позицию
    double key;
    int pos;
    cout << "Enter key to find and add: ";
    cin >> key;
    cout << "Enter position to add (0 to " << n << "): ";
    cin >> pos;
    auto it = find_key(lst, key);
    if (it != lst.end()) {
        add_key_at_position(lst, key, pos);
        cout << "List after adding key at position: ";
        print_list(lst);
    }
    else {
        cout << "Key not found!" << endl;
    }

    // Задание 4: Удалить элемент с заданным ключом
    cout << "Enter key to remove: ";
    cin >> key;
    remove_key(lst, key);
    cout << "List after removing key: ";
    print_list(lst);

    // Задание 5: Вычесть разницу между максимальным и минимальным
    subtract_diff(lst);
    cout << "List after subtracting max-min difference: ";
    print_list(lst);

    return 0;
}