#include "counting_sort.h"
#include <chrono>
#include <vector>
#include <algorithm>

void perform_counting_sort(std::vector<int> &a, int n, long long &count_compare) 
{
    int max_val = a[0];
    int min_val = a[0];

    for (int i = 1; i < n; i++) 
    {
        if (++count_compare && a[i] > max_val) 
        {
            max_val = a[i];
        }
        if (++count_compare && a[i] < min_val) 
        {
            min_val = a[i];
        }
    }

    int range = max_val - min_val + 1;
    std::vector<int> count(range, 0);

    for (int i = 0; i < n; i++) 
    {
        count[a[i] - min_val]++;
    }

    int index = 0;
    for (int i = 0; i < range; i++) 
    {
        while (count[i] > 0) 
        {
            a[index++] = i + min_val;
            count[i]--;
        }
    }
}

SortResult counting_sort(ArrayData &data) 
{
    SortResult res = {0.0, 0LL};
    
    auto start = std::chrono::high_resolution_clock::now();

    perform_counting_sort(data.element, data.dataSize, res.comparisons);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    res.runTime = duration.count();

    return res;
}