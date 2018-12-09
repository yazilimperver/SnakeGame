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
	snake.assignPlayer(mPlayers[0]);

	populateGameMenu();

	mFruitGenerator.setLevel(mLevel);
	mFruitGenerator.setSnakeItem(snake);
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

			static float gameTime = 0;
			gameTime += tickTime;

			if (gameTime > 1000)
			{
				mFruitGenerator.generateFruit();
				gameTime = 0;
			}
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
	else if (SnakeGameScreen::eGAME_SCREEN_MENU == mCurrentGameScreen)
	{
		mMainMenu.update();
	}
}

void ConsoleSnakeGame::display(float tickTime)
{
	if (SnakeGameScreen::eGAME_SCREEN_GAME == mCurrentGameScreen)
	{
		// Display fps at top right	
		setColor(Color::eColor_black, Color::eColor_green);
		moveCursor(90, 0);
		cout << "FPS : " << mLoopManager.getLastFPS() << "    ";

		// Display console info
		mConsoleInfo.displayConsoleInfo();
	}
	else if (SnakeGameScreen::eGAME_SCREEN_MENU == mCurrentGameScreen)
	{
		mMainMenu.display();
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
		if (SnakeGameScreen::eGAME_SCREEN_SPLASH == mCurrentGameScreen
			||
			SnakeGameScreen::eGAME_SCREEN_GAMEOVER == mCurrentGameScreen)
		{
			clearConsole();

			/// Set color
			setColor(Color::eColor_black, Color::eColor_green);
			LogoDisplayer::DisplaySnakeLogo();

			mMainMenu.reset();

			mCurrentGameScreen = SnakeGameScreen::eGAME_SCREEN_MENU;
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

			mFruitGenerator.generateFruit();
			mFruitGenerator.generateFruit();
			mFruitGenerator.generateFruit();
			mFruitGenerator.generateFruit();
			mFruitGenerator.generateFruit();
			mFruitGenerator.generateFruit();
			mFruitGenerator.generateFruit();
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
		displayCenteredText("Please Press Space Bar to return menu!", 126, 36);

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
		this->switchToGameScreen(SnakeGameScreen::eGAME_SCREEN_MENU);
	}
}

void ConsoleSnakeGame::clearMenuBackground()
{
	clearConsole();

	/// Set color
	setColor(Color::eColor_black, Color::eColor_green);
	LogoDisplayer::DisplaySnakeLogo();
}

void ConsoleSnakeGame::menuItemSelected(const std::string& menuId)
{
	if ("QUIT" == menuId)
	{
		exit(0);
	}
	else if ("TRON MODE" == menuId)
	{
		/// Clear console
		clearConsole();

		/// Start game
		mGameMode = GameMode::eGameMode_Tron;
		switchToGameScreen(SnakeGameScreen::eGAME_SCREEN_GAME);
	}
	else if ("SNAKE MODE" == menuId)
	{
		/// Clear console
		clearConsole();

		/// Start game
		mGameMode = GameMode::eGameMode_Snake;
		switchToGameScreen(SnakeGameScreen::eGAME_SCREEN_GAME);
	}
	// Colors
	else if ("RED" == menuId)
	{
		mPlayers[0].GetPlayerData().mPlayerColor = Color::eColor_red;
	}
	else if ("GREEN" == menuId)
	{
		mPlayers[0].GetPlayerData().mPlayerColor = Color::eColor_green;
	}
	else if ("BLUE" == menuId)
	{
		mPlayers[0].GetPlayerData().mPlayerColor = Color::eColor_blue;
	}
	else if ("CYAN" == menuId)
	{
		mPlayers[0].GetPlayerData().mPlayerColor = Color::eColor_cyan;
	}
	else if ("YELLOW" == menuId)
	{
		mPlayers[0].GetPlayerData().mPlayerColor = Color::eColor_yellow;
	}
	else if ("PURPLE" == menuId)
	{
		mPlayers[0].GetPlayerData().mPlayerColor = Color::eColor_purple;
	}
	else if ("GRAY" == menuId)
	{
		mPlayers[0].GetPlayerData().mPlayerColor = Color::eColor_gray;
	}
	else if ("WHITE" == menuId)
	{
		mPlayers[0].GetPlayerData().mPlayerColor = Color::eColor_white;
	}
	else if (menuId.find('=') != menuId.npos)
	{
		mPlayers[0].GetPlayerData().mName = menuId.substr(menuId.find('=') + 1);
	}
}

void ConsoleSnakeGame::prepareGameScreen()
{
	/// First display level (order is important for initialization)
	mLevel.display();

	/// Provide snake initial position
	snake.initialize(ConsoleCellData{ {10, 10}, '@', Color::eColor_blue, Color::eColor_black });

	/// Update snake according to game mode
	snake.setTronMode(mGameMode == GameMode::eGameMode_Tron?true:false);

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

void ConsoleSnakeGame::populateGameMenu()
{
	// Menu initialization
	MenuContent& topMenu = mMainMenu.getManagedMenu();
	topMenu.mTitle = "~ MAIN MENU ~";
	topMenu.mParent = nullptr;
	topMenu.mSelectedItem = 0;
	topMenu.mItems.push_back(MenuContent{ "SINGLE PLAYER", 0, false, &topMenu });
	topMenu.mItems.push_back(MenuContent{ "MULTI PLAYER", 0, false, &topMenu });
	topMenu.mItems.push_back(MenuContent{ "OPTIONS", 0, false, &topMenu });
	topMenu.mItems.push_back(MenuContent{ "QUIT", 0, false, &topMenu });

	auto& singlePlayerMenu = topMenu.mItems[0];
	singlePlayerMenu.mItems.push_back(MenuContent{ "TRON MODE", 0, false, &singlePlayerMenu });
	singlePlayerMenu.mItems.push_back(MenuContent{ "SNAKE MODE", 0, false, &singlePlayerMenu });
	
	auto& optionsMenu = topMenu.mItems[2];
	optionsMenu.mItems.push_back(MenuContent{ "UPDATE YOUR NAME", 0, false, &optionsMenu });
	
	auto& nameMenu = optionsMenu.mItems[0];
	nameMenu.mIsInputField = true;
	nameMenu.mItems.push_back(MenuContent{ "               ", 0, false, &optionsMenu });

	auto& nameInputMenu = nameMenu.mItems[0];
	optionsMenu.mItems.push_back(MenuContent{ "UPDATE YOUR COLOR", 0, false, &optionsMenu });

	auto& colorMenu = optionsMenu.mItems[1];
	colorMenu.mItems.push_back(MenuContent{ "RED", 0, false, &optionsMenu });
	colorMenu.mItems.push_back(MenuContent{ "GREEN", 0, false, &optionsMenu });
	colorMenu.mItems.push_back(MenuContent{ "BLUE", 0, false, &optionsMenu });
	colorMenu.mItems.push_back(MenuContent{ "CYAN", 0, false, &optionsMenu });
	colorMenu.mItems.push_back(MenuContent{ "YELLOW", 0, false, &optionsMenu });
	colorMenu.mItems.push_back(MenuContent{ "PURPLE", 0, false, &optionsMenu });
	colorMenu.mItems.push_back(MenuContent{ "GRAY", 0, false, &optionsMenu });
	colorMenu.mItems.push_back(MenuContent{ "WHITE", 0, false, &optionsMenu });
	
	mMainMenu.setStartPosition(16, 60);
	mMainMenu.calculateMenuMetrics();
	mMainMenu.setListener(this);
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
	
	/// Clear console
	clearConsole();
}

