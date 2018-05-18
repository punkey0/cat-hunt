/*********************************************************************
** Program name: Final Project
** Author: Kasey Kagawa
** Date: 11/29/2017
** Description: Player Class header file
*********************************************************************/

#include "item.hpp"
#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player : public Item
{
	public:
		Player();
		char checkInv();
		void changeInv(char c);
};

#endif