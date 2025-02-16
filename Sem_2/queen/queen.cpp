#include <iostream>
using namespace std;

const int N = 8;

void brd(int b[N]) 
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j) 
        {
            if (b[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

bool check(int b[N], int row, int col) 
{
    for (int i = 0; i < row; ++i) 
    {
        if (b[i] == col or abs(b[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

bool solve(int b[N], int row) 
{
    if (row == N) 
    {
        brd(b);
        return true; 
    }

    for (int col = 0; col < N; ++col) 
    {
        if (check(b, row, col)) 
        {
            b[row] = col;
            if (solve(b, row + 1)) 
                return true; 
            b[row] = -1;
        }
    }
    return false; 
}

int main() 
{
    int b[N] = { -1, -1, -1, -1, -1, -1, -1, -1 };
    if (!solve(b, 0))
        cout << "Решение не найдено." << endl;
    return 0;
}