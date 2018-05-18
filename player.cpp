/*********************************************************************
** Program name: Final Project
** Author: Kasey Kagawa
** Date: 11/29/2017
** Description: Cat Class function definition file
*********************************************************************/

#include "player.hpp"

Player::Player()
{
	name = "Player";
	symbol = 'P';
	inventory = '.';
}

char Player::checkInv()
{
	return inventory;
}

void Player::changeInv(char c)
{
	inventory = c;
}