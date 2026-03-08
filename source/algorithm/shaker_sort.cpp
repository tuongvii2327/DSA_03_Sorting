#include "shaker_sort.h"
#include <chrono>
#include <algorithm>
#include <vector>

void perform_shaker_sort(std::vector<int> &a, int n, long long &count_compare) 
{
    int left = 0;
    int right = n - 1;
    int k = 0;

    while (left < right) 
    {
        for (int i = left; i < right; i++) 
        {
            if (++count_compare && a[i] > a[i + 1]) 
            {
                std::swap(a[i], a[i + 1]);
                k = i;
            }
        }
        right = k;

        for (int i = right; i > left; i--) 
        {
            if (++count_compare && a[i] < a[i - 1]) 
            {
                std::swap(a[i], a[i - 1]);
                k = i;
            }
        }
        left = k;
    }
}

SortResult shaker_sort(ArrayData &data) 
{
    SortResult res = {0.0, 0LL};
    
    auto start = std::chrono::high_resolution_clock::now();

    if (data.dataSize > 0) 
    {
        perform_shaker_sort(data.element, data.dataSize, res.comparisons);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    res.runTime = duration.count();

    return res;
}