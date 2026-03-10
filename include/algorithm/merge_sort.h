#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "utilities.h"

void merge_arrays(std::vector <int> &a, int start, int mid, int end, long long &count_compare);
void perform_merge_sort(std::vector<int> a, int n, long long &count_compare);

void merge_arrays(std::vector <int> &a, int start, int mid, int end);
void perform_merge_sort(std::vector<int> &a, int n);


SortResult merge_sort(ArrayData &data);

#endif