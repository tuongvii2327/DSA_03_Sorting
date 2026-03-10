#ifndef FLASH_SORT_H
#define FLASH_SORT_H

#include "utilities.h"
#include "insertion_sort.h"

void perform_flash_sort(std::vector<int> a, int n, long long &count_compare);

void perform_flash_sort(std::vector<int> &a, int n);

SortResult flash_sort(ArrayData &data);

#endif