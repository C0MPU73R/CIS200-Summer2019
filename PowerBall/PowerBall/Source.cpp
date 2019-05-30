#include <iostream>

#include "PowerBallTicket.h"

using namespace std;

int main()
{
	int totalWon = 0;
	int totalSpent = 0;

	int menuOption = 0;

	while (menuOption != 3)
	{
		PowerBallTicket winningTicket;
		if (menuOption == 1)
		{
			int white1, white2, white3, white4, white5, red;
			cout << "Enter your 6 numbers - 5 white numbers 1-69 and 1 red number 1-26" << endl;
			cin >> white1 >> white2 >> white3 >> white4 >> white5 >> red;
			try
			{
				PowerBallTicket myTicket(white1, white2, white3, white4, white5, red);
				totalSpent += 2;
				totalWon += myTicket.getWinnings(winningTicket);

			}
			catch (invalid_argument &e)
			{
				cout << e.what() << endl;
			}
		}

		if (menuOption == 2)
		{
			int ticketsToBuy = 0;
			cout << "How many tickets do you want to buy?" << endl;
			cin >> ticketsToBuy;

			int displayAllOrJustWinningTickets = 0;
			cout << "Do you want to see all your tickets or just the winning tickets?\n1 - All\n2 - Winning only" << endl;
			cin >> displayAllOrJustWinningTickets;

			for (int ticketToBuy = 0; ticketToBuy < ticketsToBuy; ticketToBuy++)
			{
				PowerBallTicket myTicket;

				int winnings = myTicket.getWinnings(winningTicket);
				totalWon += winnings;

				if (displayAllOrJustWinningTickets == 1 || (displayAllOrJustWinningTickets == 2 && winnings > 0))
				{
					cout << myTicket << endl;
				}
			}
			totalSpent += ticketsToBuy * 2;
		}

		cout << "The winning ticket is: " << winningTicket << endl;

		cout << "Total Spent: $" << totalSpent << " - Total Won: $" << totalWon << " - Net Loss: $" << totalWon - totalSpent << endl;


		cout << "Please pick an option:\n1 - Pick PowerBallTIcket numbers\n2 - Buy random PowerBallTickets\n3 - Quit" << endl;

		cin >> menuOption;
	}

	system("pause");
	return 0;
}