#include <iostream>
#include <algorithm>
using namespace std;

class Money {
public:
    Money(long r = 0, int k = 0) : rub(r), kop(k) {
        normalize();
    }

    Money(const Money& m) : rub(m.rub), kop(m.kop) {
        normalize();
    }

    ~Money() {}

    Money& operator=(const Money& m) {
        if (this == &m) return *this;
        rub = m.rub;
        kop = m.kop;
        return *this;
    }

    bool operator==(const Money& m) const {
        return (rub == m.rub) && (kop == m.kop);
    }

    bool operator>(const Money& m) const {
        if (rub > m.rub) return true;
        if (rub == m.rub && kop > m.kop) return true;
        return false;
    }

    friend ostream& operator<<(ostream& out, const Money& m) {
        out << m.rub << "," << (m.kop < 10 ? "0" : "") << m.kop;
        return out;
    }

    friend istream& operator>>(istream& in, Money& m) {
        cout << "rub kop: ";
        in >> m.rub >> m.kop;
        m.normalize();
        return in;
    }

private:
    long rub;
    int kop;

    void normalize() {
        rub += kop / 100;
        kop = kop % 100;
        if (kop < 0) {
            rub--;
            kop += 100;
        }
    }
};

template <class T>
class Set {
public:
    Set(int s, T k) {
        size = s;
        data = new T[size];
        for (int i = 0; i < size; i++)
            data[i] = k;
    }

    Set(const Set<T>& a) {
        size = a.size;
        data = new T[size];
        for (int i = 0; i < size; i++)
            data[i] = a.data[i];
    }

    ~Set() {
        delete[] data;
        data = nullptr;
    }

    Set<T>& operator=(const Set<T>& a) {
        if (this == &a) return *this;
        size = a.size;
        delete[] data;
        data = new T[size];
        for (int i = 0; i < size; i++)
            data[i] = a.data[i];
        return *this;
    }

    T& operator[](int index) {
        if (index < size) return data[index];
        cout << "\nError! Index > size";
        return data[0];
    }

    bool operator==(const Set<T>& a) const {
        if (size != a.size) return false;
        for (int i = 0; i < size; i++)
            if (data[i] != a.data[i])
                return false;
        return true;
    }

    bool operator>(const T val) const {
        for (int i = 0; i < size; i++)
            if (data[i] == val)
                return true;
        return false;
    }

    int operator()() const {
        return size;
    }

    friend ostream& operator<<(ostream& out, const Set<T>& a) {
        for (int i = 0; i < a.size; i++)
            out << a.data[i] << " ";
        return out;
    }

    friend istream& operator>>(istream& in, Set<T>& a) {
        for (int i = 0; i < a.size; i++)
            in >> a.data[i];
        return in;
    }

private:
    int size;
    T* data;
};

int main() {
    cout << "test int" << endl;
    Set<int> s1(3, 0);
    cout << "enter 3 int: ";
    cin >> s1;
    cout << "set: " << s1 << endl;

    int val;
    cout << "check val: ";
    cin >> val;
    cout << "contains " << val << ": " << (s1 > val ? "yes" : "no") << endl;

    cout << "test money" << endl;
    Money m;
    cout << "enter rub kop: ";
    cin >> m;
    cout << "money: " << m << endl;

    Set<Money> s2(2, m);
    cout << "enter 2 money: ";
    cin >> s2;
    cout << "set: " << s2 << endl;

    Money m2;
    cout << "check money (rub kop): ";
    cin >> m2;
    cout << "contains " << m2 << ": " << (s2 > m2 ? "yes" : "no") << endl;

    return 0;
}