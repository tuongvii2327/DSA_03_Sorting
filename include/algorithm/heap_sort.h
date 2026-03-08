#ifndef HEAP_H
#define HEAP_H

#include "utilities.h"

void heapify(std::vector<int>& a, int size, int id, long long& comparisons);
void perform_heap_sort(std::vector<int>& a, int size, long long& comparisons);

SortResult heap_sort(ArrayData& data);

#endif

