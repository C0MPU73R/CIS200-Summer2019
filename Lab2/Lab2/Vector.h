#pragma once

class Vector
{
public:
	Vector(int size = 0);  // makes Size = s, 
		//allocates s space, 
		// makes all entries 0
	
	Vector(const Vector & rhs);  // copy constructor
		// makes self a deep copy of rhs
	
	Vector operator = (const Vector & rhs);// makes self a deep copy of rhs

	~Vector();     // default destructor

	int & operator[](int index); // if 0 <=pos<size
							  // returns entries[index]

	int getSize();// returns the # of entries.

private:
	int size;            //store the # of elements used  
	int *entries;
};

