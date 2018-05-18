/*********************************************************************
** Program name: Final Project
** Author: Kasey Kagawa
** Date: 11/29/2017
** Description: Item function definition header file
*********************************************************************/

#include "item.hpp"
#include <iostream>

Item::Item()
{
	name = "NONAME";
	symbol = ' ';
	inventory = '.';
}

void Item::setName(std::string n)
{
	name = n;
}

void Item::setSymbol(char c)
{
	symbol = c;
}

char Item::printSymbol()
{
	return symbol;
}

char Item::checkInv()
{
	return inventory;
}

void Item::changeInv(char c)
{
	inventory = c;
}