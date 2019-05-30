#pragma once

using namespace std;

class PowerBallTicket
{
private:
	int whiteNumbers[5];
	int redNumber;
public:
	PowerBallTicket();
	PowerBallTicket(int white1, int white2, int white3, int white4, int white5, int red);
	int getWinnings(PowerBallTicket& winningTicket);
	
	// https://github.com/EricCharnesky/CIS200-Summer2019/blob/0ca9bdfa17d0cca595b37d842029bb70305d4891/Pointers/Pointers/Source.cpp
	friend ostream & operator<<(ostream & os, const PowerBallTicket & powerBallTicket );
};

PowerBallTicket::PowerBallTicket()
{
	whiteNumbers[0] = 0;
	whiteNumbers[1] = 0;
	whiteNumbers[2] = 0;
	whiteNumbers[3] = 0;
	whiteNumbers[4] = 0;

	for (int whiteNumberIndex = 0; whiteNumberIndex < 5; whiteNumberIndex++)
	{
		int randomNumber = rand() % 69 + 1;
		while (randomNumber == whiteNumbers[0] ||
			randomNumber == whiteNumbers[1] ||
			randomNumber == whiteNumbers[2] ||
			randomNumber == whiteNumbers[3] ||
			randomNumber == whiteNumbers[4])
		{
			randomNumber = rand() % 69 + 1;
		}
		whiteNumbers[whiteNumberIndex] = randomNumber;
	}

	redNumber = rand() % 26 + 1;
}

PowerBallTicket::PowerBallTicket(int white1, int white2, int white3, int white4, int white5, int red)
{
	whiteNumbers[0] = white1;
	whiteNumbers[1] = white2;
	whiteNumbers[2] = white3;
	whiteNumbers[3] = white4;
	whiteNumbers[4] = white5;

	for (int firstNumberIndex = 0; firstNumberIndex < 5; firstNumberIndex++)
	{
		for (int secondNumberIndex = firstNumberIndex + 1; secondNumberIndex < 5; secondNumberIndex++)
		{
			if (whiteNumbers[firstNumberIndex] == whiteNumbers[secondNumberIndex])
			{
				throw invalid_argument("White numbers cannot be duplicated");
			}
		}
	}
	redNumber = red;
}

int PowerBallTicket::getWinnings(PowerBallTicket & winningTicket)
{
	int whiteMatches = 0;

	bool redMatches = redNumber == winningTicket.redNumber;

	for (int myWhiteNumberIndex = 0; myWhiteNumberIndex < 5; myWhiteNumberIndex++)
	{
		for (int winningTicketWhiteNumberIndex = 0; winningTicketWhiteNumberIndex < 5; winningTicketWhiteNumberIndex++)
		{
			if (whiteNumbers[myWhiteNumberIndex] == winningTicket.whiteNumbers[winningTicketWhiteNumberIndex])
			{
				whiteMatches++;
			}
		}
	}

	if (whiteMatches == 5 && redMatches)
	{
		return 2000000000;
	}
	else if (whiteMatches == 5)
	{
		return 1000000;
	}
	else if (whiteMatches == 4 && redMatches)
	{
		return 50000;
	}
	else if (whiteMatches == 4 || (whiteMatches == 3 && redMatches))
	{
		return 100;
	}
	else if (whiteMatches == 3 || (whiteMatches == 2 && redMatches))
	{
		return 7;
	}
	else if (redMatches)
	{
		return 4;
	}
	else
	{
		return 0;
	}
}

ostream & operator<<(ostream & os, const PowerBallTicket & powerBallTicket)
{
	os << powerBallTicket.whiteNumbers[0] << " " <<
		powerBallTicket.whiteNumbers[1] << " " <<
		powerBallTicket.whiteNumbers[2] << " " <<
		powerBallTicket.whiteNumbers[3] << " " <<
		powerBallTicket.whiteNumbers[4] << " " <<
		"PowerBall: " << powerBallTicket.redNumber;
	return os;
}
