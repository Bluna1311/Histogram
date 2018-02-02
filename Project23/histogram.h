#pragma once

#include <vector>
using namespace std;

class  histogram
{
public:
	histogram(double Xmin, double Xmax, int BinNumber);
	void add(double X);
	void GetResult(vector<double>& binBoundaries, vector<long>& Data);
	void writeResultsToStream(ostream &os, vector<double>  binBoundaries, vector<long>  Data);
	vector<double>  binBoundaries;
private:

	double M_XMIN;
	double M_XMax;
	int  M_BinNumber;
	double M_BucketSize;
	int M_Over;
	int M_Under;
	vector <long> H1;
	
};