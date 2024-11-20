#include <iostream>
using namespace std;
int main()
{
    int n, tmp, * ptr = &tmp, max, min;
    cout << "count of numbers: ";
    cin >> n;
    cout << "num1: ";
    cin >> *ptr;
    max = *ptr;
    min = *ptr;
    for (int i = 2; i <= n; i++)
    {
        cin >> *ptr;
        if (*ptr > max)
        {
            max = *ptr;
        }
        else if (*ptr < min)
        {
            min = *ptr;
        }
        cout << "min: " << min << endl;
        cout << "max: " << max << endl;
    }
    return 0;
}
