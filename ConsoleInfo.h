/**
 * \file    ConsoleInfo.h
 * \date    2018/12/01
 * \author  yazilimperver
 * \brief   Responsible for displaying information about current game
 * Copyright © 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef CONSOLEINFO_H__
#define CONSOLEINFO_H__

#include <GameMode.h>
#include <Player.h>
#include <vector>
#include <chrono>

class ConsoleInfo
{
public:
	/// This function display information that does not change during game
	void displayCommonConsoleInfo();

	/// This function display information that change during game
	void displayConsoleInfo();

	/// Game mode and other game data
	GameMode getGameMode() const;
	void setGameMode(GameMode val);
	void setConsoleWidth(int val);
	void setConsoleStartRow(int val);
	void setGameTime(int val);

	void setPlayerDataList(std::vector<Player>& val);
private:
	GameMode mGameMode = GameMode::eGameMode_Tron;
	int mConsoleWidth = 100;
	int mConsoleStartRow = 0;
	int mGameTime = 0;
	std::vector<Player>* mPlayerDataList = nullptr;
};

#endif // CONSOLEINFO_H__

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
