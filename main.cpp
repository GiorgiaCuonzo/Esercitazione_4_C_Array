#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"
using namespace std;


int main()
{
    string fileName = "data.csv";
    double S = 0;
    unsigned int n = 0;
    double* w = nullptr;
    double* r = nullptr;
    
    FileReader(fileName,S,n,w,r);
    
    double V = 0;
    PrintResult(S,n,w,r,V);

    string outputFile = "./result.txt";
    if(!ExportResult(outputFile,S,n,w,r,V))
    {
        cerr << "Something went wrong with export" << endl;
    }
    else
    {
        cout << "Export succeded" << endl;
    }

    return 0;
}
