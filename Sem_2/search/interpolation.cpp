#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int low, int high, int x) {
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }
        int pos = low + (((double)(x - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == x) return pos;

        if (arr[pos] < x) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int interpolationSearchRec(int arr[], int low, int high, int x) {
    if (low > high || x < arr[low] || x > arr[high]) return -1;

    if (low == high) {
        if (arr[low] == x) return low;
        return -1;
    }

    int pos = low + (((double)(x - arr[low]) * (high - low)) / (arr[high] - arr[low]));

    if (arr[pos] == x) return pos;

    if (arr[pos] < x)
        return interpolationSearchRec(arr, pos + 1, high, x);
    else
        return interpolationSearchRec(arr, low, pos - 1, x);
}

int main() {
    setlocale(LC_ALL, "RU");
    int arr[] = { 2, 2, 6, 7, 13, 18, 21, 84, 88, 77 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 18;

    int res = interpolationSearch(arr, 0, n - 1, x);
    if (res == -1)
        cout << "Ёлемент " << x << " не найден" << endl;
    else
        cout << "Ёлемент " << x << " найден по индексу " << res << endl;

    int resRec = interpolationSearchRec(arr, 0, n - 1, x);
    if (resRec == -1)
        cout << "Ёлемент " << x << " не найден (рекурси€)" << endl;
    else
        cout << "Ёлемент " << x << " найден по индексу " << resRec << " (рекурси€)" << endl;

    return 0;
}