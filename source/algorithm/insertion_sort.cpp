#include "insertion_sort.h"
#include <chrono>
#include <algorithm>

void perform_insertion_sort(std::vector<int> a, int n, long long &count_compare) {
    for (int i = 1; i < n && ++count_compare; i++) 
    {
        int key = a[i];
        int j = i - 1;
        while ((count_compare += 2) && j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void perform_insertion_sort(std::vector<int> &a, int n) {
    for (int i = 1; i < n; i++) 
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

SortResult insertion_sort(ArrayData &data) 
{
    SortResult res = {0.0, 0LL};
    
    perform_insertion_sort(data.element, data.dataSize, res.comparisons);
    
    auto start = std::chrono::high_resolution_clock::now();

    perform_insertion_sort(data.element, data.dataSize);
    

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    res.runTime = duration.count();

    return res;
}