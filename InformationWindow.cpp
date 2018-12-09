#include <InformationWindow.h>
#include <ConsoleUtil.h>
#include <iostream>

using namespace std;
using namespace std::chrono_literals;

void InformationWindow::displayCommonConsoleInfo()
{
	// Display joined players and corresponding scores
	// Display items that can be eat
	displayTable(COORD{ 0, (short)mConsoleStartRow }, mConsoleWidth, 10, Color::eColor_darkblue, Color::eColor_green, 0);

	// Display items
	setColor(Color::eColor_black, Color::eColor_green);
	displayCenteredText("~~Information Console~~", mConsoleWidth, mConsoleStartRow + 1);

	// Display game mode
	moveCursor(COORD{1, static_cast<short>(mConsoleStartRow + 2) });

	setColor(Color::eColor_black, Color::eColor_darkgreen);
	cout << "Game Mode: ";

	setColor(Color::eColor_black, Color::eColor_green);
	switch (mGameMode)
	{
	case GameMode::eGameMode_Snake:
		cout << "SNAKE";
		break;
	default:
	case GameMode::eGameMode_Tron:
		cout << "TRON";
		break;
	}


	// Display player information
	moveCursor(COORD{ 1, static_cast<short>(mConsoleStartRow + 4) });
	setColor(Color::eColor_black, Color::eColor_darkgreen);
	cout << "Player Count: ";

	setColor(Color::eColor_black, Color::eColor_green);
	if (nullptr != mPlayerDataList)
	{
		cout << mPlayerDataList->size();
	}
	else
	{
		cout << "0";
	}

	this->displayConsoleInfo();
}

void InformationWindow::displayConsoleInfo()
{
	short currentRow = static_cast<short>(mConsoleStartRow + 3);

	// Display game duration	
	moveCursor(COORD{ 1,  currentRow });
	setColor(Color::eColor_black, Color::eColor_darkgreen);
	cout << "Game Duration: ";

	setColor(Color::eColor_black, Color::eColor_green);
	cout << mGameTime << " sec";

	if (nullptr != mPlayerDataList)
	{
		currentRow++;
		moveCursor(COORD{ 1,  currentRow });

		for (auto& player:*mPlayerDataList)
		{
			setColor(Color::eColor_black, player.GetPlayerData().mPlayerColor);

			// Display players and their score
			// TODO: Wrap player informations
			printf("%s (%02d) - Score: <%05d>", player.GetPlayerData().mName.c_str(), player.GetPlayerData().mPlayerId, player.GetPlayerData().mScore);
		}
	}
}

GameMode InformationWindow::getGameMode() const
{
	return mGameMode;
}

void InformationWindow::setGameMode(GameMode val)
{
	mGameMode = val;
}

void InformationWindow::setConsoleWidth(int val)
{
	mConsoleWidth = val;
}

void InformationWindow::setConsoleStartRow(int val)
{
	mConsoleStartRow = val;
}

void InformationWindow::setPlayerDataList(std::vector<Player>& val)
{
	mPlayerDataList = &val;
}

void InformationWindow::setGameTime(int val)
{
	mGameTime = val;
}
