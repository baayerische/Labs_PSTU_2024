#include <iostream>
#include <string>
using namespace std;

string info(int year) {
    string n[] = {
        "�����", "����", "�����", "�������",
        "�������", "����", "������", "����",
        "��������", "������", "������", "������"
    };
    int i = (year - 2020) % 12;
    if (i < 0) i += 12;
    return "��� " + n[i];
}

string info(string month) {
    if (month == "������" or month == "�������") return "�������/�������";
    if (month == "����" or month == "������") return "����/����";
    if (month == "���" or month == "����") return "��������/�����";
    if (month == "����" or month == "������") return "���/���";
    if (month == "��������" or month == "�������") return "����";
    if (month == "������" or month == "�������") return "�������/�������/��������";
    return "�������� �����";
}

int main() {
    setlocale(LC_ALL, "rus");
    cout << info(2006) << endl;
    cout << info("��������") << endl;
    return 0;
}