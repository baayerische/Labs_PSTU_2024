#pragma once
#include "Person.h"

class Abiturient : public Person {
protected:
    int points;
    string specialty;
public:
    Abiturient(void);
    Abiturient(string N, int A, int P, string S);
    Abiturient(const Abiturient& a);
    ~Abiturient(void);
    void Show();
    void Input();
    int Get_points();
    string Get_specialty();
    void Set_points(int P);
    void Set_specialty(string S);
    Abiturient& operator=(const Abiturient& a);
};