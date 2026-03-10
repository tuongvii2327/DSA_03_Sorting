#include "utilities.h"
#include "dispatch_sorting_algorithm.h"

#include "selection_sort.h"
#include "bubble_sort.h"
#include "shell_sort.h"
#include "heap_sort.h"

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