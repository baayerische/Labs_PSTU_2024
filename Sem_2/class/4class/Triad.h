#pragma once
#include <iostream>

using namespace std;

class Triad {
public:
    Triad(void);
    virtual ~Triad(void);
    Triad(int, int, int);
    Triad(const Triad&);

    // Селекторы
    int Get_first() { return first; }
    int Get_second() { return second; }
    int Get_third() { return third; }

    // Модификаторы
    void Set_first(int);
    void Set_second(int);
    void Set_third(int);

    // Операции сравнения
    bool operator==(const Triad&) const;
    bool operator<(const Triad&) const;
    bool operator>(const Triad&) const;

    Triad& operator=(const Triad&);

    friend istream& operator>>(istream& in, Triad& t);
    friend ostream& operator<<(ostream& out, const Triad& t);

protected:
    int first;
    int second;
    int third;
};