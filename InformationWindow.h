/**
 * @file    InformationWindow.h
 * @date    2018/12/01
 * @author  yazilimperver
 * @brief   Responsible for displaying information about current game
 * Copyright � 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef INFORMATION_WINDOW_H__
#define INFORMATION_WINDOW_H__

#include <GameMode.h>
#include <Player.h>
#include <vector>
#include <chrono>

/**
 * @brief This class is responsible for displaying information under game level during gameplay.
 *        
 */
class InformationWindow
{
public:
	/**
	 * @brief This function display information that does not change during game
	 * 
	 */
	void displayCommonConsoleInfo();

	/**
	 * @brief This function display information that change continuously during game
	 * 
	 */
	void displayConsoleInfo();

	/**
	 * @brief Get the Game Mode
	 * 
	 * @return GameMode 
	 */
	GameMode getGameMode() const;
  
  /**
   * @brief Set the Game Mode object
   * 
   * @param val New game mode which is set at the beginning of game
   */
	void setGameMode(GameMode val);

  /**
   * @brief Set the Console Width
   * 
   * @param val The width of console level that game will be played
   */
	void setConsoleWidth(int val);

  /**
   * @brief Set the Console Start Row object
   * 
   * @param val The start row
   */
	void setConsoleStartRow(int val);

  /**
   * @brief Set current game time
   * 
   * @param val The time representation in seconds
   */
	void setGameTime(int val);

  /**
   * @brief Set the Player Data
   * 
   * @param val Currently active player list
   */
	void setPlayerDataList(std::vector<Player>& val);
private:
  /**
   * @brief Current game mode
   */
	GameMode mGameMode = GameMode::eGameMode_Tron;

  /**
   * @brief Current game console width
   */
	int mConsoleWidth = 100;

  /**
   * @brief Game field start row
   */
	int mConsoleStartRow = 0;

  /**
   * @brief Current game time in seconds
   */
	int mGameTime = 0;

  /**
   * @brief Reference to current player list
   */
	std::vector<Player>* mPlayerDataList = nullptr;
};
#endif // INFORMATION_WINDOW_H__

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
