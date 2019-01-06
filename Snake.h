/**
 * @fileSnake.h
 * @date2018/10/23
 * @authoryazilimperver
 * @brief 
 * Copyright (C) 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef SNAKE_H__
#define SNAKE_H__

#include <Player.h>
#include <ConsoleCellItem.h>
#include <deque>

class SnakeModeItemGenerator;

/**
 * @brief This class is responsible from management of snake mechanics. Each player will have instance of this class in multiplayer case.
 * 
 */
class Snake
{
public:
	/**
	 * @brief Construct a new Snake object
	 * 
	 * @param itemGenerator Item generator which will be used to check if snake eat one of item generated
	 * @param level The level that snake will move on
	 * @param snakeHead The initial head position and associated data for snake
	 */
	Snake(SnakeModeItemGenerator& itemGenerator, ConsoleLevel& level, const ConsoleCellData& snakeHead);

	/**
	 * @brief Re-initialize this snake with given data (i.e. restarts)
	 * 
	 * @param snakeHead The snake head position
	 */
	void initialize(const ConsoleCellData& snakeHead);
	
	/**
	 * @brief Display method
	 * 
	 */
	void display();

	/**
	 * @brief Perform snake mechanics
	 * 
	 * @param timePassedInMsec 
	 */
	void update(float timePassedInMsec);

	/**
	 * @brief Gameover check
	 * 
	 * @return true 
	 * @return false 
	 */
	bool isGameOver() const;

	/**
	 * @brief Set tron mode enabled make snake getting longer per timeout. Otherwise it only grow with fruit
	 * 
	 * @param isEnabled 
	 */
	void setTronMode(bool isEnabled);

	/**
	 * @brief Assign player to this snake
	 * 
	 * @param player 
	 */
	void assignPlayer(Player& player);

	/**
	 * @brief Return snake body content which will be used by item generator for the time being
	 * 
	 * @return const std::deque<COORD>& 
	 */
	const std::deque<COORD>& getBody() const;

	/**
	 * @brief Snake direction information
	 * 
	 */
	enum eDirection
	{
		DIRECTION_LEFT,
		DIRECTION_RIGHT,
		DIRECTION_UP,
		DIRECTION_DOWN,
	};
protected:

	/**
	 * @brief Add a tail to snake
	 * 
	 */
	void addTail();

	/**
	 * @brief Check keyboard input
	 * 
	 */
	void checkInput();

	/**
	 * @brief Clear tail cell
	 * 
	 */
	void clearTail();

	/**
	 * @brief Perform snake movement mechanics
	 * 
	 * @param direction 
	 */
	void performMove(eDirection direction);

	/**
	 * @brief Check provided cell for game over conditions (usually new head)
	 * 
	 * @param coordToCheck 
	 * @return true 
	 * @return false 
	 */
	bool isGameOver(const COORD& coordToCheck);

	/**
	 * @brief Initialization status
	 * 
	 */
	bool mIsInitialized = true;

	/**
	 * @brief The item generator that we will use for checking fruit
	 * 
	 */
	SnakeModeItemGenerator& mSnakeModeItemGenerator;

	/**
	 * @brief The player assigned to this snake item
	 * 
	 */
	Player* mPlayer = nullptr;

	/**
	 * @brief Is game over
	 * 
	 */
	bool mIsGameOver = false;

	/**
	 * @briefSnake game logic items. We will hold snake body content as deque separated from position data to prevent unnecessary updates
	 */
	std::deque<int> mSnakeBodyContent;

	/**
	 * @brief Hold position of each content starting from head
	 * 
	 */
	std::deque<COORD> mSnakeBody;

	/**
	 * @brief The cell that should be used as start point for clear. This will be the tail of previous tick
	 * 
	 */
	COORD mCellToClear;	

	/**
	 * @brief Add body part to snake conditions flag
	 * 
	 */
	bool mAddBodyPart = false;	 
	int mMovementLeftToAdd = 0;
	int mNewBodyPartContent = 0;

	/**
	 * @brief Current snake direction
	 * 
	 */
	eDirection mCurrentDirection = DIRECTION_RIGHT;

	/**
	 * @brief Initiated direction (will be more useful for networking)
	 * 
	 */
	eDirection mInitiatedDirection = DIRECTION_RIGHT;

	/**
	 * @brief The accumulated time since last move in miliseconds
	 * 
	 */
	float mAccumulatedTime = 0;

	/**
	 * @brief The snake move timeout in milliseconds
	 * 
	 */
	const float cInitialTimeOut = 250.0F;

	/**
	 * @brief The variable that will be used to track snake movement
	 * 
	 */	
	float mMoveTimeout = cInitialTimeOut;

	/**
	 * @brief Ignore consecutive keyboard inputs till previous one is applied
	 * 
	 */
	bool mIgnoreInput = false;

	/**
	 * @brief Whether use keyboard or not
	 * 
	 */
	bool mUseKeyboard = true;

	/**
	 * @brief Current snake game mode
	 * 
	 */
	bool mIsTronModeEnabled = true;

	/**
	 * @brief The game level border to prevent item get out scope
	 * 
	 */
	RECT mBorder{ 2, 3, 117, 28 };			
};

#endif // SNAKE_H__

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
