#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Item
{
private:
	string name;
	double price;
public:
	Item(string name, double price)
	{
		this->name = name;
		setPrice(price);
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
	}

	//https://github.com/EricCharnesky/CIS200-Summer2019/blob/master/OODesign/OODesign/Tree.cpp#L43
	friend ostream & operator<<(ostream & os, const Item & item)
	{
		os << "Name: " + item.name;
		os << " Price: " + to_string(item.price);

		return os;
	}
};


int main()
{
	

	bool valid = false;

	while (!valid)
	{
		cout << "Please enter a number:" << endl;

		string input;
		cin >> input;
		
		try
		{
			int number;
			number = stoi(input);
			cout << number * 10;
			valid = true;
		}
		catch (invalid_argument& excpt)
		{
			cout << excpt.what() << endl;
		}
	}



	cout << "Enter the item name: ";
	string name;
	cin >> name;

	bool validItem = false;

	while (!validItem)
	{
		try
		{
			cout << "Enter the item price: ";
			double price;
			cin >> price;

			Item someItem(name, price);
			validItem = true;
			cout << someItem << endl;
		}
		catch (invalid_argument& e)
		{
			cout << e.what() << endl;
		}


	}
	
	system("pause");
	return(0);
}