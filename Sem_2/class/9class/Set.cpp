#include "Set.h"
#include "error.h"
#include <iostream>
using namespace std;

Set::Set() {
    size = 0;
    elements = nullptr;
}

Set::Set(int s) {
    if (s > MAX_SIZE) throw error("Set length more than MAX_SIZE\n");
    size = s;
    elements = new int[s];
    for (int i = 0; i < size; i++)
        elements[i] = 0;
}

Set::Set(int s, int* mas) {
    if (s > MAX_SIZE) throw error("Set length more than MAX_SIZE\n");
    size = s;
    elements = new int[size];
    for (int i = 0; i < size; i++)
        elements[i] = mas[i];
}

Set::Set(const Set& s) {
    size = s.size;
    elements = new int[size];
    for (int i = 0; i < size; i++)
        elements[i] = s.elements[i];
}

Set::~Set() {
    if (elements != nullptr) delete[] elements;
}

const Set& Set::operator=(const Set& s) {
    if (this == &s) return *this;
    if (elements != nullptr) delete[] elements;
    size = s.size;
    elements = new int[size];
    for (int i = 0; i < size; i++)
        elements[i] = s.elements[i];
    return *this;
}

ostream& operator<<(ostream& out, const Set& s) {
    if (s.size == 0) out << "Empty\n";
    else {
        for (int i = 0; i < s.size; i++)
            out << s.elements[i] << " ";
        out << endl;
    }
    return out;
}

istream& operator>>(istream& in, Set& s) {
    for (int i = 0; i < s.size; i++) {
        cout << ">";
        in >> s.elements[i];
    }
    return in;
}

int Set::operator[](int i) {
    if (i < 0) throw error("Index < 0\n");
    if (i >= size) throw error("Index > size\n");
    return elements[i];
}

bool Set::operator==(const Set& s) const {
    if (size != s.size) return false;
    for (int i = 0; i < size; i++) {
        bool found = false;
        for (int j = 0; j < s.size; j++) {
            if (elements[i] == s.elements[j]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

bool Set::operator>(int a) const {
    for (int i = 0; i < size; i++) {
        if (elements[i] == a) return true;
    }
    return false;
}

Set Set::operator-(int n) {
    if (n < 0) throw error("Position < 0\n");
    if (n >= size) throw error("Position > size\n");
    Set temp(size, elements);
    int newIndex = n;
    for (int i = 0; i < size; i++) {
        elements[i] = temp.elements[newIndex];
        newIndex--;
        if (newIndex < 0) newIndex = size - 1; // циклический переход
    }
    return *this;
}