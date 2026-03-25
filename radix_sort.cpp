#include "radix_sort.h"
#include <chrono>
#include <algorithm>
#include <climits>

void digit_sort(std::vector <int> a, int n, int exp, long long &count_compare) 
{
    std::vector <int> pos(10, 0), res(n);
    for (int i = 0; ++count_compare && i < n; i++) 
        pos[(a[i] / exp) % 10]++;
    
    for (int i = 1; ++count_compare && i < 10;i++)
        pos[i] += pos[i-1];

    for (int i = n - 1; ++count_compare && i >= 0; i--) 
        res[--pos[(a[i] / exp) % 10]] = a[i];
    for (int i = 0; ++count_compare && i < n; i++) 
        a[i] = res[i];
}
void perform_radix_sort(std::vector<int> a, int n, long long &count_compare) 
{
    int mx = INT_MIN;
    for (int i = 0; ++count_compare && i < n; i++) mx = std::max(mx, a[i]);
    for (int exp = 1; ++count_compare && mx/exp > 0; exp *= 10) 
        digit_sort(a, n, exp, count_compare);
}


void digit_sort(std::vector <int> &a, int n, int exp) 
{
    std::vector <int> pos(10, 0), res(n);
    for (int i = 0;i < n; i++) 
        pos[(a[i] / exp) % 10]++;
    
    for (int i = 1;i < 10;i++)
        pos[i] += pos[i-1];

    for (int i = n - 1;i >= 0; i--) 
        res[--pos[(a[i] / exp) % 10]] = a[i];
    for (int i = 0;i < n; i++) 
        a[i] = res[i];
}
void perform_radix_sort(std::vector<int> &a, int n) 
{
    int mx = INT_MIN;
    for (int i = 0;i < n; i++) mx = std::max(mx, a[i]);
    for (int exp = 1;mx/exp > 0; exp *= 10) 
        digit_sort(a, n, exp);
}


SortResult radix_sort(ArrayData &data) 
{
    SortResult res = {0.0, 0LL};
    
    perform_radix_sort(data.element, data.dataSize, res.comparisons);


    auto start = std::chrono::high_resolution_clock::now();

    perform_radix_sort(data.element, data.dataSize);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    res.runTime = duration.count();

    return res;
}