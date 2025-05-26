#pragma once
#include <iostream>
#include <map>
#include "Money.h"
using namespace std;

template<class T>
class Vector {
    map<int, T> v;
    int len;
public:
    Vector();
    Vector(int n);
    void Print();
    typename map<int, T>::iterator FindKey(const T& key);
    void AddKeyAtPosition(const T& key, int pos);
    void RemoveKey(const T& key);
    T ComputeMaxMinDiff();
    void SubtractDiff();
};

template<class T>
Vector<T>::Vector() : len(0) {}

template<class T>
Vector<T>::Vector(int n) : len(n) {
    T a;
    for (int i = 0; i < n; i++) {
        cout << "Enter value for key " << i << " (rub,kop): ";
        cin >> a;
        v[i] = a;
    }
}

template<class T>
void Vector<T>::Print() {
    for (const auto& pair : v) {
        cout << pair.first << " : " << pair.second << endl;
    }
    cout << endl;
}

template<class T>
typename map<int, T>::iterator Vector<T>::FindKey(const T& key) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it->second == key) {
            return it;
        }
    }
    return v.end();
}

template<class T>
void Vector<T>::AddKeyAtPosition(const T& key, int pos) {
    map<int, T> temp;
    int index = 0;
    auto it = v.begin();
    while (it != v.end() && index < pos) {
        temp.insert(make_pair(index, it->second));
        ++it;
        ++index;
    }
    temp.insert(make_pair(index, key));
    while (it != v.end()) {
        temp.insert(make_pair(index + 1, it->second));
        ++it;
        ++index;
    }
    v = temp;
}

template<class T>
void Vector<T>::RemoveKey(const T& key) {
    auto it = FindKey(key);
    if (it != v.end()) {
        v.erase(it);
    }
}

template<class T>
T Vector<T>::ComputeMaxMinDiff() {
    if (v.empty()) return T();
    T max_val = v.begin()->second;
    T min_val = v.begin()->second;
    for (const auto& pair : v) {
        if (pair.second > max_val) max_val = pair.second;
        if (pair.second < min_val) min_val = pair.second;
    }
    return max_val - min_val;
}

template<class T>
void Vector<T>::SubtractDiff() {
    T diff = ComputeMaxMinDiff();
    map<int, T> temp;
    int index = 0;
    for (auto& pair : v) {
        temp.insert(make_pair(index, pair.second - diff));
        ++index;
    }
    v = temp;
}