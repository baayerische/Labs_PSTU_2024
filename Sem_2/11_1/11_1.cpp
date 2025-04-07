#include <iostream>
using namespace std;

struct ListNode {
    int key;         
    ListNode* next;  
};

ListNode* createList(int n) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; i++) {
        ListNode* newNode = new ListNode;
        cout << "Введите ключ элемента " << i + 1 << ": ";
        cin >> newNode->key;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

ListNode* deleteAfterNode(ListNode* head, int pos) {
    if (head == nullptr || head->next == nullptr) {
        cout << "Невозможно удалить элемент (список слишком короткий)" << endl;
        return head;
    }

    ListNode* current = head;
    for (int i = 1; i < pos && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Невозможно удалить элемент (позиция не найдена)" << endl;
        return head;
    }

    ListNode* toDelete = current->next;
    current->next = toDelete->next;
    delete toDelete;

    return head;
}

ListNode* addKElementsToFront(ListNode* head, int K) {
    for (int i = 0; i < K; i++) {
        ListNode* newNode = new ListNode;
        cout << "Введите ключ нового элемента " << i + 1 << ": ";
        cin >> newNode->key;
        newNode->next = head;
        head = newNode;
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->key << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    setlocale(LC_ALL, "RU");

    int n, pos, K;
    cout << "Введите количество элементов в списке: ";
    cin >> n;

    ListNode* head = createList(n);
    cout << "Исходный список: ";
    printList(head);

    cout << "Введите номер элемента, после которого нужно удалить следующий: ";
    cin >> pos;
    head = deleteAfterNode(head, pos);
    cout << "Список после удаления: ";
    printList(head);

    cout << "Введите количество элементов (K) для добавления в начало: ";
    cin >> K;
    head = addKElementsToFront(head, K);
    cout << "Список после добавления " << K << " элементов: ";
    printList(head);

    return 0;
}