#pragma once
#include "Triad.h"

class Date : public Triad {
public:
    Date(void);
    virtual ~Date(void);
    Date(int, int, int);
    Date(const Date&);

    void Show() override;

    bool operator==(const Date&) const;
    bool operator<(const Date&) const;
    bool operator>(const Date&) const;
    bool operator<=(const Date&) const;
    bool operator>=(const Date&) const;
    bool operator!=(const Date&) const;

    Date& operator=(const Date&);

    friend istream& operator>>(istream& in, Date& d);
    friend ostream& operator<<(ostream& out, const Date& d);
};