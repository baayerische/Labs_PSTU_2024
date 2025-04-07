#include <iostream>
using namespace std;

struct QueueElem {
    int data;
    QueueElem* next;
};

struct Queue {
    QueueElem* front;
    QueueElem* back;
    int size;

    Queue() {
        front = back = nullptr;
        size = 0;
    }

    void push(int data) {
        QueueElem* tmp = new QueueElem;
        tmp->data = data;
        tmp->next = nullptr;

        if (size == 0) {
            front = back = tmp;
        }
        else {
            back->next = tmp;
            back = tmp;
        }
        size++;
    }

    int pop() {
        if (size == 0) {
            cout << "������� �����!" << endl;
            return -1;
        }

        QueueElem* tmp = front;
        int value = tmp->data;
        front = front->next;

        if (front == nullptr) {
            back = nullptr;
        }

        delete tmp;
        size--;
        return value;
    }

    void print() {
        QueueElem* current = front;
        cout << "�������: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void deleteAfter(int pos) {
        if (pos < 1 || pos >= size) {
            cout << "�������� �������!" << endl;
            return;
        }

        QueueElem* current = front;
        for (int i = 1; i < pos; i++) {
            current = current->next;
        }

        QueueElem* toDelete = current->next;
        current->next = toDelete->next;

        if (toDelete == back) {
            back = current;
        }

        delete toDelete;
        size--;
    }

    void addKElementsToFront(int K) {
        Queue newElements;
        for (int i = 0; i < K; i++) {
            int val;
            cout << "������� ������� " << i + 1 << ": ";
            cin >> val;
            newElements.push(val);
        }

        if (newElements.back != nullptr) {
            newElements.back->next = front;
            front = newElements.front;

            if (back == nullptr) {
                back = newElements.back;
            }

            size += K;
        }

        newElements.front = newElements.back = nullptr;
        newElements.size = 0;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Queue q;
    int n, pos, K;

    cout << "������� ���������� ��������� � �������: ";
    cin >> n;

    cout << "������� ��������:" << endl;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        q.push(val);
    }

    q.print();

    cout << "������� ����� ��������, ����� �������� ����� �������: ";
    cin >> pos;
    q.deleteAfter(pos);
    cout << "����� ��������:" << endl;
    q.print();

    cout << "������� ���������� ��������� K ��� ����������: ";
    cin >> K;
    q.addKElementsToFront(K);
    cout << "����� ����������:" << endl;
    q.print();

    return 0;
}