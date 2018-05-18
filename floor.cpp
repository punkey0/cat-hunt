/*********************************************************************
** Program name: Final Project
** Author: Kasey Kagawa
** Date: 11/29/2017
** Description: Floor Class function definition file
*********************************************************************/

#include "floor.hpp"
#include "closet.hpp"
#include "exit.hpp"
#include "item.hpp"
#include "cat.hpp"
#include "chair.hpp"
#include "tv.hpp"
#include "vase.hpp"
#include "player.hpp"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <sstream>

Floor::Floor()
{
	top0 = nullptr;
	top1 = nullptr;
	top2 = nullptr;
	top3 = nullptr;
	bottom0 = nullptr;
	bottom1 = nullptr;
	bottom2 = nullptr;
	bottom3 = nullptr;
	left0 = nullptr;
	left1 = nullptr;
	left2 = nullptr;
	left3 = nullptr;
	right0 = nullptr;
	right1 = nullptr;
	right2 = nullptr;
	right3 = nullptr;
	playerP = nullptr;
	catP = nullptr;
	gameWin = false;
	gameLose = false;
	getCat = false;
}

Floor::~Floor()
{
	Space *del = left0;
	while (del)
	{
		Space *trash = del; //stores the node to be deleted
		del = del->right; //tries to move to the next node
		delete trash; //deletes the stored node
	}
	del = left1;
	while (del)
	{
		Space *trash = del; //stores the node to be deleted
		del = del->right; //tries to move to the next node
		delete trash; //deletes the stored node
	}
	del = left2;
	while (del)
	{
		Space *trash = del; //stores the node to be deleted
		del = del->right; //tries to move to the next node
		delete trash; //deletes the stored node
	}
	del = left3;
	while (del)
	{
		Space *trash = del; //stores the node to be deleted
		del = del->right; //tries to move to the next node
		delete trash; //deletes the stored node
	}	
}

