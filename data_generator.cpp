#include "data_generator.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <cstdio>
#include <chrono>
#include <random>

void GenerateRandomData(std::vector <int> &v, int n)
{
    std::mt19937_64 rd(std::chrono::steady_clock::now().time_since_epoch().count());

    for (int i = 0; i < n; i++)
    {
        v[i] = rd() % n;
    }
}

void GenerateSortedData(std::vector <int> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = i;
    }
}

void GenerateReverseData(std::vector <int> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = n - 1 - i;
    }
}

void GenerateNearlySortedData(std::vector <int> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = i;
    }
    std::mt19937_64 rd(std::chrono::steady_clock::now().time_since_epoch().count());
;
    for (int i = 0; i < 10; i++)
    {
        int r1 = rd() % n;
        int r2 = rd() % n;
        HoanVi(v[r1], v[r2]); 
    }
}

void GenerateData(std::vector <int> &v, int n, std::string dataType)
{
    v.resize(n);
    if (dataType == "-sorted")
    {
        GenerateSortedData(v, n);
    }
    else if (dataType == "-nsorted")
    {
        GenerateNearlySortedData(v, n);
    }
    else if (dataType == "-rev")
    {
        GenerateReverseData(v, n);
    }
    else if (dataType == "-rand")
    {
        GenerateRandomData(v, n);
    }
    else std::printf("Error: unknown data type!\n");
}