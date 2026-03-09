#include "shell_sort.h"
#include <chrono>

using namespace std;

void perform_shell_sort(vector<int>& a, int size, long long& comparisons)
{
    for (int gap = size / 2; comparisons++ && gap > 0; gap /= 2)
    {
        for (int i = gap; comparisons++ && i < size; i++)
        {
            int j = i,
                temp = a[j];
            while (j >= gap && a[j - gap] > temp && comparisons++ && comparisons++)
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }
    }
}

SortResult shell_sort(ArrayData& data)
{
    SortResult res = { 0.0, 0LL };

    auto start = chrono::high_resolution_clock::now();

    perform_shell_sort(data.element, data.dataSize, res.comparisons);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    res.runTime = duration.count();

    return res;
}
