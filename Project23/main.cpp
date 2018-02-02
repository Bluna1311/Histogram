#include <vector>
#include <string>
#include <iostream>
#include "histogram.h"
#include <math.h>
#include <fstream>
using namespace std;


int main() {
	

	histogram H1(-5, 5, 10);
	vector<double>  binBoundaries;
	vector<long> Data;
	H1.add(2);
	H1.add(2);
	H1.add(6);
	H1.add(-2);
	H1.add(-4);
	H1.add(-8);
	H1.add(0);
	H1.add(5);
	
	H1.GetResult(binBoundaries ,Data);

	H1.writeResultsToStream(cout, binBoundaries, Data);

	ofstream ofs("histogram.txt");
	H1.writeResultsToStream(ofs, binBoundaries, Data);
	system("pause");
	ofs.close();
	return 0 ;


	






}