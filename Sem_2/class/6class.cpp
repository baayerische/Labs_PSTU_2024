#include <iostream>
using namespace std;

class Iterator {
    friend class Set;
public:
    Iterator() { elem = nullptr; }
    Iterator(int* p) { elem = p; }
    Iterator(const Iterator& it) { elem = it.elem; }

    bool operator==(const Iterator& it) const { return elem == it.elem; }
    bool operator!=(const Iterator& it) const { return elem != it.elem; }
    Iterator& operator--() { --elem; return *this; }
    int operator*() const { return *elem; }

private:
    int* elem;
};

class Set {
private:
    int capacity;
    int size;
    int* data;

    void ensureCapacity() {
        if (size >= capacity) {
            capacity = (capacity == 0) ? 2 : capacity * 2;
            int* newData = new int[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
    }

    bool contains(int num) const {
        for (int i = 0; i < size; i++) {
            if (data[i] == num) return true;
        }
        return false;
    }

public:
    Set() : capacity(0), size(0), data(nullptr) {}

    Set(const Set& other) : capacity(other.capacity), size(other.size) {
        data = new int[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~Set() {
        delete[] data;
    }

    Set& operator=(const Set& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            size = other.size;
            data = new int[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Индекс выходит за границы");
        }
        return data[index];
    }

    bool operator==(const Set& other) const {
        if (size != other.size) return false;
        for (int i = 0; i < size; i++) {
            if (!other.contains(data[i])) return false;
        }
        return true;
    }

    bool operator>(int num) const {
        return contains(num);
    }

    Iterator operator-(int n) const {
        if (n < 0 || n >= size) {
            throw out_of_range("Неверный индекс");
        }
        return Iterator(data + n);
    }

    Iterator begin() const { return Iterator(data); }
    Iterator end() const { return Iterator(data + size); }

    void add(int num) {
        if (!contains(num)) {
            ensureCapacity();
            data[size++] = num;
        }
    }

    int getSize() const { return size; }

    friend ostream& operator<<(ostream& out, const Set& s) {
        out << "{ ";
        for (int i = 0; i < s.size; i++) {
            out << s.data[i] << " ";
        }
        out << "}";
        return out;
    }

    friend istream& operator>>(istream& in, Set& s) {
        int num;
        in >> num;
        s.add(num);
        return in;
    }
};

int main() {
    try {
        Set s1;
        s1.add(1);
        s1.add(2);
        s1.add(3);
        cout << "Множество 1: " << s1 << endl;

        Set s2;
        s2.add(3);
        s2.add(2);
        s2.add(1);
        cout << "Множество 2: " << s2 << endl;

        cout << "s1 == s2: " << (s1 == s2 ? "Да" : "Нет") << endl;
        cout << "2 принадлежит s1: " << (s1 > 2 ? "Да" : "Нет") << endl;
        cout << "5 принадлежит s1: " << (s1 > 5 ? "Да" : "Нет") << endl;

        cout << "Элементы s1 в обратном порядке: ";
        for (Iterator it = s1 - (s1.getSize() - 1); it != s1.begin(); --it) {
            cout << *it << " ";
        }
        cout << *s1.begin() << endl;

        cout << "s1[1] = " << s1[1] << endl;

    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}