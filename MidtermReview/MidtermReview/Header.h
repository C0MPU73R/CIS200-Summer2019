#pragma once

#include <string>

using namespace std;

class Employee
{
private:
	int idNumber;
	string name;
	double annualSalary;
public:
	Employee(int idNumber, string name, double annualSalary)
	{
		this->idNumber = idNumber;
		setName(name);
		setAnnualSalary(annualSalary);
	}

	void setName(string name)
	{
		this->name = name;
	}

	void setAnnualSalary(double annualSalary)
	{
		if (annualSalary <= 0)
		{
			throw invalid_argument("Salary can't be 0 or less");
		}
		this->annualSalary = annualSalary;
	}

	int getIDNumber()
	{
		return idNumber;
	}

	string getName()
	{
		return name;
	}

	double getAnnualSalary()
	{
		return annualSalary;
	}

	double getMonthlySalary()
	{
		return annualSalary / 12;
	}

	double getWeeklySalary()
	{
		return annualSalary / 52;
	}
};