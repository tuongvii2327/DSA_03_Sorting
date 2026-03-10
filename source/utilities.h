#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <vector>

struct Config 
{
    int commandType; 
    std::string mode; 
    std::string algorithm1, algorithm2;
    std::string inputFile, inputOrder;
    int inputSize;
    std::string outputFile, outputParameter;
};

struct ArrayData
{
    int dataSize;
    std::vector<int> element;
};

struct SortResult
{
    double runTime; //ms
    long long comparisons;
};

#endif