#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include "utilities.h"

void digit_sort(std::vector <int> a, int n, int exp, long long &count_compare);
void perform_radix_sort(std::vector<int> a, int n, long long &count_compare);

void digit_sort(std::vector <int> &a, int n, int exp);
void perform_radix_sort(std::vector<int> &a, int n);

SortResult radix_sort(ArrayData &data);

#endif