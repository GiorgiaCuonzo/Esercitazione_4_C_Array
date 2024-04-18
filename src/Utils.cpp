#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"
using namespace std;

bool FileReader(const string &fileName, double &S, unsigned int &n, double* &w, double* &r)
{
    ifstream file(fileName);
    if(file.fail())
    {
        cerr << "File open failed" << endl;
        return false;
    }

    string line;

    getline(file,line);
    istringstream ss1(line);
    char c1,c2;
    ss1 >> c1 >> c2 >> S;

    getline(file,line);
    istringstream ss2(line);
    ss2 >> c1 >> c2 >> n;

    getline(file,line);

    w = new double[n];
    r = new double[n];
    for(int i=0; i<n; i++)
    {
        getline(file,line);
        istringstream ss(line);
        ss >> w[i] >> c1 >> r[i];
    }

    file.close();
    return true;
}


double RateOfReturn(double &S, unsigned int &n, double* &w, double* &r, double &V)
{
    double rateR;
    for(int i=0; i<n; i++)
    {
        rateR += w[i]*r[i];
    }

    V = (1+rateR)*S;
    return rateR;
}


void PrintResult(double &S, unsigned int &n, double* &w, double* &r, double &V)
{
    cout << "S = " << fixed << setprecision(2) << S;
    cout << ", n = " << n << endl;

    cout << "w = [ ";
    for(int i=0; i<n; i++) {
        cout << w[i] << " ";
    }
    cout << "]" << endl;

    cout << "r = [ ";
    for(int i=0; i<n; i++) {
        cout << r[i] << " ";
    }
    cout << "]" << endl;

    double rateR = RateOfReturn(S,n,w,r,V);
    cout << "Rate of return of the portfolio: " << setprecision(4) << rateR << endl;
    cout << "V: " <<  fixed << setprecision(2) << V << endl;
}


bool ExportResult(const string &outputFileName, double &S, unsigned int &n, double* &w, double* &r, double &V)
{
    ofstream fileOut(outputFileName);
    if(fileOut.fail())
    {
        cerr << "Output file open failed" << endl;
        return false;
    }

    fileOut << "S = " << fixed << setprecision(2) << S;
    fileOut << ", n = " << n << endl;

    fileOut << "w = [ ";
    for(int i=0; i<n; i++) {
        fileOut << w[i] << " ";
    }
    fileOut << "]" << endl;

    fileOut << "r = [ ";
    for(int i=0; i<n; i++) {
        fileOut << r[i] << " ";
    }
    fileOut << "]" << endl;

    double rateR = RateOfReturn(S,n,w,r,V);
    fileOut << "Rate of return of the portfolio: " << setprecision(4) << rateR << endl;
    fileOut << "V: " << fixed << setprecision(2) << V << endl;

    fileOut.close();
    return true;
}
