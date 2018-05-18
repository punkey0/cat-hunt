/*********************************************************************
** Program name: Final Project
** Author: Kasey Kagawa
** Date: 11/29/2017
** Description: Main function definition file
*********************************************************************/

#include "floor.hpp"
#include <iostream>

int main()
{
	Floor test;
	bool winState = false;
	bool loseState = false;
	int counter = 25;
	
	std::cout << "Oh no! You lost your family's beloved cat in the basement and everyone's asleep!" << std::endl;
	std::cout << "You'll have to go down there and get it back - but be quick, your mother's about to wake up!" << std::endl;
	
	test.makeFloor();
	test.printFloor();
	test.newTurn();
	
	while (winState == false && loseState == false)
	{
		std::cout << "You only have " << counter << " more minutes to find the cat!" << std::endl;
		test.senseNear();
		test.printFloor();
		test.newTurn();
		winState = test.getWin();
		loseState = test.getLose();
		counter--;
		if (counter == 0)
		{
			loseState = true;
		}
	}
	
	
	if (counter = 0)
	{
		std::cout << "Your mother appears at the top of the stairs!" << std::endl;
		std::cout << "\"What are you doing down there?\" she asks. \"Where's Mittens?\" Busted!" << std::endl;
	}
	
	return 0;
}