#include "file_work.h"

int make_file(const char* f_name) {
    ofstream stream(f_name);
    if (!stream) return -1;
    int n;
    cout << "Enter number of records: ";
    cin >> n;
    Money m;
    for (int i = 0; i < n; i++) {
        cout << "Enter money " << i + 1 << ": ";
        cin >> m;
        stream << m << endl;
    }
    stream.close();
    return n;
}

int print_file(const char* f_name) {
    ifstream stream(f_name);
    if (!stream) return -1;
    Money m;
    int count = 0;
    while (stream >> m) {
        cout << m << endl;
        count++;
    }
    stream.close();
    return count;
}

int del_range_file(const char* f_name, const Money& k1, const Money& k2) {
    ifstream stream(f_name);
    if (!stream) return -1;
    ofstream temp("temp.txt");
    Money p;
    int count = 0;
    while (stream >> p) {
        if (stream.eof()) break;
        if (!(p >= k1 && p <= k2)) temp << p << endl;
        else count++;
    }
    stream.close();
    temp.close();
    remove(f_name);
    rename("temp.txt", f_name);
    return count;
}

int double_value_file(const char* f_name, const Money& m) {
    ifstream stream(f_name);
    if (!stream) return -1;
    ofstream temp("temp.txt");
    Money p;
    int count = 0;
    while (stream >> p) {
        if (stream.eof()) break;
        if (p == m) {
            long newRub = p.getRub() * 2;
            int newKop = p.getKop() * 2;
            if (newKop >= 100) {
                newRub += newKop / 100;
                newKop %= 100;
            }
            p = Money(newRub, newKop);
            count++;
        }
        temp << p << endl;
    }
    stream.close();
    temp.close();
    remove(f_name);
    rename("temp.txt", f_name);
    return count;
}

int add_begin_file(const char* f_name, int k, const Money& m) {
    ifstream stream(f_name);
    if (!stream) return -1;
    ofstream temp("temp.txt");
    for (int i = 0; i < k; i++) {
        temp << m << endl;
    }
    Money p;
    while (stream >> p) {
        if (stream.eof()) break;
        temp << p << endl;
    }
    stream.close();
    temp.close();
    remove(f_name);
    rename("temp.txt", f_name);
    return k;
}