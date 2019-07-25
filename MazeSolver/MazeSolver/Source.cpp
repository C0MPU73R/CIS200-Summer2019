#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "MazeSolver.h"

using namespace std;

int main()
{
	string fileName;
	cout << "Enter maze filename: ";
	cin >> fileName;

	ifstream mazeFile(fileName);

	string line;
	vector<vector<char>> maze;
	if (mazeFile)
	{
		while (!mazeFile.eof())
		{
			getline(mazeFile, line);
			vector<char> characters;

			for (int letter = 0; letter < line.length(); letter++) {

				int x = line[letter];

				characters.push_back(x);
			}

			maze.push_back(characters);
		}
	}

	MazeSolver mazeSolver(maze);

	int actualShortestPath = mazeSolver.solve();
	cout << "Shortest path: " << actualShortestPath << endl;

	system("pause");
	return 0;
}