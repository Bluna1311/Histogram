#include <vector>
#include <string>
#include <iostream>
#include "histogram.h"
#include <math.h>
#include <fstream>
using namespace std;


histogram::histogram(double Xmin, double Xmax, int BinNumber) {
	// ill del, any un needed variables
	M_Over = 0;
	M_Under = 0;
	M_XMIN = Xmin;
	M_XMax = Xmax;
	M_BinNumber = BinNumber + 2;
	M_BucketSize = ((Xmax - Xmin)/ BinNumber);
	H1.resize(M_BinNumber);
	
}

void histogram::add(double X)
{

	if (X < M_XMIN)
		H1[0] ++;

	// loop method
	/*for (vector<double>::iterator it = H1.begin(); it != H1.end(); it++) {
		for (int i = 1; i < H1.size(); i++)
			if (X > (M_XMIN + (i-1)*M_BucketSize) && X <= M_XMIN + (i*M_BucketSize))
				H1[i]++;
	*/
	// no loop method 

	if (X > M_XMIN && X <= M_XMax)
	{
		int DataPoint = int((X - M_XMIN) / M_BucketSize);
		H1[DataPoint] ++;

	}


	if (X > M_XMax)
	{
		 int i = int (H1.size() - 1);
		H1[i] ++;
	}
		
	return;

}


void histogram::GetResult(vector<double> & binBoundaries, vector<long> &Data) // why the & on H!
{
	binBoundaries.resize(H1.size());
	Data.resize(H1.size());
	for (unsigned int i = 0 ; i < H1.size(); i++)
	{

		binBoundaries[i] = M_XMIN + (i * M_BucketSize);
	    Data[i] = H1[i];

	}



	return; 
}

void histogram::writeResultsToStream(ostream &os, vector<double>  binBoundaries , vector<long>  Data)
{

	for (unsigned int i = 0; i < H1.size(); i++)
		os << "left boundry " << binBoundaries[i] << " : " << Data[i] << endl;





/*	int Choice;
	cout << "option 1 : console " << endl;
	cout << "option 2 : File"  << endl;
	cin >> Choice;
	if (Choice == 1)
	{
		for (unsigned int i = 0; i < H1.size(); i++)
		{
			cout << "right boundry limit " << binBoundaries[i] << ":" << H1[i] << endl;

		}
	}
	if (Choice == 2)
	{
		ofstream FileToWrite("Histogram.txt");
		if (!FileToWrite)
		{
			cout << "error writing to file" << endl;
			system("pause");
		}
		for (unsigned int i = 0; i < H1.size(); i++)
			FileToWrite << binBoundaries[i] << " " << H1[i] << endl;
	}
	return;

	*/







}