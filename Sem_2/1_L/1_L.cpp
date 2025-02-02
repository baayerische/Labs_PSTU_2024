#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    //рандомный массив из 10 элементов и вывод
    int r, range_min, range_max, min = 100;
    int a[10];
    float sA = 0;

    srand(time(0));

    range_min = 1;
    range_max = 100;

    for (int i = 0; i < 10; i++)
    {
        a[i] = rand() % (range_max - range_min + 1) + range_min; 
        cout << a[i] << " ";//вывод

        sA += a[i];

        if (a[i] < min)
        {
            min = a[i];//поиск минимального числа
        }
    }
    sA /= 10;//среднее арифметическое
    cout << endl;

    //удаление минимальных элементов и добавление 3х средних арифметических
    int newSize = 0;
    float newArray[13];//новый массив, который будет содержать 3 новых элемента 

    //добавляем три элемента, равных среднему арифметическому, в начало 
    newArray[newSize++] = sA;
    newArray[newSize++] = sA;
    newArray[newSize++] = sA;

    for (int i = 0; i < 10; i++)
    {
        if (a[i] != min)
        {
            newArray[newSize] = a[i];//добавляем в массив все элементы, кроме равных минимальному
            newSize++;
        }
    }

    //вывод нового массива
    for (int i = 0; i < newSize; i++)
    {
        cout << newArray[i] << " ";
    }
    cout << endl;

    return 0;
}