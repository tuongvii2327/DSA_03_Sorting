#include "utilities.h"
#include "dispatch_sorting_algorithm.h"
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

    //continue else if....
    if (algorithm == "insertion-sort")
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
    else if (algorithm == "counting-sort")
    {
        result = counting_sort(data);
    }
    else if (algorithm == "binary-insertion-sort")
    {
        result = binary_insertion_sort(data);
    }
    //continue else if....

    return result;
}