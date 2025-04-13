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
        cout << "������� ������ � ��������:" << endl;
        cout << "�����: ";
        getline(cin, address);
        cout << "������� (��.�): ";
        cin >> area;
        cout << "���������� ������: ";
        cin >> rooms;
        cin.ignore();
    }

    void display() {
        cout << "���������� � ��������:" << endl;
        cout << "�����: " << address << endl;
        cout << "�������: " << area << " ��.�" << endl;
        cout << "���������� ������: " << rooms << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Apartment flat;
    flat.read();
    flat.display();
    return 0;
}