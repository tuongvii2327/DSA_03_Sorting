#include "selection_sort.h"
#include <chrono>

using namespace std;

void perform_selection_sort(vector<int> &a, int size, long long &comparisons)
{
    for (int i = 0; comparisons++ && i < size - 1; i++)
    {
        int idSmall = i;
        for (int j = i + 1; comparisons++ && j < size; j++)
        {
            comparisons++;
            if (a[j] < a[idSmall]) idSmall = j;
        }
        swap(a[i], a[idSmall]);
    }
}

SortResult selection_sort(ArrayData &data)
{
    SortResult res = {0.0, 0LL};

    auto start = chrono::high_resolution_clock::now();

    perform_selection_sort(data.element, data.dataSize, res.comparisons);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    res.runTime = duration.count();

    return res;
}
