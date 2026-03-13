#include "shell_sort.h"
#include <chrono>

using namespace std;

void perform_shell_sort(vector<int> a, int size, long long &comparisons)
{
    int gap = 1;
    while (gap < size / 3 && ++comparisons)
    {
        gap = 3 * gap + 1;
    }
    while (gap >= 1 && ++comparisons)
    {
        for (int i = gap; ++comparisons && i < size; i++)
        {
            int j = i,
                temp = a[j];
            while (j >= gap && a[j - gap] > temp && (comparisons += 2))
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }
        gap /= 3;
    }
}

void perform_shell_sort(vector<int> &a, int size)
{
    int gap = 1;
    while (gap < size / 3)
    {
        gap = 3 * gap + 1;
    }
    while (gap >= 1)
    {
        for (int i = gap; i < size; i++)
        {
            int j = i,
                temp = a[j];
            while (j >= gap && a[j - gap] > temp)
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }
        gap /= 3;
    }
}

SortResult shell_sort(ArrayData &data)
{
    SortResult res = {0.0, 0LL};

    perform_shell_sort(data.element, data.dataSize, res.comparisons);

    auto start = chrono::high_resolution_clock::now();
    perform_shell_sort(data.element, data.dataSize);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    res.runTime = duration.count();

    return res;
}
