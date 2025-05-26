#pragma once
#include <list>
#include <iostream>
using namespace std;

template<class T>
class Vector {
    list<T> lst;
    int len;
public:
    Vector(int n);
    void Print();
    list<T>::iterator FindKey(const T& key);
    void AddKeyAtPosition(const T& key, int pos);
    void RemoveKey(const T& key);
    T ComputeMaxMinDiff();
    void SubtractDiff();
};

template<class T>
Vector<T>::Vector(int n) {
    T a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        lst.push_back(a);
    }
    len = lst.size();
}

template<class T>
void Vector<T>::Print() {
    for (const T& val : lst) {
        cout << val << " ";
    }
    cout << endl;
}

template<class T>
list<T>::iterator Vector<T>::FindKey(const T& key) {
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        if (*it == key) {
            return it;
        }
    }
    return lst.end();
}

template<class T>
void Vector<T>::AddKeyAtPosition(const T& key, int pos) {
    auto it = lst.begin();
    advance(it, pos);
    lst.insert(it, key);
}

template<class T>
void Vector<T>::RemoveKey(const T& key) {
    auto it = FindKey(key);
    if (it != lst.end()) {
        lst.erase(it);
    }
}

template<class T>
T Vector<T>::ComputeMaxMinDiff() {
    if (lst.empty()) return T();
    T max_val = *lst.begin(), min_val = *lst.begin();
    for (const T& val : lst) {
        if (val > max_val) max_val = val;
        if (val < min_val) min_val = val;
    }
    return max_val - min_val; 
}
template<class T>
void Vector<T>::SubtractDiff() {
    T diff = ComputeMaxMinDiff();
    list<T> temp;
    for (const T& val : lst) {
        temp.push_back(val - diff);
    }
    lst = temp;
}