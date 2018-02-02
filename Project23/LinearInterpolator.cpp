#include "LinearInterpolator.h"
#include <iostream>
#include <map>

using namespace std;

LinearInterporlator::LinearInterporlator()
{

}
void LinearInterporlator::add(double x1 , double x2)
{
	map<double, double>::iterator it = Point.find(x1);
	if (it != Point.end())
		it->second = x2;
	else
	Point.insert(pair < double, double >(x1, x2));
	
}

double LinearInterporlator::value(double x1) 
{
	

	for (map<double, double >::iterator it = Point.begin(); it != Point.end(); ++it) // starts at the begin and will end at the last point.
	{ 
		it = Point.end();
		it--;
		if (x1 > it->first)
		{
			return it->second;
		}

		it = Point.begin();
		if (x1 < it->first)
		{
			return it->second;
		}
		
		if (it->first < x1)
			continue;
		else { 
			double RightX = it->first;
			double RightY = it->second;
			it--;
			double LeftX = it->first;
			double LeftY = it->second;

			double Grad = (RightX - LeftX) / (RightY - LeftY);

			return (Grad * (x1 - LeftX) +LeftY );
				
		}
	
	}

}




