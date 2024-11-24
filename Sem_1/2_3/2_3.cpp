#include <iostream>
using namespace std;
int main()
{
    int n, p, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        p = 1;
        for (int j = i; j <= 2 * i; j++)
        {
            p *= j;
        }
        sum += p;

    }

    sum += p;
    cout << sum << endl;
    return 0;
}