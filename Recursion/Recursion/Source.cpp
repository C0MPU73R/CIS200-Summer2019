#include <iostream>
#include <vector>

using namespace std;

int _fib(int nthTerm, int previousTerm, int currentTerm, int currentNth)
{
	if (nthTerm == currentNth)
	{
		return previousTerm + currentTerm;
	}
	return _fib(nthTerm, currentTerm, previousTerm + currentTerm, ++currentNth);
}

int fib(int nthTerm)
{
	if (nthTerm <= 0)
	{
		throw invalid_argument("nthTerm can not be 0 or less");
	}
	if (nthTerm == 1 || nthTerm == 2)
	{
		return 1;
	}
	return _fib(nthTerm, 1, 1, 3);
}

int fibIteratively(int nthTerm)
{
	if (nthTerm <= 0)
	{
		throw invalid_argument("nthTerm can not be 0 or less");
	}
	if (nthTerm == 1 || nthTerm == 2)
	{
		return 1;
	}
	int previousTerm = 1;
	int currentTerm = 1;
	int currentNth = 3;
	while (currentNth != nthTerm)
	{
		int temp = previousTerm;
		previousTerm = currentTerm;
		currentTerm += temp;
		currentNth++;
	}
	return currentTerm + previousTerm;

}


class NQueens
{
private:
	static const char QUEEN = 'Q';
	static const char SPACE = ' ';

	int numberOfQueensOnBoard;
	vector<vector<char>> board;
	bool solved;
	int size;
	int numberOfSolutions;

	bool canPutQueenOnRow(int row)
	{
		for (int column = 0; column < numberOfQueensOnBoard; column++)
		{
			if (board[row][column] == QUEEN)
			{
				return false;
			}
		}
		return true;
	}
	bool canPutQueenOnColumn(int column)
	{
		// we are only ever putting queens 1 column at a time in our Solve method
		/*for (int row = 0; row < 8; row++)
		{
			if (board[row][column] == QUEEN)
			{
				return false;
			}
		}*/
		return true;
	}

	bool isDiagonalUpSafe(int row, int column)
	{
		// row-- column-- each time
		// row >= 0, column >= 0
		while (row >= 0 && column >= 0)
		{
			if (board[row][column] == QUEEN)
			{
				return false;
			}
			row--;
			column--;
		}
		return true;
	}

	bool isDiagonalDownSafe(int row, int column)
	{
		// row++ column-- each time
		// row < 8, column >= 0
		while (row < size && column >= 0)
		{
			if (board[row][column] == QUEEN)
			{
				return false;
			}
			row++;
			column--;
		}
		return true;
	}

	bool canPutQueenOnDiagonal(int row, int column)
	{
		return isDiagonalUpSafe(row, column) && isDiagonalDownSafe(row, column);
	}

	bool canPutQueen(int row, int column)
	{
		return canPutQueenOnRow(row) && canPutQueenOnColumn(column) && canPutQueenOnDiagonal(row, column);
	}



public:
	NQueens(int size = 8)
	{
		this->size = size;
		numberOfSolutions = 0;
		numberOfQueensOnBoard = 0;
		solved = false;
		for (int row = 0; row < size; row++)
		{
			board.push_back(vector<char>(size));
			for (int column = 0; column < size; column++)
			{
				board[row][column] = SPACE;
			}
		}
	}

	void print()
	{
		for (int dash = 0; dash < size; dash++)
		{
			cout << "--";
		}
		cout << "-" << endl;
		for (int row = 0; row < size; row++)
		{
			for (int column = 0; column < size; column++)
			{
				cout << "|";
				cout << board[row][column];
			}
			cout << "|" << endl;
			for (int dash = 0; dash < size; dash++)
			{
				cout << "--";
			}
			cout << "-" << endl;
		}
	}

	void solve()
	{
		if (numberOfQueensOnBoard == size)
		{
			//solved = true;
			numberOfSolutions++;
			cout << "Solution #" << numberOfSolutions << endl;
			print();
			cout << endl << endl;
		}

		if (!solved)
		{
			for (int row = 0; row < size; row++)
			{
				if (canPutQueen(row, numberOfQueensOnBoard))
				{
					board[row][numberOfQueensOnBoard] = QUEEN;
					numberOfQueensOnBoard++;
					solve();
					if (!solved)
					{
						numberOfQueensOnBoard--;
						board[row][numberOfQueensOnBoard] = SPACE;
					}
				}
			}
		}
	}

};


int main()
{
	NQueens nQueens(8);
	nQueens.solve();
	/*for (int number = 1; number < 50; number++)
	{
		cout << fib(number) << endl;
	}*/
	system("pause");
	return 0;
}