/**
 * \file    SnakeItem.h
 * \date    2018/10/23
 * \author  yazilimperver
 * \brief   
 * Copyright © 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef SNAKEITEM_H__
#define SNAKEITEM_H__

#include <Player.h>
#include <ConsoleCellItem.h>
#include <deque>

class SnakeItem
{
public:
	SnakeItem(ConsoleLevel& level, const ConsoleCellData& snakeHead);

	/// Re-initialize this snake with given data
	void initialize(const ConsoleCellData& snakeHead);
	
	/// Just display item
	void display();

	/// Update this snake
	void update(float timePassedInMsec);

	/// For upper management :)
	bool isGameOver() const;

	int getScore() const;
	/// Assign player to this snake
	void assignPlayer(Player& player);

	/// Direction information
	enum eDirection
	{
		DIRECTION_LEFT,
		DIRECTION_RIGHT,
		DIRECTION_UP,
		DIRECTION_DOWN,
	};
protected:

	void addTail();

	/// Check input
	void checkInput();

	/// Clear tail cell
	void clearTail();

	/// Perform movement
	void performMove(eDirection direction);

	/// Check for game over
	bool isGameOver(const COORD& coordToCheck);

	/// Initialization completed
	bool mIsInitialized = true;

	/// The player assigned to this snake item
	Player* mPlayer = nullptr;

	/// Is game over
	bool mIsGameOver = false;

	/// Snake game logic items
	/// We will hold snake body content as deque
	/// separated from position data to prevent unnecessary updates
	std::deque<int> mSnakeBodyContent;

	/// Hold position of each content starting from head
	std::deque<COORD> mSnakeBody;

	/// The cell that should be used as start point for clear
	/// This will be the tail of previous tick
	COORD mCellToClear;	

	/// Add body part snake
	bool mAddBodyPart = false;	 
	int mMovementLeftToAdd = 0;
	int mNewBodyPartContent = 0;

	/// The list of cell items
	eDirection mCurrentDirection = DIRECTION_RIGHT;

	/// Initiated direction (will be more useful for networking)
	eDirection mInitiatedDirection = DIRECTION_RIGHT;

	/// The accumulated time since last move
	float mAccumulatedTime = 0;

	/// The item move timeout in milliseconds
	const float cInitialTimeOut = 250.0F;
	float mMoveTimeout = cInitialTimeOut;

	/// Ignore consecutive keyboard inputs till previous one is applied
	bool mIgnoreInput = false;

	/// Whether use keyboard or not
	bool mUseKeyboard = true;

	/// Tron mode
	bool mIsTronModeEnabled = true;

	/// Border to prevent item get out scope
	RECT mBorder{ 2, 3, 117, 28 };			
};

#endif // SNAKEITEM_H__

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
