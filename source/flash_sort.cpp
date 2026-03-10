#include "flash_sort.h"
#include <chrono>
#include <algorithm>

void perform_flash_sort(std::vector<int> a, int n, long long &count_compare) 
{
    int mn = a[0], mx = a[0];
    for (int i = 1; count_compare += 3, i < n; i++) 
    {
        mn = std::min(mn, a[i]);
        mx = std::max(mx, a[i]);
    }
    if (++count_compare && mx == mn) 
        return;
    
    int num = 0.45 * n;
    std::vector <int> pos(num);
    double c1 = (double)(num - 1)/(mx - mn);
    for (int i = 0; ++count_compare && i < n; i++) 
        pos[c1 * (a[i] - mn)]++;

    for (int i = 1; ++count_compare && i < num; i++) 
        pos[i] += pos[i-1];
    
    int count = 0, i = 0;

    while (++count_compare && count < n) 
    {
        int k = c1 * (a[i] - mn);
        while (++count_compare && i >= pos[k])
        {
            i++;
            k = c1 * (a[i] - mn);
        }
        int tmp = a[i];
        while (++count_compare && i != pos[k]) 
        {
            k = c1 * (tmp - mn);
            pos[k]--;
            std::swap(a[pos[k]], tmp);
            count++;
        }
    }
    
    perform_insertion_sort(a, n, count_compare);
}


void perform_flash_sort(std::vector<int> &a, int n) 
{
    int mn = a[0], mx = a[0];
    for (int i = 1;i < n; i++) 
    {
        mn = std::min(mn, a[i]);
        mx = std::max(mx, a[i]);
    }
    if (mx == mn) 
        return;
    
    int num = 0.45 * n;
    std::vector <int> pos(num);
    double c1 = (double)(num - 1)/(mx - mn);
    for (int i = 0; i < n; i++) 
        pos[c1 * (a[i] - mn)]++;

    for (int i = 1; i < num; i++) 
        pos[i] += pos[i-1];
    
    int count = 0, i = 0;

    while (count < n) 
    {
        int k = c1 * (a[i] - mn);
        while (i >= pos[k])
        {
            i++;
            k = c1 * (a[i] - mn);
        }
        int tmp = a[i];
        while (i != pos[k]) 
        {
            k = c1 * (tmp - mn);
            pos[k]--;
            std::swap(a[pos[k]], tmp);
            count++;
        }
    }
    
    perform_insertion_sort(a, n);
}


SortResult flash_sort(ArrayData &data) 
{
    SortResult res = {0.0, 0LL};
    
    perform_flash_sort(data.element, data.dataSize, res.comparisons);   

    auto start = std::chrono::high_resolution_clock::now();

    perform_flash_sort(data.element, data.dataSize);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    res.runTime = duration.count();

    return res;
}