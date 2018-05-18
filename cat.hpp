/*********************************************************************
** Program name: Final Project
** Author: Kasey Kagawa
** Date: 11/29/2017
** Description: Cat Class header file
*********************************************************************/

#include "space.hpp"
#include "item.hpp"
#ifndef CAT_HPP
#define CAT_HPP

class Cat : public Item
{
	private:
		Space *turn1;
		Space *turn2;
		Space *turn3;
		Space *turn4;
	public:
		Cat();
		void catTrail(Space *s);
};

#endif