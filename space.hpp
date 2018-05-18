/*********************************************************************
** Program name: Final Project
** Author: Kasey Kagawa
** Date: 11/29/2017
** Description: Space Class header file
*********************************************************************/

#include "item.hpp"
#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{	
	public:
		Space *up;
		Space *down;
		Space *left;
		Space *right;
		Item *item;
		Space();
};

#endif