#ifndef SHELL_H
#define SHELL_H

#include "utilities.h"

void perform_shell_sort(std::vector<int> a, int size, long long &comparisons);

void perform_shell_sort(std::vector<int> &a, int size);

SortResult shell_sort(ArrayData &data);

#endif
