#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "utilities.h"

int partition(std::vector<int> &a, int left, int right, long long &count_compare);

void perform_quick_sort(std::vector<int> a, int left, int right, long long &count_compare);

int partition(std::vector<int> &a, int left, int right);

void perform_quick_sort(std::vector<int> &a, int left, int right);

SortResult quick_sort(ArrayData &data);

#endif