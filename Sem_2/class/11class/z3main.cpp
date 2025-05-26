#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements (n): ";
    cin >> n;

    Vector<double> vec(n);
    cout << "Initial list: ";
    vec.Print();

    // Задание 3: Добавить элемент с заданным ключом на заданную позицию
    double key;
    int pos;
    cout << "Enter key to find and add: ";
    cin >> key;
    cout << "Enter position to add (0 to " << n << "): ";
    cin >> pos;
    auto it = vec.FindKey(key);
    if (it != vec.end()) {
        vec.AddKeyAtPosition(key, pos);
        cout << "List after adding key at position: ";
        vec.Print();
    }
    else {
        cout << "Key not found!" << endl;
    }

    // Задание 4: Удалить элемент с заданным ключом
    cout << "Enter key to remove: ";
    cin >> key;
    vec.RemoveKey(key);
    cout << "List after removing key: ";
    vec.Print();

    // Задание 5: Вычесть разницу между максимальным и минимальным
    vec.SubtractDiff();
    cout << "List after subtracting max-min difference: ";
    vec.Print();

    return 0;
}