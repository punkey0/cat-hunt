/*********************************************************************
** Program name: Final Project
** Author: Kasey Kagawa
** Date: 11/29/2017
** Description: Exit Class header file
*********************************************************************/

#include "item.hpp"
#include "space.hpp"
#ifndef EXIT_HPP
#define EXIT_HPP

class Exit : public Space
{	
	public:
		Space *up;
		Space *down;
		Space *left;
		Space *right;
		Item *item;
		Exit();
};

#endif