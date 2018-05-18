/*********************************************************************
** Program name: Final Project
** Author: Kasey Kagawa
** Date: 11/29/2017
** Description: Cat Class function definition file
*********************************************************************/

#include "cat.hpp"

Cat::Cat()
{
	name = "Cat";
	symbol = 'c';
	turn1 = nullptr;
	turn2 = nullptr;
	turn3 = nullptr;
	turn4 = nullptr;
}

void Cat::catTrail(Space *s)
{
	if (turn1 == nullptr)
	{
		turn1 = s;
		return;
	}
	else if (turn2 == nullptr)
	{
		turn2 = turn1;
		turn1 = s;
		return;
	}
	else if (turn3 == nullptr)
	{
		turn3 = turn2;
		turn2 = turn1;
		turn1 = s;
		return;
	}
	turn4 = turn3;
	turn3 = turn2;
	turn2 = turn1;
	turn1 = s;
}