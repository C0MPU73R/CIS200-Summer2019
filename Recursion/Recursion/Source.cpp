#include <iostream>

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


class EightQueens
{
private:
	static const char QUEEN = 'Q';
	static const char SPACE = ' ';
	
	int numberOfQueensOnBoard;
	char board[8][8];
	bool solved;
	
	bool canPutQueenOnRow(int row)
	{

	}
	bool canPutQueenOnColumn(int column)
	{

	}
	bool canPutQueenOnDiagonal(int row, int column)
	{

	}
	
	bool canPutQueen(int row, int column)
	{
		return canPutQueenOnRow(row) && canPutQueenOnColumn(column) && canPutQueenOnDiagonal(row, column);
	}



public:
	EightQueens()
	{
		numberOfQueensOnBoard = 0;
		solved = false;
		for (int row = 0; row < 8; row++)
		{
			for (int column = 0; column < 8; column++)
			{
				board[row][column] = SPACE;
			}
		}
	}

	void print()
	{
		cout << "-----------------" << endl;
		for (int row = 0; row < 8; row++)
		{
			for (int column = 0; column < 8; column++)
			{
				cout << "|";
				cout << board[row][column];
			}
			cout << "|";
			cout << endl << "-----------------" << endl;
		}
	}

	void solve()
	{
		if (numberOfQueensOnBoard == 8)
		{
			solved = true;
			print();
		}

		if (!solved)
		{
			for (int row = 0; row < 8; row++)
			{
				if (canPutQueen(row, numberOfQueensOnBoard) )
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
	EightQueens eightQueens;
	eightQueens.print();
	/*for (int number = 1; number < 50; number++)
	{
		cout << fib(number) << endl;
	}*/
	system("pause");
	return 0;
}