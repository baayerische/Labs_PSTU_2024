#include <iostream>
using namespace std;

int main() 
{
    const int r = 3;
    const int c = 4;
    int arr[r][c] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 3, 12}
    };

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int num;
    cin >> num;

    bool delC[c] = { 0 };

    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            if (arr[i][j] == num) {
                delC[j] = 1;
                break;
            }
        }
    }

    int newC = 0;
    for (int j = 0; j < c; j++) {
        if (!delC[j]) {
            newC++;
        }
    }

    int** newArr = new int* [r];
    for (int i = 0; i < r; i++) {
        newArr[i] = new int[newC];
    }

    for (int i = 0; i < r; i++) {
        int newJ = 0;
        for (int j = 0; j < c; j++) {
            if (!delC[j]) {
                newArr[i][newJ] = arr[i][j];
                newJ++;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < newC; j++) {
            cout << newArr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}