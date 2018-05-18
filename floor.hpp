/*********************************************************************
** Program name: Final Project
** Author: Kasey Kagawa
** Date: 11/29/2017
** Description: Floor Class header file
*********************************************************************/

#include "space.hpp"
#ifndef FLOOR_HPP
#define FLOOR_HPP

class Floor : public Space
{
	private:
		Space *top0;
		Space *top1;
		Space *top2;
		Space *top3;
		Space *bottom0;
		Space *bottom1;
		Space *bottom2;
		Space *bottom3;
		Space *left0;
		Space *left1;
		Space *left2;
		Space *left3;
		Space *right0;
		Space *right1;
		Space *right2;
		Space *right3;
		Space *playerP;
		Space *catP;
		bool gameWin;
		bool gameLose;
		bool getCat;
	public:
		Floor();
		~Floor();
		void makeFloor(); //creates game space
		void printFloor(); //prints game space
		void newTurn(); //moves characters
		void senseNear(); //prints out what items are nearby
		int makeHash(int x, int y); //hashes item placement to guarantee uniqueness
		bool getWin(); //retrieves win state
		bool getLose(); //retrieves lose state
};

#endif