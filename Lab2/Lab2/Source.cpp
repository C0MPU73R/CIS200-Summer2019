#include <iostream>

#include "Vector.h"

using namespace std;

void quadraticEquation(double a, double b, double c, double &root1, double &root2)
{
	if (a == 0)
	{
		throw invalid_argument("a cannot be 0");
	}
	if (b*b - 4 * a * c < 0)
	{
		throw invalid_argument("determinant cannot be negative");
	}
	root1 = (-b + sqrt(b*b - 4 * a*c)) / (2 * a);
	root2 = (-b - sqrt(b*b - 4 * a*c)) / (2 * a);
}

void bell(int a)
{

}

void bar(int a)
{

}

void foo(int a)
{

}


int main() {

	double a, b, c, root1, root2;

	a = 0;
	b = 0;
	c = 0;
	try
	{
		cout << a << "x^2 + " << b << "x + " << c << endl;
		quadraticEquation(a, b, c, root1, root2);
		cout << " - root1: " << root1 << " - root2: " << root2 << endl;
	}
	catch (invalid_argument &e)
	{
		cout << e.what() << endl;
	}

	a = 1;
	b = 2;
	c = 8;
	try
	{
		cout << a << "x^2 + " << b << "x + " << c << endl;
		quadraticEquation(a, b, c, root1, root2);
		cout << " - root1: " << root1 << " - root2: " << root2 << endl;
	}
	catch (invalid_argument &e)
	{
		cout << e.what() << endl;
	}

	a = 1;
	b = -2;
	c = 1;
	try
	{
		cout << a << "x^2 + " << b << "x + " << c << endl;
		quadraticEquation(a, b, c, root1, root2);
		cout << " - root1: " << root1 << " - root2: " << root2 << endl;
	}
	catch (invalid_argument &e)
	{
		cout << e.what() << endl;
	}



/*
	Vector test(10);
	Vector *vecPtr;
	Vector exam(5);
	for (int i = 0; i < test.getSize(); i++) {
		test[i] = i;
	}
	cout << "test initally is : ";
	for (int i = 0; i < test.getSize(); i++) {
		cout << test[i] << " ";
	}
	cout << endl;

	cout << "empty Vector of length 5 is : ";
	for (int i = 0; i < exam.getSize(); i++)
		cout << exam[i] << " ";
	cout << endl;
	exam = test;
	cout << "after exam = test, exam  is : ";
	for (int i = 0; i < exam.getSize(); i++)
		cout << exam[i] << " ";
	cout << endl;
	{
		Vector sqrs(10);
		cout << "The squares are : ";
		for (int i = 0; i < sqrs.getSize(); i++)
			sqrs[i] = i * i;
		vecPtr = &sqrs;
		for (int i = 0; i < sqrs.getSize(); i++)
			cout << i * i << " ";
		cout << endl;
	}
	cout << "trying to print an empty vector: ";
	for (int i = 0; i < vecPtr->getSize(); i++)
		cout << (*vecPtr)[i] << " ";
	cout << endl;
	for (int i = 0; i < test.getSize(); i++)
		test[i] = 10 - i;
	cout << "testing deep copy :\n";
	cout << "test is now : ";
	for (int i = 0; i < test.getSize(); i++)
		cout << test[i] << " ";
	cout << endl;
	cout << "exam is now : ";
	for (int i = 0; i < exam.getSize(); i++)
		cout << exam[i] << " ";
	cout << endl;
*/
	system("pause");

	return 0;
}
