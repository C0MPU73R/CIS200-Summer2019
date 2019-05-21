#pragma once

class PowerBallTicket
{
private:
	int whiteNumbers[5];
	int redNumber;
public:
	PowerBallTicket();
	PowerBallTicket(int white1, int white2, int white3, int white4, int white5, int red);
	int getWinnings(PowerBallTicket& winningTicket);
};