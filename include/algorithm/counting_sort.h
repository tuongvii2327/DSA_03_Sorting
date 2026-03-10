#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include "utilities.h"

void perform_counting_sort(std::vector<int> a, int n, long long &count_compare);

void perform_counting_sort(std::vector<int> &a, int n);

SortResult counting_sort(ArrayData &data); 


#endif