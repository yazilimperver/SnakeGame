#include "MovableItem.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include "ConsoleLevel.h"
#include "ConsoleUtil.h"

MovableItem::MovableItem(ConsoleLevel& level, const ConsoleCellData& initialCellInfo)
	: mCellItem{ level, initialCellInfo }
{								 	
	level.getLevelBorders(mBorder);
}

void MovableItem::displayItem()
{
	mCellItem.display();
}

void MovableItem::display()
{		
}

void MovableItem::update(float timePassedInMsec)
{
	// Check keyboard
	int readData = getNonBlockingChar();

	if (-1 != readData)
	{
		constexpr int KEY_UP = 0x48;
		constexpr int KEY_DOWN = 0x50;
		constexpr int KEY_LEFT = 0x4b;
		constexpr int KEY_RIGHT = 0x4d;

		switch (readData)
		{
		case KEY_LEFT:
			mDirection = DIRECTION_LEFT;
			break;
		case KEY_RIGHT:
			mDirection = DIRECTION_RIGHT;
			break;
		case KEY_UP:
			mDirection = DIRECTION_UP;
			break;
		case KEY_DOWN:
			mDirection = DIRECTION_DOWN;
			break;
		}
	}

	mAccumulatedTime += timePassedInMsec;

	if (mAccumulatedTime > mMoveTimeout)
	{
		mAccumulatedTime = 0;

		COORD coord = mCellItem.getCellItemData().mPosition;

		// Move item according to direction
		switch (mDirection)
		{
		case MovableItem::DIRECTION_LEFT:
			coord.X--;
			break;
		case MovableItem::DIRECTION_RIGHT:
			coord.X++;
			break;
		case MovableItem::DIRECTION_UP:
			coord.Y--;
			break;
		case MovableItem::DIRECTION_DOWN:
			coord.Y++;
			break;
		}

		// Check boundary
		if ((coord.X < mBorder.right)
			&&
			(coord.X >= mBorder.left)
			&&
			(coord.Y >= mBorder.top)
			&&
			(coord.Y < mBorder.bottom))
		{							 
			mCellItem.moveTo(coord);
		}
	}
}
