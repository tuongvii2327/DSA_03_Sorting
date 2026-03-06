#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "utilities.h"

void read_file(const std::string &fileName, ArrayData &data);

void write_file(const std::string &fileName, const ArrayData &data);

void write_console_1(const Config &config, const SortResult &result);

void write_console_2(const Config &config, const SortResult &result);

void write_console_3(const Config &config, const SortResult &result1, const SortResult &result2, const SortResult &result3, const SortResult &result4);

void write_console_4(const Config &config, const SortResult &result1, const SortResult &result2);

void write_console_5(const Config &config, const SortResult &result1, const SortResult &result2);

#endif 