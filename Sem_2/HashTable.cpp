#include <iostream>

using namespace std;

const int tsize = 10;
const int ekey = -1;
int keys[tsize];
int values[tsize];

void init()
{
    for(int i = 0; i < tsize; i++)
    {
        keys[i] = ekey;
    }
}

int Hash(int key)
{
    return key % tsize;
}

void insert(int value, int key)
{
    int index = Hash(key);
    int sindex = index;

    while (keys[index] != ekey && keys[index] != key)
    {
        index = (index + 1) % tsize;
        if (index == sindex)
        {
            cout << "Table overflow" << endl;
            return;
        }
    }

    keys[index] = key;
    values[index] = value;
}

bool search(int key, int &value_out)
{
    int index = Hash(key);
    int sindex = index;

    while (keys[index] != ekey)
    {
        if (keys[index] == key)
        {
            value_out = values[index];
            return true;
        }
        index = (index + 1) % tsize;
        if (index == sindex) break;
    }

    return false;
}

void remove(int key)
{
    int index = Hash(key);
    int sindex = index;

    while (keys[index] != ekey)
    {
        if (keys[index] == key)
        {
            keys[index] = ekey;
            return;
        }
        index = (index + 1) % tsize;
        if (index == sindex) break;
    }
}

void printTable()
{
    for (int i = 0; i < tsize; i++)
    {
        if (keys[i] != ekey)
            cout << i << ": " << keys[i] << " -> " << values[i] << endl;
        else
            cout << i << ": [empty]" << endl;
    }
}

int main()
{
    init();
    int n, key, value, val, del;
    cout << "How many numbers, but not > 10" << endl;
    cin >> n;
    cout << "Enter value then key" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> key;
        cin >> value;
        insert(key, value);
    }
    printTable();
    cout << "Enter key to find value" << endl;
    cin >> key;
    if (search(key, val))
    {
        cout << "Found key: " << key << " with value: " << val << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }
    cout << "Enter key to delete" << endl;
    cin >> del;
    remove(del);
    printTable();
    return 0;
}
