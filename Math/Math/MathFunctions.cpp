#include "MathFunctions.h"

Circle::Circle(double radius)
{
	this->radius = radius;
}

double Circle::getArea()
{
	return radius * radius * PI;
}

double Circle::getCircumference()
{
	return radius * 2 * PI;
}

double Circle::getRadius()
{
	return radius;
}


