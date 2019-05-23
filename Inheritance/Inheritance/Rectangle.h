#pragma once

#include "Polygon.h"

class Rectangle : public Polygon
{
private:
	double length;
	double width;
public:
	Rectangle(double length, double width) : Polygon(4)
	{
		this->setSideLength(0, length);
		this->setSideLength(1, width);
		this->setSideLength(2, length);
		this->setSideLength(3, width);
		this->length = length;
		this->width = width;
	}

	double getArea()
	{
		return length * width;
	}

	double getLength()
	{
		return length;
	}
};