#include <ConsoleSnakeGame.h>	 
#include <ConsoleUtil.h>		
#include <LoopManager.h>  
#include <iostream>				  
#include <thread>
#include <cstdlib>

#include <LogoDisplayer.h>
#include <conio.h>		   
#include <chrono>

using namespace std::chrono_literals;
using namespace std;

ConsoleSnakeGame::ConsoleSnakeGame(const LoopManager& loopManager) 
	: snake{ mLevel, ConsoleCellData{ {10, 10}, '@', Color::eColor_blue, Color::eColor_black} }
, mLoopManager(loopManager)
{

}

void ConsoleSnakeGame::initialize()
{
	// Level initialization
	mLevel.load();
	
	// Player initialization
	mPlayers.push_back(Player{});

	// Console info initialization
	mConsoleStartRow = mLevel.getHeight();
	mConsoleInfo.setConsoleStartRow(mConsoleStartRow);
	mConsoleInfo.setConsoleWidth(mLevel.getWidth());
	mConsoleInfo.setGameMode(GameMode::eGameMode_Tron);
	mConsoleInfo.setPlayerDataList(mPlayers);

	mGameStartClock = chrono::high_resolution_clock::now();
	mCurrentGameTime = 0;
}

void ConsoleSnakeGame::update(float tickTime)
{
	if ( SnakeGameScreen::eGAME_SCREEN_GAME == mCurrentGameScreen)
	{
		if (false == snake.isGameOver())
		{
			snake.update(tickTime);

			// Update time
			mCurrentGameTime = chrono::duration_cast<chrono::duration<int>>(chrono::high_resolution_clock::now() - mGameStartClock).count();
			
			// Update console info time per second
			mConsoleInfo.setGameTime(mCurrentGameTime);

			// Update player scores
			this->updateScores();
		}
		else
		{
			this->switchToGameScreen(SnakeGameScreen::eGAME_SCREEN_GAMEOVER);
		}
	}
	else if (SnakeGameScreen::eGAME_SCREEN_GAMEOVER == mCurrentGameScreen)
	{
		this->displayGameOver(tickTime);
	}
}

bool ConsoleSnakeGame::switchToGameScreen(SnakeGameScreen newScreen)
{
	bool isSwitchSuccess = false;

	switch (newScreen)
	{
	case SnakeGameScreen::eGAME_SCREEN_LOGO:
		if (SnakeGameScreen::eGAME_SCREEN_INITIAL == mCurrentGameScreen)
		{
			mCurrentGameScreen = SnakeGameScreen::eGAME_SCREEN_LOGO;
			this->displayLogo();
			isSwitchSuccess = true;
		}
		break;
	case SnakeGameScreen::eGAME_SCREEN_SPLASH:
		if (SnakeGameScreen::eGAME_SCREEN_LOGO == mCurrentGameScreen)
		{
			mCurrentGameScreen = SnakeGameScreen::eGAME_SCREEN_SPLASH;
			this->displayGameLogo();
			isSwitchSuccess = true;
		}
		break;
	case SnakeGameScreen::eGAME_SCREEN_MENU:
		if (SnakeGameScreen::eGAME_SCREEN_SPLASH == mCurrentGameScreen)
		{
			mCurrentGameScreen = SnakeGameScreen::eGAME_SCREEN_MENU;

			/// TODO
			isSwitchSuccess = true;
		}
		break;
	case SnakeGameScreen::eGAME_SCREEN_GAME:
		if (SnakeGameScreen::eGAME_SCREEN_MENU == mCurrentGameScreen
			||
			SnakeGameScreen::eGAME_SCREEN_SPLASH == mCurrentGameScreen)
		{
			mCurrentGameScreen = SnakeGameScreen::eGAME_SCREEN_GAME;
			this->prepareGameScreen();
			mGameStartClock = chrono::high_resolution_clock::now();
			isSwitchSuccess = true;
		}
		else if (SnakeGameScreen::eGAME_SCREEN_GAMEOVER == mCurrentGameScreen)
		{
			mCurrentGameScreen = SnakeGameScreen::eGAME_SCREEN_GAME;
			clearConsole();
			this->prepareGameScreen();
			mGameStartClock = chrono::high_resolution_clock::now();
			isSwitchSuccess = true;
		}
		break;
	case SnakeGameScreen::eGAME_SCREEN_GAMEOVER:
		if (SnakeGameScreen::eGAME_SCREEN_GAME == mCurrentGameScreen)
		{
			mCurrentGameScreen = SnakeGameScreen::eGAME_SCREEN_GAMEOVER;
			//this->displayGameOver();
			isSwitchSuccess = true;
		}
		break;
	default:
		break;
	}

	if (false == isSwitchSuccess)
	{
		setColor(Color::eColor_red, Color::eColor_yellow);
		displayCenteredText("Unexpected game screen change request!", 126, 38);
	}

	return isSwitchSuccess;
}

