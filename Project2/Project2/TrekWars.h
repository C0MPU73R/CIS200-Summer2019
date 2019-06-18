#pragma once

#include <string>
#include <cmath>

using namespace std;

enum Alignment { us, them, chaotic };

class Ship
{
private:
	string name;
	Alignment align;
	int xLoc;
	int yLoc;
	int range;
	int currentHealth;
	int attackPower;
	int maxHealth;
	int xMove;
	int yMove;

	virtual string getType()
	{
		return "Ship";
	}

protected:
	bool isTargetWithinRange(Ship *target)
	{
		return hypot(xLoc - target->getX(), yLoc - target->getY()) <= range;
	}

	bool shouldShootTarget(Ship *target)
	{
		return align == chaotic || align != target->getAlign();
	}

public:
	Ship(string name, int x, int y, Alignment align, int maxHealth, int range, int attackPower, int xMove, int yMove)
	{
		this->name = name;
		this->xLoc = x;
		this->yLoc = y;
		this->align = align;
		this->maxHealth = maxHealth;
		this->currentHealth = maxHealth;
		this->range = range;
		this->attackPower = attackPower;
		this->xMove = xMove;
		this->yMove = yMove;
	}

	virtual void attack(Ship *target)
	{
		if (shouldShootTarget(target) && isTargetWithinRange(target))
		{
			target->assessDamage(attackPower);
		}
	}

	int getX()
	{
		return xLoc;
	}

	int getY()
	{
		return yLoc;
	}

	Alignment getAlign()
	{
		return align;
	}

	virtual string status()
	{
		return "Name: " + name + "\n"
			+ "Type: " + this->getType() + "\n"
			+ "Health: " + to_string(getCurrentHealth()) + "\n"
			+ "Location: (" + to_string(getX()) + ", " + to_string(getY()) + ")" + "\n";
	}

	virtual void move()
	{
		if (currentHealth == 0)
		{
			throw invalid_argument("Cannot move a ship at 0 health");
		}
		assessDamage(-1);
		yLoc += yMove;
		xLoc += xMove;
	}

	void changeAlign()
	{
		if (align == us)
		{
			align = them;
		}
		else if (align == them)
		{
			align = us;
		}
	}

	void assessDamage(int amount)
	{
		currentHealth -= amount;
		if (currentHealth < 0)
		{
			currentHealth = 0;
		}
		if (currentHealth > maxHealth)
		{
			currentHealth = maxHealth;
		}
	}

	int getCurrentHealth()
	{
		return currentHealth;
	}

};

class Battleship : public Ship
{
private:
	int torpedos;

	string getType()
	{
		return "Battleship";
	}

public:
	Battleship(string name, int xLoc, int yLoc, Alignment align) : Ship(name, xLoc, yLoc, align, 100, 10, 10, -1, -1)
	{
		torpedos = 10;
	}

	void attack(Ship *target)
	{
		Ship::attack(target);
		if (torpedos > 0)
		{
			if (shouldShootTarget(target))
			{
				torpedos--;
				if (isTargetWithinRange(target))
				{
					target->assessDamage(10);
				}
			}
		}
	}

	string status()
	{
		return Ship::status() + "Torpedos: " + to_string(torpedos) + "\n";
	}
};

class Cruiser : public Ship
{

private:
	string getType()
	{
		return "Cruiser";
	}

public:
	Cruiser(string name, int xLoc, int yLoc, Alignment align) : Ship(name, xLoc, yLoc, align, 50, 50, 5, 1, 2)
	{

	}
};

class Corvette : public Ship
{

private:
	string getType()
	{
		return "Corvette";
	}

public:
	Corvette(string name, int xLoc, int yLoc, Alignment align) : Ship(name, xLoc, yLoc, align, 20, 25, 0, 5, 5)
	{

	}

	void attack(Ship *target)
	{
		if (isTargetWithinRange(target) && shouldShootTarget(target))
		{
			target->changeAlign();
		}
	}
};

class Repair : public Cruiser
{
private:
	string getType()
	{
		return "Repair";
	}

public:
	Repair(string name, int xLoc, int yLoc, Alignment align) : Cruiser(name, xLoc, yLoc, align)
	{

	}

	void attack(Ship *target)
	{
		if (isTargetWithinRange(target) && this->getAlign() != chaotic && this->getAlign() == target->getAlign() && target->getCurrentHealth() != 0)
		{
			target->assessDamage(-10000000);
		}
	}
};