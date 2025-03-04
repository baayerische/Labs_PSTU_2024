#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int r, range_min, range_max, min = 100;
    int a[10];
    float sA = 0;

    srand(time(0));

    range_min = 1;
    range_max = 100;

    for (int i = 0; i < 10; i++)
    {
        a[i] = rand() % (range_max - range_min + 1) + range_min; 
        cout << a[i] << " ";

        sA += a[i];

        if (a[i] < min)
        {
            min = a[i];
        }
    }
    sA /= 10;
    cout << endl;

    int newSize = 0;
    float newArray[13];

    newArray[newSize++] = sA;
    newArray[newSize++] = sA;
    newArray[newSize++] = sA;

    for (int i = 0; i < 10; i++)
    {
        if (a[i] != min)
        {
            newArray[newSize] = a[i];
            newSize++;
        }
    }

    for (int i = 0; i < newSize; i++)
    {
        cout << newArray[i] << " ";
    }
    cout << endl;

    return 0;
}
