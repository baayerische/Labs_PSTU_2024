#include <iostream>
#include <string>
using namespace std;

class Apartment {
private:
    string address;
    double area;
    int rooms;
public:

    void init(string addr, double a, int r) {
        address = addr;
        area = a;
        rooms = r;
    }

    void read() {
        cout << "Введите данные о квартире:" << endl;
        cout << "Адрес: ";
        getline(cin, address);
        cout << "Площадь (кв.м): ";
        cin >> area;
        cout << "Количество комнат: ";
        cin >> rooms;
        cin.ignore();
    }

    void display() {
        cout << "Информация о квартире:" << endl;
        cout << "Адрес: " << address << endl;
        cout << "Площадь: " << area << " кв.м" << endl;
        cout << "Количество комнат: " << rooms << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Apartment flat;
    flat.read();
    flat.display();
    return 0;
}