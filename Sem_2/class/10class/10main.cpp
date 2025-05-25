#include "file_work.h"
#include <iostream>
using namespace std;

int main() {
    Money m, k1, k2;
    int k, c;
    char file_name[30];
    do {
        cout << "\n1. Make file\n";
        cout << "2. Print file\n";
        cout << "3. Delete records in range\n";
        cout << "4. Double value\n";
        cout << "5. Add records at beginning\n";
        cout << "6. Exit\n";
        cin >> c;
        switch (c) {
        case 1: cout << "file name? "; cin >> file_name;
            k = make_file(file_name);
            if (k < 0) cout << "Can't make file\n";
            break;
        case 2: cout << "file name? "; cin >> file_name;
            k = print_file(file_name);
            if (k == 0) cout << "Empty file\n";
            if (k < 0) cout << "Can't read file\n";
            break;
        case 3: cout << "file name? "; cin >> file_name;
            cout << "Enter range start (k1): "; cin >> k1;
            cout << "Enter range end (k2): "; cin >> k2;
            k = del_range_file(file_name, k1, k2);
            if (k < 0) cout << "Can't read file\n";
            else if (k > 0) cout << k << " records deleted\n";
            break;
        case 4: cout << "file name? "; cin >> file_name;
            cout << "Enter money to double: "; cin >> m;
            k = double_value_file(file_name, m);
            if (k < 0) cout << "Can't read file\n";
            else if (k > 0) cout << k << " records doubled\n";
            break;
        case 5: cout << "file name? "; cin >> file_name;
            int count;
            cout << "count? "; cin >> count;
            cout << "Enter money to add: "; cin >> m;
            k = add_begin_file(file_name, count, m);
            if (k < 0) cout << "Can't read file\n";
            else if (k > 0) cout << k << " records added\n";
            break;
        }
    } while (c != 6);
    return 0;
}