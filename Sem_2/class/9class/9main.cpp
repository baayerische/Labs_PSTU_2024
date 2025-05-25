#include "Set.h"
#include "error.h"
#include <iostream>
using namespace std;

int main() {
    try {
        int init1[] = { 1, 2, 3, 4 };
        int init2[] = { 4, 3, 2, 1 };
        Set s1(4, init1); // множество {1, 2, 3, 4}
        Set s2(4, init2); // множество {4, 3, 2, 1}
        cout << "Set s1: " << s1; // 1 2 3 4
        cout << "Set s2: " << s2; // 4 3 2 1

        cout << "Enter index: ";
        int i;
        cin >> i;
        cout << "Element at index " << i << " in s1: " << s1[i] << endl; // может вызвать исключение

        cout << "Enter number to check membership: ";
        int num;
        cin >> num;
        cout << num << (s1 > num ? " is" : " is not") << " in s1" << endl; // проверка принадлежности

        cout << "s1 == s2: " << (s1 == s2 ? "true" : "false") << endl; // проверка на равенство (true)

        cout << "Enter position to shift left: ";
        int pos;
        cin >> pos;
        s1 = s1 - pos; // переход влево
        cout << "After shifting s1 left by " << pos << ": " << s1; // циклический сдвиг
    }
    catch (error e) {
        e.what(); // вывод сообщения об ошибке
    }
    return 0;
}