void Floor::makeFloor()
{
	Space *temp0 = nullptr;
	Space *temp1 = nullptr;
	Space *temp2 = nullptr;
	Space *temp3 = nullptr;
	int catX = -1;
	int catY = -1;
	int vaseX = -1;
	int vaseY = -1;
	int tvX = -1;
	int tvY = -1;
	int chairX = -1;
	int chairY = -1;
	int playerX = -1;
	int playerY = -1;
	int catHash = 0;
	int vaseHash = 0;
	int tvHash = 0;
	int chairHash = 0;
	int playerHash = 0;
	
	top0 = new Space(); //creates each square individually because of inability to iterate variables
	left0 = top0;
	Space *pointer = top0;
	temp0 = pointer;
	
	pointer->right = new Space;
	pointer = pointer->right;
	pointer->left = temp0;
	top1 = pointer;
	temp1 = pointer;
	
	pointer->right = new Space;
	pointer = pointer->right;
	pointer->left = temp1;
	top2 = pointer;
	temp2 = pointer;
	
	pointer->right = new Space;
	pointer = pointer->right;
	pointer->left = temp2;
	top3 = pointer;
	right0 = pointer;
	temp3 = pointer;
	
	pointer = temp0;
	pointer->down = new Space;
	pointer = pointer->down;
	pointer->up = temp0;
	left1 = pointer;
	temp0 = pointer;
	
	pointer->right = new Space;
	pointer = pointer->right;
	pointer->up = temp1;
	pointer->left = temp0;
	pointer->up->down = pointer;
	temp1 = pointer;
	
	pointer->right = new Space;
	pointer = pointer->right;
	pointer->left = temp1;
	pointer->up = temp2;
	pointer->up->down = pointer;
	temp2 = pointer;
	
	pointer->right = new Space;
	pointer = pointer->right;
	pointer->up = temp3;
	pointer->left = temp2;
	pointer->up->down = pointer;
	right1 = pointer;
	temp3 = pointer;
	
	pointer = temp0;
	pointer->down = new Space;
	pointer = pointer->down;
	pointer->up = temp0;
	left2 = pointer;
	temp0 = pointer;
	
	pointer->right = new Space;
	pointer = pointer->right;
	pointer->left = temp0;
	pointer->up = temp1;
	pointer->up->down = pointer;
	temp1 = pointer;
	
	pointer->right = new Space;
	pointer = pointer->right;
	pointer->left = temp1;
	pointer->up = temp2;
	pointer->up->down = pointer;
	temp2 = pointer;
	
	pointer->right = new Space;
	pointer = pointer->right;
	pointer->left = temp2;
	pointer->up = temp3;
	pointer->up->down = pointer;
	right2 = pointer;
	temp3 = pointer;
	
	pointer = temp0;
	pointer->down = new Space;
	pointer = pointer->down;
	pointer->up = temp0;
	left3 = pointer;
	bottom0 = pointer;
	temp0 = pointer;
	
	pointer->right = new Space;
	pointer = pointer->right;
	pointer->left = temp0;
	pointer->up = temp1;
	pointer->up->down = pointer;
	bottom1 = pointer;
	temp1 = pointer;
	
	pointer->right = new Space;
	pointer = pointer->right;
	pointer->left = temp1;
	pointer->up = temp2;
	pointer->up->down = pointer;
	bottom2 = pointer;
	temp2 = pointer;
	
	pointer->right = new Space;
	pointer = pointer->right;
	pointer->left = temp2;
	pointer->up = temp3;
	pointer->up->down = pointer;
	bottom3 = pointer;
	right3 = pointer;
	temp3 = pointer;
	
	unsigned seed = std::time(nullptr); //pulls current epoch time for seed
	srand(seed); //sets seed
	catX = (rand() % 3);  //random X/Y coordinates for cat, TV, vase, chair, and Player
	catY = (rand() % 3);
	catHash = makeHash(catX,catY); // hash function makes sure that no two items are in the same place
	
	tvX = (rand() % 3);
	tvY = (rand() % 3);
	tvHash = makeHash(tvX,tvY);
	
	vaseX = (rand() % 3);
	vaseY = (rand() % 3);
	vaseHash = makeHash(vaseX,vaseY);
	
	chairX = (rand() % 3);
	chairY = (rand() % 3);
	chairHash = makeHash(chairX,chairY);
	
	playerX = (rand() % 2)+1;
	playerY = (rand() % 2)+1;
	playerHash = makeHash(playerX,playerY);
	
	while (tvHash == catHash || tvHash == vaseHash || tvHash == chairHash || tvHash == playerHash)
	{ 
		tvX = (rand() % 3);
		tvY = (rand() % 3);
		tvHash = makeHash(tvX,tvY);
	}
	
	while (vaseHash == catHash || vaseHash == tvHash || vaseHash == chairHash || vaseHash == playerHash)
	{	
		vaseX = (rand() % 3);
		vaseY = (rand() % 3);
		vaseHash = makeHash(vaseX,vaseY);
	}
	
	while (chairHash == catHash || chairHash == vaseHash || chairHash == tvHash || chairHash == playerHash)
	{
		chairX = (rand() % 3);
		chairY = (rand() % 3);
		chairHash = makeHash(chairX,chairY);
	}
	
	while (playerHash == catHash || playerHash == vaseHash || playerHash == tvHash || playerHash == chairHash)
	{
		playerX = (rand() % 2)+1;
		playerY = (rand() % 2)+1;
		playerHash = makeHash(playerX,playerY);
	}
	
	if (catX == 0) //place the cat
	{
		pointer = left0;
		if (catY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Cat;
			catP = pointer;
		}
		else if (catY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Cat;
			catP = pointer;
		}
		else if (catY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Cat;
			catP = pointer;
		}
		else if (catY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Cat;
			catP = pointer;
		}
	}
	else if (catX == 1)
	{
		pointer = left1;
		if (catY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Cat;
			catP = pointer;
		}
		else if (catY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Cat;
			catP = pointer;
		}
		else if (catY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Cat;
			catP = pointer;
		}
		else if (catY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Cat;
			catP = pointer;
		}
	}
	else if (catX == 2)
	{
		pointer = left2;
		if (catY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Cat;
			catP = pointer;
		}
		else if (catY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Cat;
			catP = pointer;
		}
		else if (catY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Cat;
			catP = pointer;
		}
		else if (catY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Cat;
			catP = pointer;
		}
	}
	if (catX == 3)
	{
		pointer = left3;
		if (catY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Cat;
			catP = pointer;
		}
		else if (catY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Cat;
			catP = pointer;
		}
		else if (catY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Cat;
			catP = pointer;
		}
		else if (catY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Cat;
			catP = pointer;
		}
	}

	if (tvX == 0) //place the TV
	{
		pointer = left0;
		if (tvY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new TV;
		}
		else if (tvY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new TV;
		}
		else if (tvY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new TV;
		}
		else if (tvY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new TV;
		}
	}
	else if (tvX == 1)
	{
		pointer = left1;
		if (tvY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new TV;
		}
		else if (tvY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new TV;
		}
		else if (tvY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new TV;
		}
		else if (tvY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new TV;
		}
	}
	else if (tvX == 2)
	{
		pointer = left2;
		if (tvY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new TV;
		}
		else if (tvY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new TV;
		}
		else if (tvY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new TV;
		}
		else if (tvY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new TV;
		}
	}
	if (tvX == 3)
	{
		pointer = left3;
		if (tvY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new TV;
		}
		else if (tvY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new TV;
		}
		else if (tvY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new TV;
		}
		else if (tvY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new TV;
		}
	}
	
	if (vaseX == 0) //place the vase
	{
		pointer = left0;
		if (vaseY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Vase;
		}
		else if (vaseY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Vase;
		}
		else if (vaseY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Vase;
		}
		else if (vaseY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Vase;
		}
	}
	else if (vaseX == 1)
	{
		pointer = left1;
		if (vaseY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Vase;
		}
		else if (vaseY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Vase;
		}
		else if (vaseY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Vase;
		}
		else if (vaseY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Vase;
		}
	}
	else if (vaseX == 2)
	{
		pointer = left2;
		if (vaseY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Vase;
		}
		else if (vaseY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Vase;
		}
		else if (vaseY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Vase;
		}
		else if (vaseY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Vase;
		}
	}
	if (vaseX == 3)
	{
		pointer = left3;
		if (vaseY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Vase;
		}
		else if (vaseY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Vase;
		}
		else if (vaseY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Vase;
		}
		else if (vaseY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Vase;
		}
	}
	
	if (playerX == 0) //place the player
	{
		pointer = left0;
		if (playerY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Item;
			pointer->item->setSymbol('P');
			playerP = pointer;
		}
		else if (playerY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Item;
			pointer->item->setSymbol('P');
			playerP = pointer;
		}
		else if (playerY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Item;
			pointer->item->setSymbol('P');
			playerP = pointer;
		}
		else if (playerY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Item;
			pointer->item->setSymbol('P');
			playerP = pointer;
		}
	}
	else if (playerX == 1)
	{
		pointer = left1;
		if (playerY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Item;
			pointer->item->setSymbol('P');
			playerP = pointer;
		}
		else if (playerY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Item;
			pointer->item->setSymbol('P');
			playerP = pointer;
		}
		else if (playerY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Item;
			pointer->item->setSymbol('P');
			playerP = pointer;
		}
		else if (playerY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Item;
			pointer->item->setSymbol('P');
			playerP = pointer;
		}
	}
	else if (playerX == 2)
	{
		pointer = left2;
		if (playerY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Item;
			pointer->item->setSymbol('P');
			playerP = pointer;
		}
		else if (playerY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Item;
			pointer->item->setSymbol('P');
			playerP = pointer;
		}
		else if (playerY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Item;
			pointer->item->setSymbol('P');
			playerP = pointer;
		}
		else if (playerY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Item;
			pointer->item->setSymbol('P');
			playerP = pointer;
		}
	}
	if (playerX == 3)
	{
		pointer = left3;
		if (playerY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Item;
			pointer->item->setSymbol('P');
			playerP = pointer;
		}
		else if (playerY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Item;
			pointer->item->setSymbol('P');
			playerP = pointer;
		}
		else if (playerY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Item;
			pointer->item->setSymbol('P');
			playerP = pointer;
		}
		else if (playerY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Item;
			pointer->item->setSymbol('P');
			playerP = pointer;
		}
	}
	
	if (chairX == 0) //place the chair
	{
		pointer = left0;
		if (chairY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Chair;
		}
		else if (chairY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Chair;
		}
		else if (chairY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Chair;
		}
		else if (chairY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Chair;
		}
	}
	else if (chairX == 1)
	{
		pointer = left1;
		if (chairY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Chair;
		}
		else if (chairY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Chair;
		}
		else if (chairY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Chair;
		}
		else if (chairY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Chair;
		}
	}
	else if (chairX == 2)
	{
		pointer = left2;
		if (chairY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Chair;
		}
		else if (chairY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Chair;
		}
		else if (chairY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Chair;
		}
		else if (chairY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Chair;
		}
	}
	if (chairX == 3)
	{
		pointer = left3;
		if (chairY == 0)
		{
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Chair;
		}
		else if (chairY == 1)
		{
			pointer = pointer->right;
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Chair;
		}
		else if (chairY == 2)
		{
			for (int i=0;i<2;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Chair;
		}
		else if (chairY == 3)
		{
			for (int i;i<3;i++)
			{
				pointer = pointer->right;
			}
			delete pointer->item;
			pointer->item = nullptr;
			pointer->item = new Chair;
		}
	}
	
	pointer = left0; //create and place Exit area
	pointer->left = new Exit;
	pointer = pointer->left;
	pointer->item->setName("Exit");
	pointer->item->setSymbol('E');
	pointer->right = left0;
	left0 = pointer;
	
	pointer = left1;
	pointer->left = new Exit;
	pointer = pointer->left;
	pointer->item->setName("Exit");
	pointer->item->setSymbol('E');
	pointer->right = left1;
	left1 = pointer;
	pointer->up = left0;
	pointer->up->down = pointer;
	
	pointer = left2;
	pointer->left = new Exit;
	pointer = pointer->left;
	pointer->item->setName("Exit");
	pointer->item->setSymbol('E');
	pointer->right = left2;
	left2 = pointer;
	pointer->up = left1;
	pointer->up->down = pointer;
	
	pointer = left3;
	pointer->left = new Exit;
	pointer = pointer->left;
	pointer->item->setName("Exit");
	pointer->item->setSymbol('E');	
	pointer->right = left3;
	left3 = pointer;
	pointer->up = left2;
	pointer->up->down = pointer;
	
	pointer = right0; //create and place Closet area
	pointer->right = new Closet;
	pointer = pointer->right;
	pointer->item->setName("Closet");
	pointer->item->setSymbol('C');
	pointer->left = right0;
	right0 = pointer;
	
	pointer = right1;
	pointer->right = new Closet;
	pointer = pointer->right;
	pointer->item->setName("Closet");
	pointer->item->setSymbol('C');
	pointer->left = right1;
	right1 = pointer;
	pointer->up = right0;
	pointer->up->down = pointer;
	
	pointer = right2;
	pointer->right = new Closet;
	pointer = pointer->right;
	pointer->item->setName("Closet");
	pointer->item->setSymbol('C');
	pointer->left = right2;
	right2 = pointer;
	pointer->up = right1;
	pointer->up->down = pointer;
	
	pointer = right3;
	pointer->right = new Closet;
	pointer = pointer->right;
	pointer->item->setName("Closet");
	pointer->item->setSymbol('C');	
	pointer->left = right3;
	right3 = pointer;
	pointer->up = right2;
	pointer->up->down = pointer;
}

void Floor::printFloor()
{
	Space *print = left0;
	char printer;
	
	std::cout << "---------------" << std::endl; //top of board
	
	std::cout << "| "; //side to board
	while (print != nullptr)
	{
		printer = print->item->printSymbol();
		std::cout << printer << " ";
		print = print->right;
	}
	std::cout << "|" << std::endl;
	
	std::cout << "| ";
	print = left1;
	while (print != nullptr)
	{
		printer = print->item->printSymbol();
		std::cout << printer << " ";
		print = print->right;
	}
	std::cout << "|" << std::endl;

	std::cout << "| ";	
	print = left2;
	while (print != nullptr)
	{
		printer = print->item->printSymbol();
		std::cout << printer << " ";
		print = print->right;
	}
	std::cout << "|" << std::endl;

	std::cout << "| ";	
	print = left3;
	while (print != nullptr)
	{
		printer = print->item->printSymbol();
		std::cout << printer << " ";
		print = print->right;
	}
	std::cout << "|" << std::endl;
	std::cout << "---------------" << std::endl; //bottom of board	
	std::cout << std::endl;
}

void Floor::newTurn()
{
	std::string entry;
	int direction = 0;
	int catMove = -1;
	bool catCheck = false;
	Item *temp;
	Item *temp2;
	Space *pointer;
	
	std::cout << "Which direction do you want to move?" << std::endl;
	std::cout << "1. North" << std::endl;
	std::cout << "2. East" << std::endl;
	std::cout << "3. South" << std::endl;
	std::cout << "4. West" << std::endl;
	
	while (std::getline(std::cin,entry)) //reads string to entry buffer
	{
		std::stringstream stream(entry); //starts string stream into buffer
		char extra;
		if (!(stream >> direction)) //if stream does not correctly go into integer variable
		{
			std::cout << "Please enter an integer." << std::endl;
			continue;
		}
		else if (direction <= 0 || direction >= 5)
		{
			std::cout << "Please select a valid option." << std::endl;
			continue;
		}
		if (stream >> extra) //test to see if there's any leftover chars in buffer
		{
			std::cout << "Please enter an integer." << std::endl;
			continue;
		}
		break; //it entered correctly, so exit loop
	}
	
	if (direction == 1) //moving up/North
	{
		if (playerP->up->item->printSymbol() == 'V' || playerP->up->item->printSymbol() == 'h' || playerP->up->item->printSymbol() == '@')
		{
			std::cout << "You trip over the obstacle in the dark, making a huge crash!" << std::endl;
			std::cout << "\"What on Earth is all that racket?\" your father shouts from downstairs. Busted!" << std::endl;
			gameLose = true;
			return;
		}
		else if (playerP->up->item->printSymbol() == 'c' && playerP->item->checkInv() == '.')
		{
			std::cout << "You try to pick up the cat, but it hisses and scraches your hands! Ouch!" << std::endl;
			std::cout << "The cat scampers away in the dark. Better find the closet and get the cat carrier out of it first!" << std::endl;
			return;
		}
		else if (playerP->up->item->printSymbol() == 'c' && playerP->item->checkInv() == 'C')
		{
			std::cout << "You carefully creep up on the pair of beady glowing eyes, open the cage..." << std::endl;
			std::cout << "...and the cat just walks inside and curls up, purring. Cats, huh?" << std::endl;
			getCat = true;
			delete catP->item;
			catP->item = new Item;
			return;
		}
		else if (playerP == top0 || playerP == top1 || playerP == top2 || playerP == top3)
		{
			std::cout << "You bump up against the cool concrete walls of the basement - and get a little basement gunk on your hands. Gross." << std::endl;
			std::cout << "Somewhere behind you, that darn cat hisses. Better turn around and keep looking." << std::endl;
			return;
		}
	
		temp = playerP->item; //store current location of Player item
		temp2 = playerP->up->item; //store next location of Player item
	
		playerP->up->item = temp; //swap item locations
		playerP->item = temp2;
		playerP = playerP->up;
				
		unsigned seed = std::time(nullptr); //pulls current epoch time for seed
		srand(seed); //sets seed
		while (catCheck == false)
		{
			catMove = (rand() % 3)+1;
			
			if (catMove == 1)
			{
				if (catP == top0 || catP == top1 || catP == top2 || catP == top3) //keep cat in bounds
				{
					break;
				}
				else if (catP->up->item->printSymbol() == 'E' || catP->up->item->printSymbol() == 'C')
				{ //keep cat out of closet and exit
					break;
				}
				else if (catP->up->item->printSymbol() != ' ')
				{	//prevent cat from getting stuck
					if (catP->up->up != nullptr || catP->up->up->item->printSymbol() != 'V' || catP->up->up->item->printSymbol() != 'h' || catP->up->up->item->printSymbol() != '@' || catP->up->up->item->printSymbol() != 'E' || catP->up->up->item->printSymbol() != 'C')
					{
						if (catP->up->up != nullptr)
						{
							temp = catP->item;
							temp2 = catP->up->up->item;
				
							catP->up->up->item = temp;
							catP->item = temp2;
							
							catP = catP->up->up;
							catCheck = true;
						}
						else
						{
							break;
						}
					}
				}
				else if (catP->up->item->printSymbol() == 'P')
				{
					std::cout << "You hear a low growling nearby..." << std::endl;
					catCheck = true;
				}
				else
				{
					temp = catP->item;
					temp2 = catP->up->item;
		
					catP->up->item = temp;
					catP->item = temp2;
					catP = catP->up;
					catCheck = true;
				}
			}
			else if (catMove == 2)
			{
				if (catP == right0 || catP == right1 || catP == right2 || catP == right3)
				{
					break;
				}
				else if (catP->right->item->printSymbol() == 'E' || catP->right->item->printSymbol() == 'C')
				{
					break;
				}
				else if (catP->right->item->printSymbol() != ' ')
				{	
					if (catP->right->right != nullptr || catP->right->right->item->printSymbol() != 'V' || catP->right->right->item->printSymbol() != 'h' || catP->right->right->item->printSymbol() != '@' || catP->right->right->item->printSymbol() != 'E' || catP->right->right->item->printSymbol() != 'C')
					{
						if (catP->right->right != nullptr)
						{
							temp = catP->item;
							temp2 = catP->right->right->item;
				
							catP->right->right->item = temp;
							catP->item = temp2;
							
							catP = catP->right->right;
							catCheck = true;
						}
						else
						{
							break;
						}
					}
				}
				else if (catP->right->item->printSymbol() == 'P')
				{
					std::cout << "You hear a low growling nearby..." << std::endl;
					catCheck = true;
				}
				else
				{
					temp = catP->item;
					temp2 = catP->right->item;
		
					catP->right->item = temp;
					catP->item = temp2;
					
					catP = catP->right;
					catCheck = true;
				}
			}
			else if (catMove == 3)
			{
				if (catP == bottom0 || catP == bottom1 || catP == bottom2 || catP == bottom3)
				{
					break;
				}
				else if (catP->down->item->printSymbol() == 'E' || catP->down->item->printSymbol() == 'C')
				{
					break;
				}
				else if (catP->down->item->printSymbol() != ' ')
				{	
					if (catP->down->down != nullptr || catP->down->down->item->printSymbol() != 'V' || catP->down->down->item->printSymbol() != 'h' || catP->down->down->item->printSymbol() != '@' || catP->down->down->item->printSymbol() != 'E' || catP->down->down->item->printSymbol() != 'C')
					{
						if (catP->down->down != nullptr)
						{
							temp = catP->item;
							temp2 = catP->down->down->item;
				
							catP->down->down->item = temp;
							catP->item = temp2;
							
							catP = catP->down->down;
							catCheck = true;
						}
						else
						{
							break;
						}
					}
				}
				else if (catP->down->item->printSymbol() == 'P')
				{
					std::cout << "You hear a low growling nearby..." << std::endl;
					catCheck = true;
				}
				else
				{
					temp = catP->item;
					temp2 = catP->down->item;
		
					catP->down->item = temp;
					catP->item = temp2;
					
					catP = catP->down;
					catCheck = true;
				}
			}
			else if (catMove == 4)
			{
				if (catP == left0 || catP == left1 || catP == left2 || catP == left3)
				{
					break;
				}
				else if (catP->left->item->printSymbol() == 'E' || catP->left->item->printSymbol() == 'C')
				{
					break;
				}
				else if (catP->left->item->printSymbol() != ' ')
				{
					if (catP->left->left != nullptr || catP->left->left->item->printSymbol() != 'V' || catP->left->left->item->printSymbol() != 'h' || catP->left->left->item->printSymbol() != '@' || catP->left->left->item->printSymbol() != 'E' || catP->left->left->item->printSymbol() != 'C')
					{
						if (catP->left->left != nullptr)
						{
							temp = catP->item;
							temp2 = catP->left->left->item;
				
							catP->left->left->item = temp;
							catP->item = temp2;
							
							catP = catP->left->left;
							catCheck = true;
						}
						else
						{
							break;
						}
					}
				}	
				else if (catP->left->item->printSymbol() == 'P')
				{
					std::cout << "You hear a low growling nearby..." << std::endl;
					catCheck = true;
				}
				else
				{
					temp = catP->item;
					temp2 = catP->left->item;
		
					catP->left->item = temp;
					catP->item = temp2;
					
					catP = catP->left;
					catCheck = true;
				}
			}
		}
	}
	
	if (direction == 2)
	{
		if (playerP->right->item->printSymbol() == 'V' || playerP->right->item->printSymbol() == 'h' || playerP->right->item->printSymbol() == '@')
		{
			std::cout << "You trip over the obstacle in the dark, making a huge crash!" << std::endl;
			std::cout << "\"What on Earth is all that racket?\" your father shouts from downstairs. Busted!" << std::endl;
			gameLose = true;
			return;
		}
		else if (playerP->right->item->printSymbol() == 'c' && playerP->item->checkInv() == '.')
		{
			std::cout << "You try to pick up the cat, but it hisses and scraches your hands! Ouch!" << std::endl;
			std::cout << "Better find the closet and get the cat carrier out of it first!" << std::endl;
		}
		else if (playerP->right->item->printSymbol() == 'c' && playerP->item->checkInv() == 'C')
		{
			std::cout << "You carefully creep up on the pair of beady glowing eyes, open the cage..." << std::endl;
			std::cout << "...and the cat just walks inside and curls up, purring. Cats, huh?" << std::endl;
			getCat = true;
			delete catP->item;
			catP->item = new Item;
			return;
		}
		else if (playerP->right->item->printSymbol() == 'C' && playerP->item->checkInv() == '.')
		{
			std::cout << "You run your hands over the sliding doors of the basement closet door, roll it open..." << std::endl;
			std::cout << "And there's that darn cat carrier! Now you can get the little beast without getting scratched up. Maybe." << std::endl;
			playerP->item->changeInv('C');
			return;
		}
		else if (playerP == right0 || playerP == right1 || playerP == right2 || playerP == right3)
		{
			std::cout << "You bump into rack after rack of dusty old coats. Achoo!" << std::endl;
			std::cout << "Who knows how far back these coats go - but there's the cat meowing somewhere in the darkness behind you." << std::endl;
			return;
		}
		
		temp = playerP->item;
		temp2 = playerP->right->item;
		std::cout << ":" << temp->printSymbol() << ":" << std::endl;
		std::cout << ":" << temp2->printSymbol() << ":" << std::endl;
		
		playerP->right->item = temp;
		playerP->item = temp2;
		playerP = playerP->right;

		
		std::cout << "Move complete" << std::endl;
				
		unsigned seed = std::time(nullptr); //pulls current epoch time for seed
		srand(seed); //sets seed
		while (catCheck == false)
		{
			catMove = (rand() % 3)+1;
			
			if (catMove == 1)
			{
				if (catP == top0 || catP == top1 || catP == top2 || catP == top3)
				{
					break;
				}
				else if (catP->up->item->printSymbol() == 'E' || catP->up->item->printSymbol() == 'C')
				{
					break;
				}
				else if (catP->up->item->printSymbol() != ' ')
				{	
					if (catP->up->up != nullptr || catP->up->up->item->printSymbol() != 'V' || catP->up->up->item->printSymbol() != 'h' || catP->up->up->item->printSymbol() != '@' || catP->up->up->item->printSymbol() != 'E' || catP->up->up->item->printSymbol() != 'C')
					{
						if (catP->up->up != nullptr)
						{
							temp = catP->item;
							temp2 = catP->up->up->item;
				
							catP->up->up->item = temp;
							catP->item = temp2;
							
							catP = catP->up->up;
							catCheck = true;
						}
						else
						{
							break;
						}
					}
				}
				else if (catP->up->item->printSymbol() == 'P')
				{
					std::cout << "You hear a low growling nearby..." << std::endl;
					catCheck = true;
				}
				else
				{
					temp = catP->item;
					temp2 = catP->up->item;
		
					catP->up->item = temp;
					catP->item = temp2;
					catP = catP->up;
					catCheck = true;
				}
			}
			else if (catMove == 2)
			{
				if (catP == right0 || catP == right1 || catP == right2 || catP == right3)
				{
					break;
				}
				else if (catP->right->item->printSymbol() == 'E' || catP->right->item->printSymbol() == 'C')
				{
					break;
				}
				else if (catP->right->item->printSymbol() != ' ')
				{	
					if (catP->right->right != nullptr || catP->right->right->item->printSymbol() != 'V' || catP->right->right->item->printSymbol() != 'h' || catP->right->right->item->printSymbol() != '@' || catP->right->right->item->printSymbol() != 'E' || catP->right->right->item->printSymbol() != 'C')
					{
						if (catP->right->right != nullptr)
						{
							temp = catP->item;
							temp2 = catP->right->right->item;
				
							catP->right->right->item = temp;
							catP->item = temp2;
							
							catP = catP->right->right;
							catCheck = true;
						}
						else
						{
							break;
						}
					}
				}
				else if (catP->right->item->printSymbol() == 'P')
				{
					std::cout << "You hear a low growling nearby..." << std::endl;
					catCheck = true;
				}
				else
				{
					temp = catP->item;
					temp2 = catP->right->item;
		
					catP->right->item = temp;
					catP->item = temp2;
					
					catP = catP->right;
					catCheck = true;
				}
			}
			else if (catMove == 3)
			{
				if (catP == bottom0 || catP == bottom1 || catP == bottom2 || catP == bottom3)
				{
					break;
				}
				else if (catP->down->item->printSymbol() == 'E' || catP->down->item->printSymbol() == 'C')
				{
					break;
				}
				else if (catP->down->item->printSymbol() != ' ')
				{	
					if (catP->down->down != nullptr || catP->down->down->item->printSymbol() != 'V' || catP->down->down->item->printSymbol() != 'h' || catP->down->down->item->printSymbol() != '@' || catP->down->down->item->printSymbol() != 'E' || catP->down->down->item->printSymbol() != 'C')
					{
						if (catP->down->down != nullptr)
						{
							temp = catP->item;
							temp2 = catP->down->down->item;
				
							catP->down->down->item = temp;
							catP->item = temp2;
							
							catP = catP->down->down;
							catCheck = true;
						}
						else
						{
							break;
						}
					}
				}
				else if (catP->down->item->printSymbol() == 'P')
				{
					std::cout << "You hear a low growling nearby..." << std::endl;
					catCheck = true;
				}
				else
				{
					temp = catP->item;
					temp2 = catP->down->item;
		
					catP->down->item = temp;
					catP->item = temp2;
					
					catP = catP->down;
					catCheck = true;
				}
			}
			else if (catMove == 4)
			{
				if (catP == left0 || catP == left1 || catP == left2 || catP == left3)
				{
					break;
				}
				else if (catP->left->item->printSymbol() == 'E' || catP->left->item->printSymbol() == 'C')
				{
					break;
				}
				else if (catP->left->item->printSymbol() != ' ')
				{
					if (catP->left->left != nullptr || catP->left->left->item->printSymbol() != 'V' || catP->left->left->item->printSymbol() != 'h' || catP->left->left->item->printSymbol() != '@' || catP->left->left->item->printSymbol() != 'E' || catP->left->left->item->printSymbol() != 'C')
					{
						if (catP->left->left != nullptr)
						{
							temp = catP->item;
							temp2 = catP->left->left->item;
				
							catP->left->left->item = temp;
							catP->item = temp2;
							
							catP = catP->left->left;
							catCheck = true;
						}
						else
						{
							break;
						}
					}
				}	
				else if (catP->left->item->printSymbol() == 'P')
				{
					std::cout << "You hear a low growling nearby..." << std::endl;
					catCheck = true;
				}
				else
				{
					temp = catP->item;
					temp2 = catP->left->item;
		
					catP->left->item = temp;
					catP->item = temp2;
					
					catP = catP->left;
					catCheck = true;
				}
			}
		}
	}
	
	if (direction == 3)
	{
		if (playerP->down->item->printSymbol() == 'V' || playerP->down->item->printSymbol() == 'h' || playerP->down->item->printSymbol() == '@')
		{
			std::cout << "You trip over the obstacle in the dark, making a huge crash!" << std::endl;
			std::cout << "\"What on Earth is all that racket?\" your father shouts from downstairs. Busted!" << std::endl;
			gameLose = true;
			return;
		}
		else if (playerP->down->item->printSymbol() == 'c' && playerP->item->checkInv() == '.')
		{
			std::cout << "You try to pick up the cat, but it hisses and scraches your hands! Ouch!" << std::endl;
			std::cout << "Better find the closet and get the cat carrier out of it first!" << std::endl;
		}
		else if (playerP->down->item->printSymbol() == 'c' && playerP->item->checkInv() == 'C')
		{
			std::cout << "You carefully creep up on the pair of beady glowing eyes, open the cage..." << std::endl;
			std::cout << "...and the cat just walks inside and curls up, purring. Cats, huh?" << std::endl;
			getCat = true;
			delete catP->item;
			catP->item = new Item;
			return;
		}
		else if (playerP == bottom0 || playerP == bottom1 || playerP == bottom2 || playerP == bottom3)
		{
			std::cout << "You bump up against the cool concrete walls of the basement - and get a little basement gunk on your hands. Gross." << std::endl;
			std::cout << "Somewhere behind you, that darn cat hisses. Better turn around and keep looking." << std::endl;
			return;
		}
		
		temp = playerP->item;
		temp2 = playerP->down->item;
			
		playerP->down->item = temp;
		playerP->item = temp2;
		playerP = playerP->down;	
				
		unsigned seed = std::time(nullptr); //pulls current epoch time for seed
		srand(seed); //sets seed
		while (catCheck == false)
		{
			catMove = (rand() % 3)+1;
			
			if (catMove == 1)
			{
				if (catP == top0 || catP == top1 || catP == top2 || catP == top3)
				{
					break;
				}
				else if (catP->up->item->printSymbol() == 'E' || catP->up->item->printSymbol() == 'C')
				{
					break;
				}
				else if (catP->up->item->printSymbol() != ' ')
				{	
					if (catP->up->up != nullptr || catP->up->up->item->printSymbol() != 'V' || catP->up->up->item->printSymbol() != 'h' || catP->up->up->item->printSymbol() != '@' || catP->up->up->item->printSymbol() != 'E' || catP->up->up->item->printSymbol() != 'C')
					{
						if (catP->up->up != nullptr)
						{
							temp = catP->item;
							temp2 = catP->up->up->item;
				
							catP->up->up->item = temp;
							catP->item = temp2;
							
							catP = catP->up->up;
							catCheck = true;
						}
						else
						{
							break;
						}
					}
				}
				else if (catP->up->item->printSymbol() == 'P')
				{
					std::cout << "You hear a low growling nearby..." << std::endl;
					catCheck = true;
				}
				else
				{
					temp = catP->item;
					temp2 = catP->up->item;
		
					catP->up->item = temp;
					catP->item = temp2;
					catP = catP->up;
					catCheck = true;
				}
			}
			else if (catMove == 2)
			{
				if (catP == right0 || catP == right1 || catP == right2 || catP == right3)
				{
					break;
				}
				else if (catP->right->item->printSymbol() == 'E' || catP->right->item->printSymbol() == 'C')
				{
					break;
				}
				else if (catP->right->item->printSymbol() != ' ')
				{	
					if (catP->right->right != nullptr || catP->right->right->item->printSymbol() != 'V' || catP->right->right->item->printSymbol() != 'h' || catP->right->right->item->printSymbol() != '@' || catP->right->right->item->printSymbol() != 'E' || catP->right->right->item->printSymbol() != 'C')
					{
						if (catP->right->right != nullptr)
						{
							temp = catP->item;
							temp2 = catP->right->right->item;
				
							catP->right->right->item = temp;
							catP->item = temp2;
							
							catP = catP->right->right;
							catCheck = true;
						}
						else
						{
							break;
						}
					}
				}
				else if (catP->right->item->printSymbol() == 'P')
				{
					std::cout << "You hear a low growling nearby..." << std::endl;
					catCheck = true;
				}
				else
				{
					temp = catP->item;
					temp2 = catP->right->item;
		
					catP->right->item = temp;
					catP->item = temp2;
					
					catP = catP->right;
					catCheck = true;
				}
			}
			else if (catMove == 3)
			{
				if (catP == bottom0 || catP == bottom1 || catP == bottom2 || catP == bottom3)
				{
					break;
				}
				else if (catP->down->item->printSymbol() == 'E' || catP->down->item->printSymbol() == 'C')
				{
					break;
				}
				else if (catP->down->item->printSymbol() != ' ')
				{	
					if (catP->down->down != nullptr || catP->down->down->item->printSymbol() != 'V' || catP->down->down->item->printSymbol() != 'h' || catP->down->down->item->printSymbol() != '@' || catP->down->down->item->printSymbol() != 'E' || catP->down->down->item->printSymbol() != 'C')
					{
						if (catP->down->down != nullptr)
						{
							temp = catP->item;
							temp2 = catP->down->down->item;
				
							catP->down->down->item = temp;
							catP->item = temp2;
							
							catP = catP->down->down;
							catCheck = true;
						}
						else
						{
							break;
						}
					}
				}
				else if (catP->down->item->printSymbol() == 'P')
				{
					std::cout << "You hear a low growling nearby..." << std::endl;
					catCheck = true;
				}
				else
				{
					temp = catP->item;
					temp2 = catP->down->item;
		
					catP->down->item = temp;
					catP->item = temp2;
					
					catP = catP->down;
					catCheck = true;
				}
			}
			else if (catMove == 4)
			{
				if (catP == left0 || catP == left1 || catP == left2 || catP == left3)
				{
					break;
				}
				else if (catP->left->item->printSymbol() == 'E' || catP->left->item->printSymbol() == 'C')
				{
					break;
				}
				else if (catP->left->item->printSymbol() != ' ')
				{
					if (catP->left->left != nullptr || catP->left->left->item->printSymbol() != 'V' || catP->left->left->item->printSymbol() != 'h' || catP->left->left->item->printSymbol() != '@' || catP->left->left->item->printSymbol() != 'E' || catP->left->left->item->printSymbol() != 'C')
					{
						if (catP->left->left != nullptr)
						{
							temp = catP->item;
							temp2 = catP->left->left->item;
				
							catP->left->left->item = temp;
							catP->item = temp2;
							
							catP = catP->left->left;
							catCheck = true;
						}
						else
						{
							break;
						}
					}
				}	
				else if (catP->left->item->printSymbol() == 'P')
				{
					std::cout << "You hear a low growling nearby..." << std::endl;
					catCheck = true;
				}
				else
				{
					temp = catP->item;
					temp2 = catP->left->item;
		
					catP->left->item = temp;
					catP->item = temp2;
					
					catP = catP->left;
					catCheck = true;
				}
			}
		}	
	}
	
	if (direction == 4)
	{
		if (playerP->left->item->printSymbol() == 'V' || playerP->left->item->printSymbol() == 'h' || playerP->left->item->printSymbol() == '@')
		{
			std::cout << "You trip over the obstacle in the dark, making a huge crash!" << std::endl;
			std::cout << "\"What on Earth is all that racket?\" your father shouts from downstairs. Busted!" << std::endl;
			gameLose = true;
			return;
		}
		else if (playerP->left->item->printSymbol() == 'c' && playerP->item->checkInv() == '.')
		{
			std::cout << "You try to pick up the cat, but it hisses and scraches your hands! Ouch!" << std::endl;
			std::cout << "Better find the closet and get the cat carrier out of it first!" << std::endl;
		}
		else if (playerP->left->item->printSymbol() == 'c' && playerP->item->checkInv() == 'C')
		{
			std::cout << "You carefully creep up on the pair of beady glowing eyes, open the cage..." << std::endl;
			std::cout << "...and the cat just walks inside and curls up, purring. Cats, huh?" << std::endl;
			getCat = true;
			delete catP->item;
			catP->item = new Item;
			return;
		}
		else if (playerP->left->item->printSymbol() == 'E' && getCat == false)
		{
			std::cout << "You find your way back to the steps going upstairs - but that darn cat is still in the basement." << std::endl;
			std::cout << "Better turn around and see if you can find the darn thing before your parents wake up." << std::endl;
		}
		else if (playerP == left0 || playerP == left1 || playerP == left2 || playerP == left3)
		{
			std::cout << "You put your hand on the doorknob - but you still don't have the cat!" << std::endl;
			std::cout << "Better turn around and find that cat!" << std::endl;
			return;
		}
		else if (playerP->left->item->printSymbol() == 'E' && getCat == true)
		{
			std::cout << "Cat in the carrier and carrier in hand, you open the door and head up the steps." << std::endl;
			std::cout << "You managed to get the cat before your parents woke up - good job!" << std::endl;
			std::cout << "Setting the carrier down, you slowly open the door..." << std::endl;
			std::cout << "...and the cat bolts out and heads right back down stairs! Oh well." << std::endl;
			gameWin = true;
			return;
		}
		
		temp = playerP->item;
		temp2 = playerP->left->item;
		
		playerP->left->item = temp;
		playerP->item = temp2;
		playerP = playerP->left;	
				
		unsigned seed = std::time(nullptr); //pulls current epoch time for seed
		srand(seed); //sets seed
		while (catCheck == false)
		{
			catMove = (rand() % 3)+1;
			
			if (catMove == 1)
			{
				if (catP == top0 || catP == top1 || catP == top2 || catP == top3)
				{
					break;
				}
				else if (catP->up->item->printSymbol() == 'E' || catP->up->item->printSymbol() == 'C')
				{
					break;
				}
				else if (catP->up->item->printSymbol() != ' ')
				{	
					if (catP->up->up != nullptr || catP->up->up->item->printSymbol() != 'V' || catP->up->up->item->printSymbol() != 'h' || catP->up->up->item->printSymbol() != '@' || catP->up->up->item->printSymbol() != 'E' || catP->up->up->item->printSymbol() != 'C')
					{
						if (catP->up->up != nullptr)
						{
							temp = catP->item;
							temp2 = catP->up->up->item;
				
							catP->up->up->item = temp;
							catP->item = temp2;
							
							catP = catP->up->up;
							catCheck = true;
						}
						else
						{
							break;
						}
					}
				}
				else if (catP->up->item->printSymbol() == 'P')
				{
					std::cout << "You hear a low growling nearby..." << std::endl;
					catCheck = true;
				}
				else
				{
					temp = catP->item;
					temp2 = catP->up->item;
		
					catP->up->item = temp;
					catP->item = temp2;
					catP = catP->up;
					catCheck = true;
				}
			}
			else if (catMove == 2)
			{
				if (catP == right0 || catP == right1 || catP == right2 || catP == right3)
				{
					break;
				}
				else if (catP->right->item->printSymbol() == 'E' || catP->right->item->printSymbol() == 'C')
				{
					break;
				}
				else if (catP->right->item->printSymbol() != ' ')
				{	
					if (catP->right->right != nullptr || catP->right->right->item->printSymbol() != 'V' || catP->right->right->item->printSymbol() != 'h' || catP->right->right->item->printSymbol() != '@' || catP->right->right->item->printSymbol() != 'E' || catP->right->right->item->printSymbol() != 'C')
					{
						if (catP->right->right != nullptr)
						{
							temp = catP->item;
							temp2 = catP->right->right->item;
				
							catP->right->right->item = temp;
							catP->item = temp2;
							
							catP = catP->right->right;
							catCheck = true;
						}
						else
						{
							break;
						}
					}
				}
				else if (catP->right->item->printSymbol() == 'P')
				{
					std::cout << "You hear a low growling nearby..." << std::endl;
					catCheck = true;
				}
				else
				{
					temp = catP->item;
					temp2 = catP->right->item;
		
					catP->right->item = temp;
					catP->item = temp2;
					
					catP = catP->right;
					catCheck = true;
				}
			}
			else if (catMove == 3)
			{
				if (catP == bottom0 || catP == bottom1 || catP == bottom2 || catP == bottom3)
				{
					break;
				}
				else if (catP->down->item->printSymbol() == 'E' || catP->down->item->printSymbol() == 'C')
				{
					break;
				}
				else if (catP->down->item->printSymbol() != ' ')
				{	
					if (catP->down->down != nullptr || catP->down->down->item->printSymbol() != 'V' || catP->down->down->item->printSymbol() != 'h' || catP->down->down->item->printSymbol() != '@' || catP->down->down->item->printSymbol() != 'E' || catP->down->down->item->printSymbol() != 'C')
					{
						if (catP->down->down != nullptr)
						{
							temp = catP->item;
							temp2 = catP->down->down->item;
				
							catP->down->down->item = temp;
							catP->item = temp2;
							
							catP = catP->down->down;
							catCheck = true;
						}
						else
						{
							break;
						}
					}
				}
				else if (catP->down->item->printSymbol() == 'P')
				{
					std::cout << "You hear a low growling nearby..." << std::endl;
					catCheck = true;
				}
				else
				{
					temp = catP->item;
					temp2 = catP->down->item;
		
					catP->down->item = temp;
					catP->item = temp2;
					
					catP = catP->down;
					catCheck = true;
				}
			}
			else if (catMove == 4)
			{
				if (catP == left0 || catP == left1 || catP == left2 || catP == left3)
				{
					break;
				}
				else if (catP->left->item->printSymbol() == 'E' || catP->left->item->printSymbol() == 'C')
				{
					break;
				}
				else if (catP->left->item->printSymbol() != ' ')
				{
					if (catP->left->left != nullptr || catP->left->left->item->printSymbol() != 'V' || catP->left->left->item->printSymbol() != 'h' || catP->left->left->item->printSymbol() != '@' || catP->left->left->item->printSymbol() != 'E' || catP->left->left->item->printSymbol() != 'C')
					{
						if (catP->left->left != nullptr)
						{
							temp = catP->item;
							temp2 = catP->left->left->item;
				
							catP->left->left->item = temp;
							catP->item = temp2;
							
							catP = catP->left->left;
							catCheck = true;
						}
						else
						{
							break;
						}
					}
				}	
				else if (catP->left->item->printSymbol() == 'P')
				{
					std::cout << "You hear a low growling nearby..." << std::endl;
					catCheck = true;
				}
				else
				{
					temp = catP->item;
					temp2 = catP->left->item;
		
					catP->left->item = temp;
					catP->item = temp2;
					
					catP = catP->left;
					catCheck = true;
				}
			}
		}
	}	
}

void Floor::senseNear() //sense nearby objects
{
	if (playerP->up->item->printSymbol() == 'V') //read in a given direction and output text
	{
		std::cout << "The scent of decaying flowers comes from just north of you..." << std::endl;
	}
	else if (playerP->right->item->printSymbol() == 'V')
	{
		std::cout << "The scent of decaying flowers comes from just east of you..." << std::endl;
	}
	else if (playerP->left->item->printSymbol() == 'V')
	{
		std::cout << "The scent of decaying flowers comes from just west of you..." << std::endl;
	}
	else if (playerP->down->item->printSymbol() == 'V')
	{
		std::cout << "The scent of decaying flowers comes from just south of you..." << std::endl;
	}
	
	if (playerP->up->item->printSymbol() == '@')
	{
		std::cout << "You hear the faint crackle of a old cathode tube just north of you..." << std::endl;
	}
	else if (playerP->right->item->printSymbol() == '@')
	{
		std::cout << "You hear the faint crackle of a old cathode tube just east of you..." << std::endl;
	}
	else if (playerP->left->item->printSymbol() == '@')
	{
		std::cout << "You hear the faint crackle of a old cathode tube just west of you..." << std::endl;
	}
	else if (playerP->down->item->printSymbol() == '@')
	{
		std::cout << "You hear the faint crackle of a old cathode tube just south of you..." << std::endl;
	}
	
	if (playerP->up->item->printSymbol() == 'h')
	{
		std::cout << "Your nose fills with the dust of decaying upholstery from the north..." << std::endl;
	}
	else if (playerP->right->item->printSymbol() == 'h')
	{
		std::cout << "Your nose fills with the dust of decaying upholstery from the east..." << std::endl;
	}
	else if (playerP->left->item->printSymbol() == 'h')
	{
		std::cout << "Your nose fills with the dust of decaying upholstery from the west..." << std::endl;
	}
	else if (playerP->down->item->printSymbol() == 'h')
	{
		std::cout << "Your nose fills with the dust of decaying upholstery from the south..." << std::endl;
	}
}

bool Floor::getWin()
{
	return gameWin;
}

bool Floor::getLose()
{
	return gameLose;
}

int Floor::makeHash(int x, int y) //Cantor pairing function to prevent overlapping items
{
	return (((x+y)*(x+y+1))/2)+y;
}