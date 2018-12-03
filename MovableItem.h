/**
 * \file    MovableItem.h
 * \date    2018/10/22
 * \author  yazilimperver
 * \brief   
 * Copyright © 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef MOVABLEITEM_H__
#define MOVABLEITEM_H__

#include <ConsoleCellItem.h>

class MovableItem
{
public:
	MovableItem(ConsoleLevel& level, const ConsoleCellData& initialCellInfo);

	/// Just displat item
	void displayItem();

	/// Will also check keyboard input if requested
	void display();

	void update(float timePassedInMsec);
private:
	/// The movable item
	ConsoleCellItem mCellItem;
	
	enum eDirection
	{
		DIRECTION_LEFT,
		DIRECTION_RIGHT,
		DIRECTION_UP,
		DIRECTION_DOWN,
	};

	/// Current direction of cell item
	eDirection mDirection = DIRECTION_LEFT;
	   
	/// The accumulated time since last move
	float mAccumulatedTime = 0;

	/// The item move timeout in milliseconds
	float mMoveTimeout = 500;

	/// Whether use keyboard or not
	bool mUseKeyboard = true;

	/// Border to prevent item get out scope
	RECT mBorder{ 2, 3, 117, 28 };
};

#endif // MOVABLEITEM_H__

/*
  Copyright (c) [2018] [Yazilimperver <yazilimpervergs@gmail.com>]
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/
