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
            cout << "Очередь пуста!" << endl;
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
        cout << "Очередь: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void deleteAfter(int pos) {
        if (pos < 1 || pos >= size) {
            cout << "Неверная позиция!" << endl;
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
            cout << "Введите элемент " << i + 1 << ": ";
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

    cout << "Введите количество элементов в очереди: ";
    cin >> n;

    cout << "Введите элементы:" << endl;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        q.push(val);
    }

    q.print();

    cout << "Введите номер элемента, после которого нужно удалить: ";
    cin >> pos;
    q.deleteAfter(pos);
    cout << "После удаления:" << endl;
    q.print();

    cout << "Введите количество элементов K для добавления: ";
    cin >> K;
    q.addKElementsToFront(K);
    cout << "После добавления:" << endl;
    q.print();

    return 0;
}