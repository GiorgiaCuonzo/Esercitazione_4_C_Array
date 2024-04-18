#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

/* Function that reads the input file and returns the invested quantity in the double S, the number of assets
in n and the fractions of S and their rtes of return in the arrays w and r*/
bool FileReader(const string &fileName, double &S, unsigned int &n, double* &w, double* &r);

/* Function that computes the rate of return and the final value V of the entire portfolio */
double RateOfReturn(double &S, unsigned int &n, double* &w, double* &r, double &V);

/* Function that prints the data and the computed results on the screen */
void PrintResult(double &S, unsigned int &n, double* &w, double* &r, double &V);

/* Function that prints the data and the computed results in a txt type of output file */
bool ExportResult(const string &outputFileName, double &S, unsigned int &n, double* &w, double* &r, double &V);

#endif
