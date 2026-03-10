#include "utilities.h"
#include "dispatch_sorting_algorithm.h"

#include "selection_sort.h"
#include "bubble_sort.h"
#include "shell_sort.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "radix_sort.h"
#include "flash_sort.h"
#include "quick_sort.h"
#include "shaker_sort.h"
#include "counting_sort.h"
#include "binary_insertion_sort.h"

SortResult dispatch_sorting_algorithm(std::string algorithm, ArrayData &data)
{

    SortResult result;

    // TuongVi
    if (algorithm == "selection-sort")
    {
        result = selection_sort(data);
    }
    else if (algorithm == "bubble-sort")
    {
        result = bubble_sort(data);
    }
    else if (algorithm == "insertion-sort")
    {
        result = insertion_sort(data);
    }
    else if (algorithm == "merge-sort") 
    {
        result = merge_sort(data);
    }
    else if (algorithm == "radix-sort") 
    {
        result = radix_sort(data);
    }
    else if (algorithm == "flash-sort") 
    {
        result = flash_sort(data);
    }
    else if (algorithm == "counting-sort")
    {
        result = counting_sort(data);
    }
    else if (algorithm == "binary-insertion-sort")
    {
        result = binary_insertion_sort(data);
    }
    else if (algorithm == "shell-sort")
    {
        result = shell_sort(data);
    }
    else if (algorithm == "heap-sort")
    {
        result = heap_sort(data);
    }
    return result;
}