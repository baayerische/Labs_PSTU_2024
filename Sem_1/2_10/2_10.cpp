#include <iostream>
using namespace std;
int main()
{
    int n, tmp, max;
    cout << "enter lenght:" << endl;
    cin >> n;
    cout << "enter num1:" << endl;
    cin >> max;
    for (int i = 2; i <= n; i++)
    {
        cout << "enter next num : " << endl;
            cin >> tmp;
        if (tmp > max) 
        { 
            max = tmp; 
        }
    }
    cout << "max: " << max << endl;
    return 0;
}