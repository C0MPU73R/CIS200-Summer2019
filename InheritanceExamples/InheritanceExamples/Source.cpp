#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main()
{
	SomeBaseClass baseClass;
	SomeDerviedClass derivedClass;

	SomeBaseClass *toSomeClass = &derivedClass;
	cout << toSomeClass->status() << endl;

	cout << baseClass.status() << endl;
	cout << derivedClass.status() << endl;

	system("pause");
	return 0;
}