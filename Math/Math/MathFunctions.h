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