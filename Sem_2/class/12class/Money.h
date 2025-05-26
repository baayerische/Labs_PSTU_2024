#pragma once
#include <iostream>
using namespace std;

class Money {
    long rub;
    int kop;
public:
    Money();
    Money(long r, int k);
    Money(const Money& m);
    ~Money();
    Money operator+(const Money& m) const;
    Money operator-(const Money& m) const;
    Money operator/(const Money& m) const;
    bool operator==(const Money& m) const;
    bool operator<(const Money& m) const;
    bool operator>(const Money& m) const;
    bool operator<=(const Money& m) const;
    bool operator>=(const Money& m) const;
    const Money& operator=(const Money& m);
    friend ostream& operator<<(ostream& out, const Money& m);
    friend istream& operator>>(istream& in, Money& m);
    long getRub() const { return rub; }
    int getKop() const { return kop; }
};