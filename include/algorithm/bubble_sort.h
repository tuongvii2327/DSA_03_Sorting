#ifndef BUBBLE_H
#define BUBBLE_H

#include "utilities.h"

void perform_bubble_sort(std::vector<int> a, int size, long long &comparisons);

void perform_bubble_sort(std::vector<int> &a, int size);

SortResult bubble_sort(ArrayData &data);

#endif
