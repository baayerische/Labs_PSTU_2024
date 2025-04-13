#include <iostream>
using namespace std;

class Money {
private:
    long rub; 
    int kop;  

    void fixKop() {
        rub += kop / 100;
        kop = kop % 100;
        if (kop < 0) {
            rub--;
            kop += 100;
        }
    }

public:
    void init(long r, int k) {
        rub = r;
        kop = k;
        fixKop();
    }

    void read() {
        cout << "������� �����: ";
        cin >> rub;
        cout << "������� �������: ";
        cin >> kop;
        fixKop();
    }

    Money sum(const Money& other) {
        Money result;
        result.rub = rub + other.rub;
        result.kop = kop + other.kop;
        result.fixKop();
        return result;
    }

    bool isGreater(const Money& other) {  
        return (rub > other.rub) || (rub == other.rub && kop > other.kop);
    }

    bool isLess(const Money& other) {     
        return (rub < other.rub) || (rub == other.rub && kop < other.kop);
    }

    bool isEqual(const Money& other) {    
        return rub == other.rub && kop == other.kop;
    }

    void show() {
        cout << rub << ",";
        if (kop < 10) cout << "0"; 
        cout << kop << " ���.";
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Money a, b;

    cout << "������ �����:"<<endl;
    a.read();

    cout << "������ �����:" << endl;
    b.read();

    Money c = a.sum(b);

    cout << "�����: " << endl;
    c.show();

    cout << "���������:" << endl;
    cout << "A > B: " << (a.isGreater(b) ? "��" : "���");
    cout << endl;
    cout << "A < B: " << (a.isLess(b) ? "��" : "���");
    cout << endl;
    cout << "A == B: " << (a.isEqual(b) ? "��" : "���");
    cout << endl;
    return 0;
}