void ConsoleSnakeGame::displayGameOver(float tickTime)
{	/// Set color
	setColor(Color::eColor_yellow, Color::eColor_red);	
	
	static float elapsed = 0.0F;
	static bool displayText = true;
	
	elapsed += tickTime;
	
	if (elapsed > 1000)
	{
		displayText = !displayText;
		elapsed = 0;
	}

	if (true == displayText)
	{
		displayCenteredText("GAME OVER!", 126, 15);
		displayCenteredText("Please Press Space Bar to restart menu!", 126, 36);

		// TODO: Also there are alive players!
		if (mPlayers.size() > 1)
		{
			displayCenteredText("Please Press Enter to continue watch game!", 126, 37);
		}
	}
	else
	{
		displayCenteredText("          ", 126, 15);
	}

	if (getNonBlockingChar() == ' ')
	{
		elapsed = 0.0F;
		displayText = true;

		// restart game
		this->switchToGameScreen(SnakeGameScreen::eGAME_SCREEN_GAME);
	}
}

void ConsoleSnakeGame::prepareGameScreen()
{
	/// First display level (order is important for initialization)
	/// TODO: add layer management
	mLevel.display();

	/// Provide snake initial position
	snake.initialize(ConsoleCellData{ {10, 10}, '@', Color::eColor_blue, Color::eColor_black });

	/// Print player
	snake.display();

	/// Display Title
	setColor(Color::eColor_red, Color::eColor_yellow);
	displayCenteredText("Multi-player Snake Game (c) 2018", 120, 0);

	/// Display information console
	mConsoleInfo.setGameMode(mGameMode);
	mConsoleInfo.displayCommonConsoleInfo();
}

void ConsoleSnakeGame::updateScores()
{
	for (auto& player : mPlayers)
	{
		if (auto& playerData = player.GetPlayerData(); true == playerData.mIsAlive)
		{
			// if tron mode is active then update score
			if (GameMode::eGameMode_Tron == mGameMode)
			{
				playerData.mScore = mCurrentGameTime;
			}
		}
	}
}

void ConsoleSnakeGame::display()
{
	//snake.display();
}

void ConsoleSnakeGame::displayLogo()
{
	/// Set color
	setColor(Color::eColor_black, Color::eColor_white);

	/// Display logo
	LogoDisplayer::DisplayYazilimPerverLogoText1();

	/// Wait a little bit
	this_thread::sleep_for(2s);

	/// Clear console
	clearConsole();
}

void ConsoleSnakeGame::displayGameLogo()
{
	/// Set color
	setColor(Color::eColor_black, Color::eColor_green);

	LogoDisplayer::DisplaySnakeLogo();
	this_thread::sleep_for(2s);

	setColor(Color::eColor_black, Color::eColor_yellow);

	auto previous(chrono::high_resolution_clock::now());
	chrono::time_point<chrono::high_resolution_clock> current;
	float elapsed = 0.0F;


	bool displayText = true;
	do
	{
		current = chrono::high_resolution_clock::now();
		elapsed = chrono::duration_cast<chrono::duration<float, milli>>(current - previous).count();

		if (elapsed > 1000)
		{
			displayText = !displayText;
			previous = current;
		}

		if (true == displayText)
		{
			displayCenteredText("Please Press Space Bar to Continue!", 126, 37);
		}
		else
		{
			displayCenteredText("                                        ", 126, 37);
		}
	} while (getNonBlockingChar() != ' ');
	
	// Populate menu
	displayMainMenu();


	/// Clear console
	clearConsole();
}

void ConsoleSnakeGame::displayMainMenu()
{
	// TODO: We may populate this from json/xml
	MenuContent& topMenu = mMainMenu.getManagedMenu();
	topMenu.mTitle = "~ MAIN MENU ~";
	topMenu.mParent = nullptr;
	topMenu.mSelectedItem = 0;
	topMenu.mItems.push_back(MenuContent{ "SINGLE PLAYER", 0, &topMenu });
	topMenu.mItems.push_back(MenuContent{ "MULTI PLAYER", 0, &topMenu });
	topMenu.mItems.push_back(MenuContent{ "OPTIONS", 0, &topMenu });
	topMenu.mItems.push_back(MenuContent{ "QUIT", 0, &topMenu });

	mMainMenu.setStartPosition(16, 60);
	mMainMenu.calculateMenuMetrics();
	mMainMenu.display();

	bool menuActive = true;

	constexpr int KEY_UP = 0x48;
	constexpr int KEY_DOWN = 0x50;

	// Menu management :)
	while (menuActive)
	{
		int input = _getch();

		if (input == KEY_UP)
		{
			topMenu.mSelectedItem = (topMenu.mSelectedItem + topMenu.mItems.size() - 1) % topMenu.mItems.size();
			mMainMenu.display();
		}
		else if (input == KEY_DOWN)
		{
			topMenu.mSelectedItem = (topMenu.mSelectedItem + 1) % topMenu.mItems.size();
			mMainMenu.display();
		}
		else if (input == ' ')
		{
			// start game
			if (0 == topMenu.mSelectedItem)
			{
				menuActive = false;
			}
			else if (3 == topMenu.mSelectedItem)
			{
				exit(0);
			}
		}
	}
}

void ConsoleSnakeGame::display(float tickTime)
{
	// Display fps at top right	
	setColor(Color::eColor_black, Color::eColor_green);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 90, 0 });
	cout << "FPS : " << mLoopManager.getLastFPS() << "    ";

	// Display console info
	mConsoleInfo.displayConsoleInfo();
}

