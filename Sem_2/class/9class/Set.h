#pragma once
#include <iostream>
#include "error.h"
using namespace std;

const int MAX_SIZE = 30; // максимальный размер множества
class Set {
    int size; // текущий размер
    int* elements; // указатель на динамический массив элементов
public:
    Set(); // конструктор без параметров
    Set(int s); // конструктор с параметром
    Set(int s, int* mas); // конструктор с параметром и массивом
    Set(const Set& s); // конструктор копирования
    ~Set(); // деструктор
    const Set& operator=(const Set& s); // операция присваивания
    int operator[](int i); // доступ по индексу
    bool operator==(const Set& s) const; // проверка на равенство
    bool operator>(int a) const; // проверка принадлежности числа множеству
    Set operator-(int n); // переход влево к элементу с номером n
    friend ostream& operator<<(ostream& out, const Set& s); // вывод
    friend istream& operator>>(istream& in, Set& s); // ввод
};