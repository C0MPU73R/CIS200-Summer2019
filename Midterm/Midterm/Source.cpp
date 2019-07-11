#include <iostream>

using namespace std;

int main()
{
	char *letters = new char[26];
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int index = 0; index < alphabet.size(); index++)
	{
		letters[index] = alphabet.at(index);
	}

	for (int index = 0; index < 26; index++)
	{
		cout << letters[index] << endl;
	}

	delete[] letters;

	system("pause");
	return 0;
}