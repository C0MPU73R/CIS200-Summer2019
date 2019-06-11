#pragma once

using namespace std;

enum Suit { Spades, Hearts, Clubs, Diamonds };

class SomeBaseClass
{
private:
	virtual string getSomeString()
	{
		return "Base class string";
	}
public:
	string status()
	{
		return "My status is: " + this->getSomeString();
	}
	Suit getSuit()
	{
		return Spades;
	}
};

class SomeDerviedClass : public SomeBaseClass
{
private:

	string getSomeString()
	{
		return "Dervied class string";
	}

public:
	string status()
	{
		return SomeBaseClass::status() + " derived class something";
	}
};