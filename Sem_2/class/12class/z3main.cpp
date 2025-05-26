#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements (n): ";
    cin >> n;

    Vector<Money> v(n);
    cout << "Initial vector:" << endl;
    v.Print();

    // Задание 3: Добавить элемент с заданным ключом на заданную позицию
    Money key;
    int pos;
    cout << "Enter key to find and add (rub,kop): ";
    cin >> key;
    cout << "Enter position to add (0 to " << n << "): ";
    cin >> pos;
    auto it = v.FindKey(key);
    if (it != v.end()) {
        v.AddKeyAtPosition(key, pos);
        cout << "Vector after adding key at position:" << endl;
        v.Print();
    }
    else {
        cout << "Key not found!" << endl;
    }

    // Задание 4: Удалить элемент с заданным ключом
    cout << "Enter key to remove (rub,kop): ";
    cin >> key;
    v.RemoveKey(key);
    cout << "Vector after removing key:" << endl;
    v.Print();

    // Задание 5: Вычесть разницу между максимальным и минимальным
    v.SubtractDiff();
    cout << "Vector after subtracting max-min difference:" << endl;
    v.Print();

    return 0;
}