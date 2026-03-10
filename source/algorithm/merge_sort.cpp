#include "merge_sort.h"
#include <chrono>
#include <algorithm>


void merge_arrays(std::vector <int> &a, int start, int mid,  int end, long long &count_compare) 
{
    int left_size = mid - start + 1;
    int right_size = end - mid;

    std::vector <int> left(left_size), right(right_size);

    for (int i = 0; ++count_compare && i < left_size; i++) 
        left[i] = a[start + i];
    
    for (int i = 0; ++count_compare && i < right_size; i++) 
        right[i] = a[mid + i + 1];
    
    int i = 0, j = 0, k = start;

    while (i < left_size && j < right_size && (count_compare += 2)) 
    {
        if (++count_compare && left[i] < right[j]) 
        {
            a[k] = left[i];
            i++;
        }
        else 
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size && ++count_compare) {
        a[k] = left[i];
        k++; i++;
    }
    while (j < right_size && ++count_compare) {
        a[k] = right[j];
        k++; j++;
    }
}

void perform_merge_sort(std::vector<int> a, int n, int start, int end, long long &count_compare) 
{
    if (start >= end) 
        return;
    int mid = (start + end) / 2;
    perform_merge_sort(a, n, start, mid, count_compare);
    perform_merge_sort(a, n, mid + 1, end, count_compare);
    merge_arrays(a, start, mid, end, count_compare);
}



void merge_arrays(std::vector <int> &a, int start, int mid,  int end) 
{
    int left_size = mid - start + 1;
    int right_size = end - mid;

    std::vector <int> left(left_size), right(right_size);

    for (int i = 0;i < left_size; i++) 
        left[i] = a[start + i];
    
    for (int i = 0;i < right_size; i++) 
        right[i] = a[mid + i + 1];
    
    int i = 0, j = 0, k = start;

    while (i < left_size && j < right_size) 
    {
        if (left[i] < right[j]) 
        {
            a[k] = left[i];
            i++;
        }
        else 
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        a[k] = left[i];
        k++; i++;
    }
    while (j < right_size) {
        a[k] = right[j];
        k++; j++;
    }
}

void perform_merge_sort(std::vector<int> &a, int n, int start, int end) 
{
    if (start >= end) 
        return;
    int mid = (start + end) / 2;
    perform_merge_sort(a, n, start, mid);
    perform_merge_sort(a, n, mid + 1, end);
    merge_arrays(a, start, mid, end);
}

SortResult merge_sort(ArrayData &data) 
{
    SortResult res = {0.0, 0LL};
     perform_merge_sort(data.element, data.dataSize, 0, data.dataSize - 1, res.comparisons);

    auto start = std::chrono::high_resolution_clock::now();

    perform_merge_sort(data.element, data.dataSize, 0, data.dataSize - 1);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    res.runTime = duration.count();

    return res;
}