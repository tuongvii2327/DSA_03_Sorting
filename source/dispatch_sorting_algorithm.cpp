#include "utilities.h"
#include "dispatch_sorting_algorithm.h"
#include "quick_sort.h"
#include "shaker_sort.h"

SortResult dispatch_sorting_algorithm(std::string algorithm, ArrayData &data)
{

    SortResult result;

    if (algorithm == "quick-sort")
    {
        result = quick_sort(data);
    }
    else if (algorithm == "shaker-sort")
    {
        result = shaker_sort(data);
    }
    //continue else if....

    return result;
}