#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Position
{
private:
	int row;
	int column;
	int numberOfNextMoves;
	vector<Position> nextMoves;

	bool isLocationOnTheBoard(int row, int column)
	{
		return row >= 0 && row < 8 && column >= 0 && column < 8;
	}

public:
	Position(int row, int column)
	{
		this->row = row;
		this->column = column;
		numberOfNextMoves = 0;

		// Up Left
		if (isLocationOnTheBoard(row - 2, column - 1))
		{
			numberOfNextMoves++;
		}

		// Up Right
		if (isLocationOnTheBoard(row - 2, column + 1))
		{
			numberOfNextMoves++;
		}

		// Right Up
		if (isLocationOnTheBoard(row - 1, column + 2))
		{
			numberOfNextMoves++;
		}

		// Right Down
		if (isLocationOnTheBoard(row + 1, column + 2))
		{
			numberOfNextMoves++;
		}

		// Down Right
		if (isLocationOnTheBoard(row + 2, column + 1))
		{
			numberOfNextMoves++;
		}

		// Down Left
		if (isLocationOnTheBoard(row + 2, column - 1))
		{
			numberOfNextMoves++;
		}

		// Left Down
		if (isLocationOnTheBoard(row + 1, column - 2))
		{
			numberOfNextMoves++;
		}

		// Left Up
		if (isLocationOnTheBoard(row - 1, column - 2))
		{
			numberOfNextMoves++;
		}
	}



	void generateNextPositions()
	{
		// Up Left
		if (isLocationOnTheBoard(row - 2, column - 1))
		{
			nextMoves.push_back(Position(row - 2, column - 1));
		}

		// Up Right
		if (isLocationOnTheBoard(row - 2, column + 1))
		{
			nextMoves.push_back(Position(row - 2, column + 1));
		}

		// Right Up
		if (isLocationOnTheBoard(row - 1, column + 2))
		{
			nextMoves.push_back(Position(row - 1, column + 2));
		}

		// Right Down
		if (isLocationOnTheBoard(row + 1, column + 2))
		{
			nextMoves.push_back(Position(row + 1, column + 2));
		}

		// Down Right
		if (isLocationOnTheBoard(row + 2, column + 1))
		{
			nextMoves.push_back(Position(row + 2, column + 1));
		}

		// Down Left
		if (isLocationOnTheBoard(row + 2, column - 1))
		{
			nextMoves.push_back(Position(row + 2, column - 1));
		}

		// Left Down
		if (isLocationOnTheBoard(row + 1, column - 2))
		{
			nextMoves.push_back(Position(row + 1, column - 2));
		}

		// Left Up
		if (isLocationOnTheBoard(row - 1, column - 2))
		{
			nextMoves.push_back(Position(row - 1, column - 2));
		}

		sort(nextMoves.begin(), nextMoves.end());
	}

	int getRow()
	{
		return row;
	}

	int getColumn()
	{
		return column;
	}

	vector<Position> getNextMoves()
	{
		return nextMoves;
	}

	friend bool operator<(const Position& l, const Position& r)
	{
		return l.numberOfNextMoves < r.numberOfNextMoves;
	}

};

class KnightsTour
{
private:
	int numberOfMoves;
	vector<vector<int>> board;
	bool solved;
	int size;
	int numberOfSolutions;

	

public:
	KnightsTour(int size = 8)
	{
		this->size = size;
		numberOfSolutions = 0;
		numberOfMoves = 0;
		solved = false;
		for (int row = 0; row < size; row++)
		{
			board.push_back(vector<int>(size));
			for (int column = 0; column < size; column++)
			{
				board[row][column] = 0;
			}
		}
	}

	void print()
	{
		for (int dash = 0; dash < size; dash++)
		{
			cout << "---";
		}
		cout << "-" << endl;
		for (int row = 0; row < size; row++)
		{
			for (int column = 0; column < size; column++)
			{
				cout << "|";
				cout << setw(2) << board[row][column];
			}
			cout << "|" << endl;
			for (int dash = 0; dash < size; dash++)
			{
				cout << "---";
			}
			cout << "-" << endl;
		}
	}

	void solve(int row, int column)
	{
		numberOfMoves++;
		board[row][column] = numberOfMoves;

		if (numberOfMoves == 64)
		{
			print();
			solved = true;
		}

		if (!solved)
		{
			Position position(row, column);
			position.generateNextPositions();
			vector<Position> nextMoves = position.getNextMoves();
			for (Position &nextPosition : nextMoves)
			{
				if (board[nextPosition.getRow()][nextPosition.getColumn()] == 0)
				{
					solve(nextPosition.getRow(), nextPosition.getColumn());
					if (!solved)
					{
						board[nextPosition.getRow()][nextPosition.getColumn()] = 0;
						numberOfMoves--;
					}
				}
			}
		}
	}

};


int main()
{
	KnightsTour knightsTour;
	knightsTour.solve(0,0);


	system("pause");
	return 0;
}