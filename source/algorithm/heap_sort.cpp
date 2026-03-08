#include "heap_sort.h"
#include <chrono>

using namespace std;

void heapify(vector<int>& a, int size, int id, long long& comparisons)
{
    comparisons += 3;
    int biggest = id,
        leftNode = id * 2 + 1,
        rightNode = id * 2 + 2;
    if (leftNode < size && a[leftNode] > a[biggest]) biggest = leftNode;
    if (rightNode < size && a[rightNode] > a[biggest]) biggest = rightNode;
    if (biggest != id)
    {
        swap(a[id], a[biggest]);
        heapify(a, size, biggest, comparisons);
    }
}

void perform_heap_sort(vector<int>& a, int size, long long& comparisons)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(a, size, i, comparisons);
    }
    for (int j = size - 1; j > 0; j--)
    {
        swap(a[0], a[j]);
        heapify(a, j, 0, comparisons);
    }
}

SortResult heap_sort(ArrayData& data)
{
    SortResult res = { 0.0, 0LL };

    auto start = chrono::high_resolution_clock::now();

    perform_heap_sort(data.element, data.dataSize, res.comparisons);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    res.runTime = duration.count();

    return res;
}

