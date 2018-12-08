/**
 * \file    ConsoleSnakeGame.h
 * \date    2018/10/22
 * \author  yazilimperver
 * \brief   
 * Copyright © 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef CONSOLESNAKEGAME_H__
#define CONSOLESNAKEGAME_H__

#include <ConsoleLevel.h>
#include <ConsoleInfo.h>
#include <SnakeGameScreen.h>
#include <SnakeItem.h>
#include <Player.h>
#include <LoopManager.h>
#include <Menu.h>

class ConsoleSnakeGame
	: public IApplication
	, public IMenuLister
{
public:
	ConsoleSnakeGame(const LoopManager& loopManager);

	/// One time initializations
	void initialize();	
	void display(float tickTime);
	void update(float tickTime);

	bool switchToGameScreen(SnakeGameScreen newScreen);

	void displayGameOver(float tickTime);
protected:
	void populateGameMenu();
	void displayLogo();
	void displayGameLogo();

	void prepareGameScreen();
	void updateScores();

	virtual void clearMenuBackground() override;
	virtual void menuItemSelected(const std::string& menuId) override;

	/// Registered players
	std::vector<std::shared_ptr<Player>> mRegisteredPlayers;

	/// Current game screen
	SnakeGameScreen mCurrentGameScreen = SnakeGameScreen::eGAME_SCREEN_INITIAL;

	/// Snake game board
	ConsoleLevel mLevel;

	/// Console info
	ConsoleInfo mConsoleInfo;

	/// Current game mode
	GameMode mGameMode = GameMode::eGameMode_Tron;

	/// General parameters
	int mWidth;
	int mHeight;

	/// Info console parameters
	int mConsoleStartRow;

	/// Snake head
	/// MovableItem snake;
	SnakeItem snake;

	/// The main menu of game
	Menu mMainMenu;

	/// Active players
	std::vector<Player> mPlayers;

	/// Loop manager that we associate our application
	const LoopManager& mLoopManager;

	/// Game start indicator
	int mCurrentGameTime = 0;
	std::chrono::time_point<std::chrono::high_resolution_clock> mGameStartClock;
};

#endif // CONSOLESNAKEGAME_H__

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
