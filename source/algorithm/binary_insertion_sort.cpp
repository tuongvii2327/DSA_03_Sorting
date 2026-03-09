#include "binary_insertion_sort.h"
#include <chrono>
#include <algorithm>
#include <vector>

void perform_binary_insertion_sort(std::vector<int> &a, int n, long long &count_compare) 
{
    for (int i = 1; i < n; i++) 
    {
        int x = a[i];
        int left = 0;
        int right = i - 1;

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            ++count_compare;
            if (x < a[mid]) 
            {
                right = mid - 1;
            } 
            else 
            {
                left = mid + 1;
            }
        }

        for (int j = i - 1; j >= left; j--) 
        {
            a[j + 1] = a[j];
        }
        
        a[left] = x;
    }
}

SortResult binary_insertion_sort(ArrayData &data) 
{
    SortResult res = {0.0, 0LL};
    
    auto start = std::chrono::high_resolution_clock::now();

    perform_binary_insertion_sort(data.element, data.dataSize, res.comparisons);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    res.runTime = duration.count();

    return res;
}