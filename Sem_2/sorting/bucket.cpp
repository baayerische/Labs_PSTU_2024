#include <iostream>
using namespace std;

int* bucketSort(int arr[], int n)
{
    const int BUCKET_NUM = 10;
    const int BUCKET_SIZE = 10;
    int buckets[BUCKET_NUM][BUCKET_SIZE];
    int bucketSizes[BUCKET_NUM] = { 0 };

    for (int i = 0; i < n; i++)
    {
        int bucketIndex = arr[i] / BUCKET_NUM;
        buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
        bucketSizes[bucketIndex]++;
    }

    for (int i = 0; i < BUCKET_NUM; i++)
    {
        for (int j = 0; j < bucketSizes[i]; j++)
        {
            int tmp = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > tmp)
            {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = tmp;
        }
    }

    int idx = 0;
    for (int i = 0; i < BUCKET_NUM; i++)
    {
        for (int j = 0; j < bucketSizes[i]; j++)
        {
            arr[idx++] = buckets[i][j];
        }
    }
    return arr;
}

int main()
{
    setlocale(LC_ALL, "RU");
    int arr[] = { 29, 25, 3, 49, 9, 37, 21, 43 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    bucketSort(arr, n);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}