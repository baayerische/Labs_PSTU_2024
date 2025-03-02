#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;

    cin >> str;

    for (size_t i = 0; i < str.length(); ++i) {
        for (size_t j = 0; j < str.length() - i - 1; ++j) {
            if (str[j] < str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }

    cout << str << endl;

    return 0;
}