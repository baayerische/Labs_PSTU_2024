#include "List.h"
#include "Person.h"
#include "Abiturient.h"
#include <iostream>
using namespace std;

ListNode::ListNode(Object* d) : data(d), next(nullptr) {}

List::List(void) : head(nullptr), size(0) {}
List::List(int n) : head(nullptr), size(0) {
    for (int i = 0; i < n; i++) Add();
}
List::~List(void) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
}

void List::Add() {
    Object* p;
    cout << "1. Person" << endl;
    cout << "2. Abiturient" << endl;
    int y;
    cin >> y;
    if (y == 1) {
        Person* a = new Person;
        a->Input();
        p = a;
    }
    else if (y == 2) {
        Abiturient* b = new Abiturient;
        b->Input();
        p = b;
    }
    else {
        return;
    }
    ListNode* newNode = new ListNode(p);
    newNode->next = head;
    head = newNode;
    size++;
}

void List::Del() {
    if (!head) return;
    ListNode* temp = head;
    head = head->next;
    delete temp->data;
    delete temp;
    size--;
}

void List::Show() {
    if (!head) {
        cout << "Empty" << endl;
        return;
    }
    ListNode* current = head;
    while (current) {
        current->data->Show();
        current = current->next;
    }
}

int List::operator()() { return size; }

double List::GetAverageAge() {
    if (!head) return 0.0;
    double totalAge = 0;
    int count = 0;
    ListNode* current = head;
    while (current) {
        totalAge += dynamic_cast<Person*>(current->data)->Get_age();
        count++;
        current = current->next;
    }
    return count > 0 ? totalAge / count : 0.0;
}