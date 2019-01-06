/**
 * @fileConsoleLevel.h
 * @date2018/10/22
 * @authoryazilimperver
 * @brief 
 * Copyright (C) 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef CONSOLELEVEL_H__
#define CONSOLELEVEL_H__

#include <vector>		 
#include <Color.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <ConsoleCellData.h>

 /**
* @brief Some level content data charrepresentations
* 
*/
constexpr int EMPTY = 32;
constexpr int SAND = 0;
constexpr int WALL = 219;
constexpr int FRUIT = 254;

/**
 * @brief This class is responsible for managing console screen for game
 */
class ConsoleLevel
{
public:
	ConsoleLevel();

	/**
	 * @brief Initiate game level with corresponding content
	 */
	void load();

	/**
	 * @brief Display currently prepared game level data
	 * 
	 */
	void display();

	/**
	 * @brief Get corresponding cell data through parameters according to provided parameters 
	 * 
	 * @param row Cell row coordinate <y>
	 * @param col Cell column coordinate <x>
	 * @param background The background color of given level cell
	 * @param foreground The foreground color of given level cell
	 * @return int return the int value of corresponding cell
	 */
	int getCellData(int row, int col, Color& background, Color& foreground);
	
	/**
	 * @brief Get corresponding cell data through parameters according to provided parameters 
	 * 
	 * @param row Cell row coordinate <y>
	 * @param col Cell column coordinate <x>
	 * @param cellData The cell content of given coordinate
	 */
	void getCellData(int row, int col, ConsoleCellData& cellData);

	/**
	 * @brief Get bundary of game level
	 * 
	 * @param border The returned border as parameter
	 */
	void getLevelBorders(RECT& border);

	/**
	 * @brief Get the Width of game level
	 * 
	 * @return int The level width
	 */
	int getWidth();

	/**
	 * @brief Get the Height of game level
	 * 
	 * @return int The level height
	 */
	int getHeight();
private: 
	/**
	 * @brief The level size parameters
	 * 
	 */
	int mWidth = 120;
	int mHeight = 30;

	/**
	 * @brief The boundary level offsets
	 * 
	 */
	int mLeftOffset = 2;
	int mTopOffset = 3;
	int mRightOffset = 2;
	int mBottomOffset = 2;

	/**
	 * @brief The level data hold in a matrix
	 * 
	 */
	std::vector< std::vector<ConsoleCellData>> mLevelMap;
};

#endif // CONSOLELEVEL_H__

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

