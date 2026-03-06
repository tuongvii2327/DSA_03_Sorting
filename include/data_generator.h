#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}

void GenerateRandomData(std::vector <int> &v, int n);

void GenerateSortedData(std::vector <int> &v, int n);

void GenerateReverseData(std::vector <int> &v, int n);

void GenerateNearlySortedData(std::vector <int> &v, int n);

/*
 * 0 - GenerateRandomData (-rand) 
 * 1 - GenerateSortedData (-sorted) 
 * 2 - GenerateReverseData (-rev) 
 * 3 - GenerateNearlySortedData (-nsorted) 
 */
void GenerateData(std::vector <int> &v, int n, std::string dataType);

#endif