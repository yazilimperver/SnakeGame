/**
 * \file    ConsoleLevel.h
 * \date    2018/10/22
 * \author  yazilimperver
 * \brief   
 * Copyright © 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef CONSOLELEVEL_H__
#define CONSOLELEVEL_H__

#include <vector>		   
#include <Color.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <ConsoleCellData.h>

 // Level constants
constexpr int EMPTY = 32;
constexpr int SAND = 0;
constexpr int WALL = 219;

class ConsoleLevel
{
public:
	ConsoleLevel();
	void load();
	void display();
	int getCellData(int row, int col, Color& background, Color& foreground);
	void getCellData(int row, int col, ConsoleCellData& cellData);
	void getLevelBorders(RECT& border);

	int getWidth();
	int getHeight();
private:   
	/// The level size
	int mWidth = 120;
	int mHeight = 30;

	/// The boundary level offsets
	int mLeftOffset = 2;
	int mTopOffset = 3;
	int mRightOffset = 2;
	int mBottomOffset = 2;

	/// The level data
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

