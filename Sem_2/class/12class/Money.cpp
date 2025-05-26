#include "Money.h"

Money::Money() : rub(0), kop(0) {}

Money::Money(long r, int k) : rub(r), kop(k) {
    if (kop >= 100) {
        rub += kop / 100;
        kop %= 100;
    }
    if (kop < 0) {
        rub--;
        kop += 100;
    }
}

Money::Money(const Money& m) : rub(m.rub), kop(m.kop) {}

Money::~Money() {}

Money Money::operator+(const Money& m) const {
    long totalRub = rub + m.rub;
    int totalKop = kop + m.kop;
    if (totalKop >= 100) {
        totalRub += totalKop / 100;
        totalKop %= 100;
    }
    if (totalKop < 0) {
        totalRub--;
        totalKop += 100;
    }
    return Money(totalRub, totalKop);
}

Money Money::operator-(const Money& m) const {
    long totalRub = rub - m.rub;
    int totalKop = kop - m.kop;
    if (totalKop < 0) {
        totalRub--;
        totalKop += 100;
    }
    return Money(totalRub, totalKop);
}

Money Money::operator/(const Money& m) const {
    if (m.rub == 0 && m.kop == 0) return *this; // Избегаем деления на ноль
    double total = (rub * 100.0 + kop) / (m.rub * 100.0 + m.kop);
    long newRub = static_cast<long>(total);
    int newKop = static_cast<int>((total - newRub) * 100);
    return Money(newRub, newKop);
}

bool Money::operator==(const Money& m) const {
    return rub == m.rub && kop == m.kop;
}

bool Money::operator<(const Money& m) const {
    if (rub < m.rub) return true;
    if (rub > m.rub) return false;
    return kop < m.kop;
}

bool Money::operator>(const Money& m) const {
    if (rub > m.rub) return true;
    if (rub < m.rub) return false;
    return kop > m.kop;
}

bool Money::operator<=(const Money& m) const {
    return (*this < m || *this == m);
}

bool Money::operator>=(const Money& m) const {
    return (*this > m || *this == m);
}

const Money& Money::operator=(const Money& m) {
    if (this != &m) {
        rub = m.rub;
        kop = m.kop;
    }
    return *this;
}

ostream& operator<<(ostream& out, const Money& m) {
    out << m.rub << "," << (m.kop < 10 ? "0" : "") << m.kop;
    return out;
}

istream& operator>>(istream& in, Money& m) {
    char comma;
    in >> m.rub >> comma >> m.kop;
    if (m.kop >= 100) {
        m.rub += m.kop / 100;
        m.kop %= 100;
    }
    if (m.kop < 0) {
        m.rub--;
        m.kop += 100;
    }
    return in;
}