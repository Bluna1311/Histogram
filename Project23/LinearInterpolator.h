#pragma once
#include <map>

using namespace std;

class LinearInterporlator {

public :

	void add(double x1 , double x2);
	LinearInterporlator();
	double value(double x1);
private :

	map < double, double> Point;


};
