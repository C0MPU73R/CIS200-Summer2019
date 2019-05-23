#include <iostream>
#include "Polygon.h"
#include "Rectangle.h"

using namespace std;

int main()
{
	// can't do this on the stack
	// Polygon anotherPolygon(4, 6);

	Polygon *somePolygon = new Rectangle(4, 6);
	cout << "Area of a 4x6 rectangle: " << somePolygon->getArea() << endl;
	
	system("pause");
	return 0;
}