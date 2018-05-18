/*********************************************************************
** Program name: Final Project
** Author: Kasey Kagawa
** Date: 11/29/2017
** Description: Item Class header file
*********************************************************************/

#include <string>
#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
	protected:
		std::string name;
		char symbol;
		char inventory;
	public:
		Item();
		void setName(std::string n);
		void setSymbol(char c);
		char printSymbol();
		virtual char checkInv();
		virtual void changeInv(char c);
};

#endif