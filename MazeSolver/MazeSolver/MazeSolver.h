#pragma once

#include <vector>
#include <iostream>

using namespace std;

class MazeSolver
{
private:

	const char START = 'S';
	const char END = 'E';
	const char WALL = 'W';
	const char OPEN = 'O';
	const char VISITED = 'V';


	int shortestPath;
	int currentPath;
	vector<vector<char>> maze;

	bool isLocationInMazeAndOpen(int row, int column)
	{
		return 0 <= row && row < maze.size() && 0 <= column
			&& column < maze.at(row).size()
			&& ( maze.at(row).at(column) == OPEN 
				|| maze.at(row).at(column) == END);
	}

	void solve(int row, int column)
	{
		if (maze.at(row).at(column) == END)
		{
			// for debugging
			//print();
			//cout << "Current Path:" << currentPath << endl;

			if (shortestPath == -1 || currentPath < shortestPath)
			{
				shortestPath = currentPath;
			}
		}
		
		else
		{
			currentPath++;
			maze.at(row).at(column) = VISITED;

			// UP
			if (isLocationInMazeAndOpen(row - 1, column))
			{
				solve(row - 1, column);
			}

			// DOWN
			if (isLocationInMazeAndOpen(row + 1, column))
			{
				solve(row + 1, column);
			}

			// LEFT
			if (isLocationInMazeAndOpen(row, column - 1))
			{
				solve(row, column - 1);
			}

			// RIGHT
			if (isLocationInMazeAndOpen(row, column + 1))
			{
				solve(row, column + 1);
			}

			currentPath--;
			maze.at(row).at(column) = OPEN;
		}
	}

public:
	MazeSolver(vector<vector<char>> maze)
	{
		this->maze = maze;
		shortestPath = -1;
		currentPath = 0;
	}

	int solve()
	{
		for (int row = 0; row < maze.size(); row++)
		{
			for (int column = 0; column < maze.at(row).size(); column++)
			{
				if (maze.at(row).at(column) == START)
				{
					solve(row, column);
				}
			}
		}

		return shortestPath;
	}

	void print()
	{
		for (int row = 0; row < maze.size(); row++)
		{
			for (int column = 0; column < maze.at(row).size(); column++)
			{
				cout << maze[row][column];
			}
			cout << endl;
		}
	}
};