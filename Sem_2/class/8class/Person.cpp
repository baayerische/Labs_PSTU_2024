#include "Person.h"

Person::Person(void) : name(""), age(0) {}
Person::Person(string N, int A) : name(N), age(A) {}
Person::Person(const Person& p) : name(p.name), age(p.age) {}
Person::~Person(void) {}

void Person::Show() {
    cout << "\nName: " << name;
    cout << "\nAge: " << age;
    cout << "\n";
}

void Person::Input() {
    cout << "\nName: "; cin >> name;
    cout << "\nAge: "; cin >> age;
}

string Person::Get_name() { return name; }
int Person::Get_age() { return age; }
void Person::Set_name(string N) { name = N; }
void Person::Set_age(int A) { age = A; }

Person& Person::operator=(const Person& p) {
    if (&p == this) return *this;
    name = p.name;
    age = p.age;
    return *this;
}