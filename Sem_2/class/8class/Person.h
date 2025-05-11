#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;

class Person : public Object {
protected:
    string name;
    int age;
public:
    Person(void);
    Person(string N, int A);
    Person(const Person& p);
    ~Person(void);
    void Show();
    void Input();
    string Get_name();
    int Get_age();
    void Set_name(string N);
    void Set_age(int A);
    Person& operator=(const Person& p);
};