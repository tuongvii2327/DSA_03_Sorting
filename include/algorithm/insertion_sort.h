#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "utilities.h"

void perform_insertion_sort(std::vector<int> a, int n, long long &count_compare);
void perform_insertion_sort(std::vector<int> &a, int n);
SortResult insertion_sort(ArrayData &data);

#endif