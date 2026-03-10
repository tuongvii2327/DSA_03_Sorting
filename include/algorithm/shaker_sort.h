#ifndef SHAKER_SORT_H
#define SHAKER_SORT_H

#include <vector>
#include "utilities.h"

void perform_shaker_sort(std::vector<int> a, int n, long long &count_compare);

void perform_shaker_sort(std::vector<int> &a, int n);

SortResult shaker_sort(ArrayData &data);

#endif