#pragma once
#include "Object.h"

struct ListNode {
    Object* data;
    ListNode* next;
    ListNode(Object* d);
};

class List {
protected:
    ListNode* head;
    int size;
public:
    List(void);
    List(int n);
    ~List(void);
    void Add();
    void Del();
    void Show();
    int operator()();
    double GetAverageAge();
};