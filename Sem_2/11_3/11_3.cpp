#include <iostream>
using namespace std;

struct StackNode {
    int key;
    StackNode* next;
};

struct Stack {
    StackNode* top;
    int size;

    Stack() {
        top = nullptr;
        size = 0;
    }

    void push(int value) {
        StackNode* newNode = new StackNode;
        newNode->key = value;
        newNode->next = top;
        top = newNode;
        size++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "���� ����!" << endl;
            return -1;
        }
        StackNode* temp = top;
        int val = temp->key;
        top = top->next;
        delete temp;
        size--;
        return val;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void print() {
        StackNode* current = top;
        cout << "����: ";
        while (current != nullptr) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }

    void deleteAfter(int pos) {
        if (pos < 1 || pos >= size) {
            cout << "�������� �������!" << endl;
            return;
        }

        Stack tempStack;
        for (int i = 0; i < pos; i++) {
            tempStack.push(pop());
        }

        pop();

        while (!tempStack.isEmpty()) {
            push(tempStack.pop());
        }
    }

    void addKElementsToFront(int K) {
        Stack tempStack;
        for (int i = 0; i < K; i++) {
            int val;
            cout << "������� ������� " << i + 1 << ": ";
            cin >> val;
            tempStack.push(val);
        }

        while (!tempStack.isEmpty()) {
            push(tempStack.pop());
        }
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Stack s;
    int n, val, pos, K;

    cout << "������� ���������� ��������� � �����: ";
    cin >> n;

    cout << "������� ��������:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> val;
        s.push(val);
    }

    s.print();

    cout << "������� ����� ��������, ����� �������� ����� �������: ";
    cin >> pos;
    s.deleteAfter(pos);
    cout << "����� ��������:" << endl;
    s.print();

    cout << "������� ���������� ��������� K ��� ����������: ";
    cin >> K;
    s.addKElementsToFront(K);
    cout << "����� ����������:" << endl;
    s.print();

    return 0;
}