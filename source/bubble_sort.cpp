#include "bubble_sort.h"
#include <chrono>

using namespace std;

void perform_bubble_sort(vector<int> a, int size, long long &comparisons)
{
    for (int i = 0; ++comparisons && i < size - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; ++comparisons && j < size - i - 1; j++)
        {
            ++comparisons;
            if (a[j] > a[j + 1])
            {
                isSwap = true;
                swap(a[j], a[j + 1]);
            }
        }
        ++comparisons;
        if (!isSwap)
            break;
    }
}

void perform_bubble_sort(vector<int> &a, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                isSwap = true;
                swap(a[j], a[j + 1]);
            }
        }
        if (!isSwap)
            break;
    }
}

SortResult bubble_sort(ArrayData &data)
{
    SortResult res = {0.0, 0LL};

    perform_bubble_sort(data.element, data.dataSize, res.comparisons);

    auto start = chrono::high_resolution_clock::now();
    perform_bubble_sort(data.element, data.dataSize);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    res.runTime = duration.count();

    return res;
}
