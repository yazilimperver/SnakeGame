/**
 * \file    SnakeModeItem.h
 * \date    2018/12/09
 * \author  yazilimperver
 * \brief   
 * Copyright � 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef SNAKEMODEITEM_H__
#define SNAKEMODEITEM_H__

#include <windows.h>
#include <Color.h>

struct SnakeModeItem
{
	/// Is this item fruit or poison
	bool mIsFruit { true };

	/// The position of this item
	COORD mPosition{ 0, 0 };

	/// The impact
	int mImpact {1};

	/// The item representation
	char mData{ static_cast<char>(254) };

	/// The color data
	Color mBackColor{ Color::eColor_black };
	Color mFrontColor{ Color::eColor_green };
};

#endif // SNAKEMODEITEM_H__

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
