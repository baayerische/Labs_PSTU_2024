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
        cout << "Введите рубли: ";
        cin >> rub;
        cout << "Введите копейки: ";
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
        cout << kop << " руб.";
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Money a, b;

    cout << "Первая сумма:"<<endl;
    a.read();

    cout << "Вторая сумма:" << endl;
    b.read();

    Money c = a.sum(b);

    cout << "Сумма: " << endl;
    c.show();

    cout << "Сравнение:" << endl;
    cout << "A > B: " << (a.isGreater(b) ? "Да" : "Нет");
    cout << endl;
    cout << "A < B: " << (a.isLess(b) ? "Да" : "Нет");
    cout << endl;
    cout << "A == B: " << (a.isEqual(b) ? "Да" : "Нет");
    cout << endl;
    return 0;
}