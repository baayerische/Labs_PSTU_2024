#include "Date.h"

Date::Date(void) : Triad() {}

Date::~Date(void) {}

Date::Date(int year, int month, int day) : Triad(year, month, day) {}

Date::Date(const Date& d) : Triad(d) {}

Date& Date::operator=(const Date& d) {
    if (&d == this) return *this;
    Triad::operator=(d);
    return *this;
}

bool Date::operator==(const Date& d) const {
    return first == d.first && second == d.second && third == d.third;
}

bool Date::operator<(const Date& d) const {
    if (first != d.first) return first < d.first;
    if (second != d.second) return second < d.second;
    return third < d.third;
}

bool Date::operator>(const Date& d) const {
    if (first != d.first) return first > d.first;
    if (second != d.second) return second > d.second;
    return third > d.third;
}

bool Date::operator<=(const Date& d) const {
    return *this == d || *this < d;
}

bool Date::operator>=(const Date& d) const {
    return *this == d || *this > d;
}

bool Date::operator!=(const Date& d) const {
    return !(*this == d);
}

istream& operator>>(istream& in, Date& d) {
    cout << "\nYear: "; in >> d.first;
    cout << "\nMonth: "; in >> d.second;
    cout << "\nDay: "; in >> d.third;
    return in;
}

ostream& operator<<(ostream& out, const Date& d) {
    out << "\nYEAR: " << d.first;
    out << "\nMONTH: " << d.second;
    out << "\nDAY: " << d.third;
    out << "\n";
    return out;
}

void Date::Show() {
    cout << "\nYEAR: " << first;
    cout << "\nMONTH: " << second;
    cout << "\nDAY: " << third;
    cout << "\n";
}