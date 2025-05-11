#include "Abiturient.h"

Abiturient::Abiturient(void) : Person(), points(0), specialty("") {}
Abiturient::Abiturient(string N, int A, int P, string S) : Person(N, A), points(P), specialty(S) {}
Abiturient::Abiturient(const Abiturient& a) : Person(a), points(a.points), specialty(a.specialty) {}
Abiturient::~Abiturient(void) {}

void Abiturient::Show() {
    cout << "\nName: " << name;
    cout << "\nAge: " << age;
    cout << "\nPoints: " << points;
    cout << "\nSpecialty: " << specialty;
    cout << "\n";
}

void Abiturient::Input() {
    cout << "\nName: "; cin >> name;
    cout << "\nAge: "; cin >> age;
    cout << "\nPoints: "; cin >> points;
    cout << "\nSpecialty: "; cin >> specialty;
}

int Abiturient::Get_points() { return points; }
string Abiturient::Get_specialty() { return specialty; }
void Abiturient::Set_points(int P) { points = P; }
void Abiturient::Set_specialty(string S) { specialty = S; }

Abiturient& Abiturient::operator=(const Abiturient& a) {
    if (&a == this) return *this;
    Person::operator=(a);
    points = a.points;
    specialty = a.specialty;
    return *this;
}