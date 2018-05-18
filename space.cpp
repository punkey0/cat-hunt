/*********************************************************************
** Program name: Final Project
** Author: Kasey Kagawa
** Date: 11/29/2017
** Description: Space Class function definition file
*********************************************************************/

#include "space.hpp"

Space::Space()
{
	up = nullptr; //defines up as nullptr by default
	down = nullptr; //defines down as nullptr by default
	item = new Item; //creates item for storage
	left = nullptr; //defines left as null by default
	right = nullptr; //defines right as nullptr by default
}