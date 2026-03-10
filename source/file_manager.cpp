#include "utilities.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>

void read_file(const std::string &fileName, ArrayData &data)
{
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open())
    {
        throw std::runtime_error(fileName + " not found!");
    }

    inputFile >> data.dataSize;
    data.element.resize(data.dataSize);
    for (int i = 0; i < data.dataSize; ++i)
    {
        inputFile >> data.element[i];
    }

    inputFile.close();
}

void write_file(const std::string &fileName, const ArrayData &data)
{
    std::ofstream outFile(fileName);
    if (!outFile.is_open())
    {
        throw std::runtime_error("cannot open " + fileName + "!");
    }

    outFile << data.dataSize << "\n";
    for (const int &num : data.element)
    {
        outFile << num << ' ';
    }

    outFile.close();
}

void write_console_1(const Config &config, const SortResult &result)
{
    std::cout << "ALGORITHM MODE" << '\n';
    std::cout << "Algorithm: " << config.algorithm1 << '\n';
    std::cout << "Input file: " << config.inputFile << '\n';
    std::cout << "Input size: " << config.inputSize << '\n';
    std::cout << "-------------------------" << '\n';
    if (config.outputParameter == "-time" || config.outputParameter == "-both")
    {
        std::cout << "Running time: " << std::fixed << std::setprecision(2) << result.runTime << " ms\n";
    }
    if (config.outputParameter == "-comp" || config.outputParameter == "-both")
    {
        std::cout << "Comparisons: " << result.comparisons << '\n';
    }
    std::cout << '\n';
}

void write_console_2(const Config &config, const SortResult &result)
{
    std::cout << "ALGORITHM MODE" << '\n';
    std::cout << "Algorithm: " << config.algorithm1 << '\n';
    std::cout << "Input size: " << config.inputSize << '\n';
    std::cout << "Input order: " << config.inputOrder << '\n';
    std::cout << "-------------------------" << '\n';
    if (config.outputParameter == "-time" || config.outputParameter == "-both")
    {
        std::cout << "Running time: " << std::fixed << std::setprecision(2) << result.runTime << " ms\n";
    }
    if (config.outputParameter == "-comp" || config.outputParameter == "-both")
    {
        std::cout << "Comparisons: " << result.comparisons << '\n';
    }
    std::cout << '\n';
}

void write_console_3(const Config &config, const SortResult &result1, const SortResult &result2, const SortResult &result3, const SortResult &result4)
{
    std::cout << "ALGORITHM MODE" << '\n';
    std::cout << "Algorithm: " << config.algorithm1 << '\n';
    std::cout << "Input size: " << config.inputSize << '\n';
    std::cout << '\n';

    std::cout << "Input order: Randomize" << '\n';
    std::cout << "-------------------------" << '\n';
    if (config.outputParameter == "-time" || config.outputParameter == "-both")
    {
        std::cout << "Running time: " << std::fixed << std::setprecision(2) << result1.runTime << " ms\n";
    }
    if (config.outputParameter == "-comp" || config.outputParameter == "-both")
    {
        std::cout << "Comparisons: " << result1.comparisons << '\n';
    }
    std::cout << '\n';

    std::cout << "Input order: Nearly Sorted" << '\n';
    std::cout << "-------------------------" << '\n';
    if (config.outputParameter == "-time" || config.outputParameter == "-both")
    {
        std::cout << "Running time: " << std::fixed << std::setprecision(2) << result2.runTime << " ms\n";
    }
    if (config.outputParameter == "-comp" || config.outputParameter == "-both")
    {
        std::cout << "Comparisons: " << result2.comparisons << '\n';
    }
    std::cout << '\n';

    std::cout << "Input order: Sorted" << '\n';
    std::cout << "-------------------------" << '\n';
    if (config.outputParameter == "-time" || config.outputParameter == "-both")
    {
        std::cout << "Running time: " << std::fixed << std::setprecision(2) << result3.runTime << " ms\n";
    }
    if (config.outputParameter == "-comp" || config.outputParameter == "-both")
    {
        std::cout << "Comparisons: " << result3.comparisons << '\n';
    }
    std::cout << '\n';

    std::cout << "Input order: Reversed" << '\n';
    std::cout << "-------------------------" << '\n';
    if (config.outputParameter == "-time" || config.outputParameter == "-both")
    {
        std::cout << "Running time: " << std::fixed << std::setprecision(2) << result4.runTime << " ms\n";
    }
    if (config.outputParameter == "-comp" || config.outputParameter == "-both")
    {
        std::cout << "Comparisons: " << result4.comparisons << '\n';
    }
    std::cout << '\n';
}

void write_console_4(const Config &config, const SortResult &result1, const SortResult &result2)
{
    std::cout << "COMPARE MODE\n";
    std::cout << "Algorithm: " << config.algorithm1 << " | " << config.algorithm2 << '\n';
    std::cout << "Input file: " << config.inputFile << '\n';
    std::cout << "Input size: " << config.inputSize << '\n';
    std::cout << "-------------------------" << '\n';
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Running time: " << result1.runTime << " ms | " << result2.runTime << " ms\n";
    std::cout << "Comparisons: " << result1.comparisons << " | " << result2.comparisons << '\n';
    std::cout << '\n';
}

void write_console_5(const Config &config, const SortResult &result1, const SortResult &result2)
{
    std::cout << "COMPARE MODE\n";
    std::cout << "Algorithm: " << config.algorithm1 << " | " << config.algorithm2 << '\n';
    std::cout << "Input size: " << config.inputSize << '\n';
    std::cout << "Input order: " << config.inputOrder << '\n';
    std::cout << "-------------------------" << '\n';
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Running time: " << result1.runTime << " ms | " << result2.runTime << " ms\n";
    std::cout << "Comparisons: " << result1.comparisons << " | " << result2.comparisons << '\n';
    std::cout << '\n';
}