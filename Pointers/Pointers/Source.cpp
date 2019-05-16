#include <iostream>
#include <string>

using namespace std;

class Item
{
private:
	string name;
	double price;
	double* totalPriceWithTax;
public:
	Item(string name, double price)
	{
		this->name = name;
		totalPriceWithTax = new double;
		setPrice(price);
	}

	~Item()
	{
		delete totalPriceWithTax;
	}

	Item(const Item& item)
	{
		name = item.name;
		price = item.price;
		delete totalPriceWithTax;
		totalPriceWithTax = new double((*item.totalPriceWithTax));
		// same as above;
		//*totalPriceWithTax = *item.totalPriceWithTax;
	}

	Item& operator=(const Item& item)
	{
		name = item.name;
		price = item.price;
		delete totalPriceWithTax;
		totalPriceWithTax = new double;
		*totalPriceWithTax = *item.totalPriceWithTax;
		return *this;
	}

	string getName()
	{
		return name;
	}

	double getPrice()
	{
		return price;
	}

	void setPrice(double price)
	{
		if (price > 100)
		{
			throw invalid_argument("Items can't cost more than $100");
		}
		else if (price <= 0)
		{
			throw invalid_argument("Items can't cost $0 or less");
		}
		this->price = price;
		
		(*totalPriceWithTax) = (price * 1.06);
	}

	double getTotalPriceWithTax()
	{
		return *totalPriceWithTax;
	}

	//https://github.com/EricCharnesky/CIS200-Summer2019/blob/master/OODesign/OODesign/Tree.cpp#L43
	friend ostream & operator<<(ostream & os, const Item & item)
	{
		os << "Name: " + item.name;
		os << " Price: " + to_string(item.price);

		return os;
	}
};

void printANumber(int number)
{
	//cout << number << endl;
	int* heapNumberTimes100 = new int;

	//cout << "memory address of heaperNumberTimes100: " << heapNumberTimes100 << endl;
	//cout << "value referenced by heaperNumberTimes100: " << (*heapNumberTimes100) << endl;
	//cout << "Assigning a value" << endl;

	(*heapNumberTimes100) = number * 100;

	//cout << "memory address of heaperNumberTimes100: " << heapNumberTimes100 << endl;
	//cout << "value referenced by heaperNumberTimes100: " << (*heapNumberTimes100) << endl;

	int times10 = number * 10;
	//cout << number << " x 10 == " << times10 << endl;

	delete heapNumberTimes100;
}

int main()
{
	int number = 42;

	for (int repeat = 0; repeat < 1000000; repeat++)
	{
		Item *potatoChips = new Item("Potato Chips", 1.99);
		
		// copy constructor
		Item moreChips = *potatoChips;
		// also copy constructor
		Item* something = new Item(moreChips);
		
		// same thing - two ways
		(*potatoChips).getTotalPriceWithTax();
		potatoChips->getTotalPriceWithTax();
		moreChips.setPrice(.99);

		*potatoChips = moreChips;

		if (repeat % 10000 == 0)
		{
			cout << repeat << endl;
		}

		delete potatoChips;
		delete something;
	}
	
	system("pause");
	return 0;
}