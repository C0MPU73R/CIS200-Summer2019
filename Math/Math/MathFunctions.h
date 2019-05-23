#pragma once
class Circle
{
private:
	double radius;
	const double PI = 3.14159;
public:
	Circle(double radius);
	double getArea();
	double getCircumference();
	double getRadius();
};

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
