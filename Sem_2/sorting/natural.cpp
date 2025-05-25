#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
using namespace filesystem;

void distributeSeries(const path& fdata, const path& f1, const path& f2)
{
    ifstream data(fdata);
    ofstream file1(f1), file2(f2);

    if (!data.is_open() || !file1.is_open() || !file2.is_open())
    {
        cerr << "Cannot open file\n";
        return;
    }

    int first, second;
    bool flag = true;

    if (!(data >> first)) return;

    file1 << first << ' ';

    while (data >> second)
    {
        if (second < first) flag = !flag;

        if (flag) file1 << second << ' ';
        else file2 << second << ' ';

        first = second;
    }
}

void mergeSeries(const path& fdata, const path& f1, const path& f2)
{
    ifstream file1(f1), file2(f2);
    ofstream data(fdata);

    if (!data.is_open() || !file1.is_open() || !file2.is_open())
    {
        cerr << "Cannot open file\n";
        return;
    }

    int val1, val2;
    bool flag1 = static_cast<bool>(file1 >> val1);
    bool flag2 = static_cast<bool>(file2 >> val2);

    while (flag1 && flag2)
    {
        if (val1 <= val2)
        {
            data << val1 << ' ';
            flag1 = static_cast<bool>(file1 >> val1);
        }
        else
        {
            data << val2 << ' ';
            flag2 = static_cast<bool>(file2 >> val2);
        }
    }

    while (flag1)
    {
        data << val1 << ' ';
        flag1 = static_cast<bool>(file1 >> val1);
    }

    while (flag2)
    {
        data << val2 << ' ';
        flag2 = static_cast<bool>(file2 >> val2);
    }
}

void naturalSort(const path& fdata, const path& f1, const path& f2)
{
    bool sorted = false;

    while (!sorted)
    {
        distributeSeries(fdata, f1, f2);

        if (file_size(f2) == 0)
        {
            sorted = true;
            if (exists(fdata)) remove(fdata);
            rename(f1, fdata);
        }
        else mergeSeries(fdata, f1, f2);
    }

    remove(f2);
}

void printData(const path& fdata)
{
    ifstream fin(fdata);
    int val;

    while (fin >> val)
    {
        cout << val << ' ';
    }
    cout << '\n';

    //fin.close();
}

int main()
{
    string data = "data.txt";
    string f1 = "f1.txt";
    string f2 = "f2.txt";

    printData(data);

    naturalSort(data, f1, f2);

    printData(data);

    return 0;
}