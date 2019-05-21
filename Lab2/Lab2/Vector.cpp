#include "Vector.h"

Vector::Vector(int size)
{
	this->size = size;
	entries = new int[size];
	for (int index = 0; index < size; index++)
	{
		entries[index] = 0;
	}
}

Vector::Vector(const Vector & rhs)
{
	size = rhs.size;
	entries = new int[size];
	for (int index = 0; index < size; index++)
	{
		entries[index] = rhs.entries[index];
	}
}

Vector Vector::operator=(const Vector & rhs)
{
	delete entries;
	this->size = rhs.size;
	entries = new int[size];
	for (int index = 0; index < size; index++)
	{
		entries[index] = rhs.entries[index];
	}
	return *this;
}

Vector::~Vector()
{
	delete entries;
}

int & Vector::operator[](int index)
{
	return entries[index];
}

int Vector::getSize()
{
	return size;
}
