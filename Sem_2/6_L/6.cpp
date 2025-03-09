#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool dig(const string& line) {
    for (char ch : line) {
        if (ch >= '0' && ch <= '9') {
            return 1;
        }
    }
    return 0;
}

bool startsWithA(const string& line) {
    return !line.empty() && (line[0] == 'A' || line[0] == 'a');
}

int main() {
    ifstream myfile("F1.txt");
    ofstream myfile2("F2.txt");
    string line;

    while (getline(myfile, line)) {
        if (!dig(line)) {
            myfile2 << line << endl;
        }
    }

    myfile.close();
    myfile2.close();

    ifstream myfile2_read("F2.txt");

    int count = 0;
    while (getline(myfile2_read, line)) {
        if (startsWithA(line)) {
            count++;
        }
    }

    myfile2_read.close();

    cout << "count: " << count << endl;

    return 0;
}