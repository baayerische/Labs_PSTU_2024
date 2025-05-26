#include <iostream>
#include "Vector.h"
#include "Money.h"
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements (n): ";
    cin >> n;

    Vector<Money> vec(n);
    cout << "Initial queue: ";
    vec.Print();

    // Задание 3: Добавить элемент с заданным ключом на заданную позицию
    Money key;
    int pos;
    cout << "Enter key to find and add (rub,kop): ";
    cin >> key;
    cout << "Enter position to add (0 to " << n << "): ";
    cin >> pos;
    if (vec.FindKey(key)) {
        vec.AddKeyAtPosition(key, pos);
        cout << "Queue after adding key at position: ";
        vec.Print();
    }
    else {
        cout << "Key not found!" << endl;
    }

    // Задание 4: Удалить элемент с заданным ключом
    cout << "Enter key to remove (rub,kop): ";
    cin >> key;
    vec.RemoveKey(key);
    cout << "Queue after removing key: ";
    vec.Print();

    // Задание 5: Вычесть разницу между максимальным и минимальным
    vec.SubtractDiff();
    cout << "Queue after subtracting max-min difference: ";
    vec.Print();

    return 0;
}