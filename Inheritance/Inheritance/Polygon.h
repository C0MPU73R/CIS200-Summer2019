#pragma once

#include <string>

using namespace std;

class Polygon
{
private:
	int numberOfSides;
	double *sideLengths;
	string name;
public:
	Polygon(int numberOfSides)
	{
		this->numberOfSides = numberOfSides;
		sideLengths = new double[numberOfSides];
		for (int index = 0; index < numberOfSides; index++)
		{
			sideLengths[index] = 0;
		}
	}

	~Polygon()
	{
		delete[] sideLengths;
	}

	Polygon(const Polygon &rhs)
	{
		numberOfSides = rhs.numberOfSides;
		sideLengths = new double[numberOfSides];
		for (int index = 0; index < numberOfSides; index++)
		{
			sideLengths[index] = rhs.sideLengths[index];
		}
	}

	Polygon operator=(const Polygon &rhs)
	{
		delete[] sideLengths;
		numberOfSides = rhs.numberOfSides;
		sideLengths = new double[numberOfSides];
		for (int index = 0; index < numberOfSides; index++)
		{
			sideLengths[index] = rhs.sideLengths[index];
		}
		return *this;
	}

	void setSideLength(int sideNumber, double length)
	{
		if (sideNumber < 0 || sideNumber >= numberOfSides)
		{
			throw invalid_argument("Invalid side number, the first side is index 0");
		}
		sideLengths[sideNumber] = length;
	}

	double getPerimeter()
	{
		double perimeter = 0;
		for (int index = 0; index < numberOfSides; index++)
		{
			perimeter += sideLengths[index];
		}
		return perimeter;
	}

	virtual double getArea()
	{
		throw exception("Get Area is not implemented");
		
	}
};