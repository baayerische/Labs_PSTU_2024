#include <iostream>
using namespace std;
int main()
{
    int n, tmp;
    bool plusFirst = false;
    bool minusFirst = false;
    cout << "enter lenght:" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "enter num:" << endl;
        cin >> tmp;
        if (!plusFirst && !minusFirst)
        {
            if (tmp > 0) 
            { 
                plusFirst = true; 
            }
            else if (tmp < 0) 
            { 
                minusFirst = true; 
            }
        }
    }
    if (plusFirst)
    {
        cout << "first, a positive number was entered";
    }
    else if (minusFirst)
    {
        cout << "first, a negative number was entered";
    }
    else
    {
        cout << "all the elements were null";

    }
    cout << endl;
    return 0;
}