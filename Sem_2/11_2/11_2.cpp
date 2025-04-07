#include <iostream>
using namespace std;

struct ListNode {
    int key;         
    ListNode* next;  
    ListNode* prev;  
};

ListNode* createList(int n) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; i++) {
        ListNode* newNode = new ListNode;
        cout << "Введите ключ элемента " << i + 1 << ": ";
        cin >> newNode->key;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return head;
}

ListNode* deleteAfterNode(ListNode* head, int pos) {
    if (head == nullptr || head->next == nullptr) {
        cout << "Невозможно удалить (список слишком короткий)" << endl;
        return head;
    }

    ListNode* current = head;
    for (int i = 1; i < pos && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Невозможно удалить (позиция не найдена)" << endl;
        return head;
    }

    ListNode* toDelete = current->next;
    current->next = toDelete->next;

    if (toDelete->next != nullptr) {
        toDelete->next->prev = current;
    }

    delete toDelete;
    return head;
}

ListNode* addKElementsToFront(ListNode* head, int K) {
    for (int i = 0; i < K; i++) {
        ListNode* newNode = new ListNode;
        cout << "Введите ключ нового элемента " << i + 1 << ": ";
        cin >> newNode->key;
        newNode->next = head;
        newNode->prev = nullptr;

        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;
    }
    return head;
}

void printListForward(ListNode* head) {
    ListNode* current = head;
    cout << "Список (вперед): ";
    while (current != nullptr) {
        cout << current->key << " <-> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void printListBackward(ListNode* head) {
    if (head == nullptr) return;

    ListNode* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    cout << "Список (назад): ";
    while (tail != nullptr) {
        cout << tail->key << " <-> ";
        tail = tail->prev;
    }
    cout << "NULL" << endl;
}

int main() {
    setlocale(LC_ALL, "RU");

    int n, pos, K;
    cout << "Введите количество элементов в списке: ";
    cin >> n;

    ListNode* head = createList(n);
    printListForward(head);
    printListBackward(head);

    cout << "Введите номер элемента, после которого нужно удалить следующий: ";
    cin >> pos;
    head = deleteAfterNode(head, pos);
    cout << "После удаления:" << endl;
    printListForward(head);
    printListBackward(head);

    cout << "Введите количество элементов (K) для добавления в начало: ";
    cin >> K;
    head = addKElementsToFront(head, K);
    cout << "После добавления " << K << " элементов:" << endl;
    printListForward(head);
    printListBackward(head);

    return 0;
}