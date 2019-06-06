#include <iostream> 
#include <vector>

using namespace std;


enum OperatingSystem { iOS, Android, Unix, Linux, Windows };

void bell(int number)
{
	cout << number << endl;
}

void bar(int number)
{
	bell(number + 2);
}

void foo(int number)
{
	bar(number * 10);
}

bool canRunCandyCrush(OperatingSystem os)
{
	return os == iOS || os == Android || os == Windows;
	
}

int main()
{
	vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 };
	
	for (int& number : primes)
	{
		foo(number);
	}

	system("pause");
	return 0;
}