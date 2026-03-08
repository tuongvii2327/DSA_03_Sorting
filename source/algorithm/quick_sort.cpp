#include "quick_sort.h"
#include <chrono>
#include <algorithm>
#include <vector>

int partition(std::vector<int> &a, int left, int right, long long &count_compare) 
{
    int pivot = a[left + (right - left) / 2];
    int i = left;
    int j = right;

    while (i <= j) 
    {
        while (++count_compare && a[i] < pivot) 
        {
            ++i;
        }
        
        while (++count_compare && a[j] > pivot) 
        {
            --j;
        }
        
        if (i <= j) 
        {
            std::swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    return i;
}

void perform_quick_sort(std::vector<int> &a, int left, int right, long long &count_compare) 
{
    if (left >= right) 
    {
        return;
    }

    int index = partition(a, left, right, count_compare);
    
    perform_quick_sort(a, left, index - 1, count_compare);
    perform_quick_sort(a, index, right, count_compare);
}

SortResult quick_sort(ArrayData &data) 
{
    SortResult res = {0.0, 0LL};
    
    auto start = std::chrono::high_resolution_clock::now();

    perform_quick_sort(data.element, 0, data.dataSize - 1, res.comparisons);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    res.runTime = duration.count();

    return res;
}