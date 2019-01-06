/**
 * @file    ConsoleSnakeGame.h
 * @date    2018/10/22
 * @author  yazilimperver
 * @brief   Main game class which is responsible for management of game. The game is composed of screens which are used to group each game activity by SnakeGameScreen enumaration.
 * 		    This can be considered as a simple state machine that will be used to manage game scenes.
 * Copyright � 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef CONSOLESNAKEGAME_H__
#define CONSOLESNAKEGAME_H__

#include <ConsoleLevel.h>
#include <InformationWindow.h>
#include <SnakeGameScreen.h>
#include <Snake.h>
#include <Player.h>
#include <LoopManager.h>
#include <Menu.h>
#include <MidiPlayer.h>
#include <SnakeModeItemGenerator.h>

/**
 * @brief This class is the main class for overall game it implements IApplication for loopmanagement and IMenuListener for menu events.
 * 
 */
class ConsoleSnakeGame
	: public IApplication
	, public IMenuListener
{
public:
	/**
	 * @brief Construct a new Console Snake Game object which accepts loopmanager
	 * 
	 * @param loopManager 
	 */
	ConsoleSnakeGame(const LoopManager& loopManager);
	~ConsoleSnakeGame();

	/**
	 * @brief Perform one time game initialization
	 * 
	 */
	void initialize();	

	/**
	 * @brief The display entry point for our game which will perform all drawing
	 * 
	 * @param tickTime: The time provided by loop manager in miliseconds
	 */
	void display(float tickTime);

	/**
	 * @brief The update entry point for our game which will perform all physics and game mechanics
	 * 
	 * @param tickTime: The time provided by loop manager in miliseconds
	 */
	void update(float tickTime);

	/**
	 * @brief Switch to provided game screen. Chekout file brief or blog post for more information
	 * 
	 * @param newScreen: The new game screen
	 * @return true : Switch performed successfully
	 * @return false : Switch failed
	 */
	bool switchToGameScreen(SnakeGameScreen newScreen);

protected:
	void displayGameOver(float tickTime);
	void populateGameMenu();
	void displayLogo();
	void displayGameLogo();

	void prepareGameScreen();
	void updateScores();

	virtual void clearMenuBackground() override;
	virtual void menuItemSelected(const std::string& menuId) override;

	/**
	 * @brief The midi player that will be used for music
	 * 
	 */
	MidiPlayer mMidiPlayer;

	/**
	 * @brief Registered players
	 * 
	 */
	std::vector<std::shared_ptr<Player>> mRegisteredPlayers;

	/**
	 * @brief Current game screen
	 * 
	 */
	SnakeGameScreen mCurrentGameScreen = SnakeGameScreen::eGAME_SCREEN_INITIAL;

	/**
	 * @brief Snake game board
	 * 
	 */
	ConsoleLevel mLevel;

	/**
	 * @brief Console info
	 * 
	 */
	InformationWindow mConsoleInfo;

	/**
	 * @brief Current game mode
	 * 
	 */
	GameMode mGameMode = GameMode::eGameMode_Tron;

	/**
	 * @brief The console width
	 * 
	 */
	int mWidth;
	
	/**
	 * @brief The console height
	 * 
	 */
	int mHeight;

	/**
	 * @brief Info console start row (y)
	 * 
	 */
	int mConsoleStartRow;

	/**
	 * @brief The snake object
	 * 
	 */
	Snake snake;

	/**
	 * @brief The main menu of game object
	 * 
	 */
	Menu mMainMenu;

	/**
	 * @brief The list of active players
	 * 
	 */
	std::vector<Player> mPlayers;

	/**
	 * @brief Loop manager that we associate our application
	 * 
	 */
	const LoopManager& mLoopManager;

	/**
	 * @brief Fruit/poison generator for snake mode games
	 * 
	 */
	SnakeModeItemGenerator mFruitGenerator;

	/**
	 * @brief Current game time in miliseconds
	 * 
	 */
	int mCurrentGameTime = 0;

	/**
	 * @brief The timer that will be used to mark start of game
	 * 
	 */
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
