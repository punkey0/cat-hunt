/*********************************************************************
** Program name: Final Project
** Author: Kasey Kagawa
** Date: 11/29/2017
** Description: Closet Class header file
*********************************************************************/

#include "item.hpp"
#include "space.hpp"
#ifndef CLOSET_HPP
#define CLOSET_HPP

class Closet : public Space
{	
	public:
		Space *up;
		Space *down;
		Space *left;
		Space *right;
		Item *item;
		Closet();
};

#endif