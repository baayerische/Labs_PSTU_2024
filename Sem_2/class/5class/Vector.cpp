#include "Vector.h"

Vector::Vector(void) {
    beg = nullptr;
    size = 0;
    cur = 0;
}

Vector::Vector(int n) {
    beg = new Object * [n];
    size = n;
    cur = 0;
}

Vector::~Vector(void) {
    if (beg != nullptr) {
        delete[] beg;
    }
    beg = nullptr;
}

void Vector::Add(Object* p) {
    if (cur < size) {
        beg[cur] = p;
        cur++;
    }
}

ostream& operator<<(ostream& out, const Vector& v) {
    if (v.size == 0) {
        out << "Empty\n";
    }
    else {
        Object** p = v.beg;
        for (int i = 0; i < v.cur; i++) {
            (*p)->Show(); 
            p++;
        }
    }
    return out;
}