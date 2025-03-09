#include <iostream>
#include <string>
#include <cstdarg>

using namespace std;

string fun(int n) {
    string s;
    while (n > 0) {
        s += '0' + (n % 3);
        n /= 3;
    }
    int len = s.length();
    for (int i = 0; i < len / 2; ++i) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
    return s;
}

string conv(int k, ...) {
    va_list args;
    va_start(args, k);

    string r;
    for (int i = 0; i < k; ++i) {
        int num = va_arg(args, int);
        r += fun(num) + " ";
    }

    va_end(args);
    return r;
}

int main() {
    cout << conv(3, 70, 21, 14) << endl;
    cout << conv(4, 70, 21, 14, 11) << endl;
    cout << conv(6, 70, 21, 14, 11, 56, 44) << endl;
    return 0;
}