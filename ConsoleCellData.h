/**
 * \file    ConsoleCellData.h
 * \date    2018/10/21
 * \author  yazilimperver
 * \brief   
 * Copyright © 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef CONSOLECELLDATA_H__
#define CONSOLECELLDATA_H__

#include <Color.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

constexpr int cNotAssisgned = -1;

struct ConsoleCellData
{								 
	/// The position of cell data
	COORD mPosition{ 0, 0 };

	/// The ascii cell content that will be displayed on console	
	int mCellContent = cNotAssisgned;

	/// The foreground color of corresponding cell
	Color mForegroundColor{ Color::eColor_white };

	/// The background color of corresponding cell
	Color mBackgroundColor{ Color::eColor_white };
};

#endif // CONSOLECELLDATA_H__

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
