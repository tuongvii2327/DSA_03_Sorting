#include "utilities.h"
#include "selection_sorting_algorithm.h"
#include "quick_sort.h"

SortResult selection_sorting_algorithm(std::string algorithm, ArrayData &data)
{

    SortResult result;

    if (algorithm == "quick-sort")
    {
        result = quick_sort(data);
    }
    //continue else if....

    return result;
}