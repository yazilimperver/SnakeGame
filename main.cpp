#include <ConsoleUtil.h>
#include <LogoDisplayer.h>
#include <ConsoleSnakeGame.h>
#include <LoopManager.h>

#include <iostream>
#include <functional>
#include <thread>		
#include <conio.h>		 
#include <chrono>

#pragma comment(lib, "winmm.lib")

using namespace std::chrono_literals;
using namespace std;	 

int main()
{
	// Perform console resizing
	setWindowSize(121, 40);

	/// Hide cursor
	cursorHide();
	
	/// Loop manager instance
	LoopManager loopMgr;

	/// Snake game
	ConsoleSnakeGame snakeGame{ loopMgr };

	/// Perform initializations
	snakeGame.initialize();

	/// Initial logo
	snakeGame.switchToGameScreen(SnakeGameScreen::eGAME_SCREEN_LOGO);
												
	/// Snake logo			
	snakeGame.switchToGameScreen(SnakeGameScreen::eGAME_SCREEN_SPLASH);

	/// Snake game menu
	snakeGame.switchToGameScreen(SnakeGameScreen::eGAME_SCREEN_MENU);

	/// Start game
	loopMgr.setApplicationToRun(&snakeGame);
	loopMgr.run();
}
