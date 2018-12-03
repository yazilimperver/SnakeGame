/**
 * \file    ConsoleCellItem.h
 * \date    2018/10/21
 * \author  yazilimperver
 * \brief   
 * Copyright © 2018, <yazilimpervergs@gmail.com>
 */
#ifndef CONSOLECELLITEM_H__
#define CONSOLECELLITEM_H__

#include <ConsoleCellData.h>
#include <ConsoleLevel.h>

class ConsoleCellItem
{
public:				  
	ConsoleCellItem(ConsoleLevel& level, const ConsoleCellData& initialCellInfo);

	/// Display the corresponding cell item in given position
	void display();
	void displayPrevious();

	/// Move the cell item to given coordinate and return cell to previous state
	/// In case of first move no previous state update will be performed
	void moveTo(const COORD& newCoord);

	/// Return the corresponding cell item data
	ConsoleCellData& getCellItemData();

	ConsoleCellItem &operator =(const ConsoleCellItem & newItem);
protected:

	void printCellData(const ConsoleCellData& cellData);

	// level representation on which movable item will travel
	ConsoleLevel& mLevel;

	/// Previous console data which will be use in case of movement
	ConsoleCellData mPreviousCellItem;

	/// Console cell item data
	ConsoleCellData mCellItemData;
};

#endif // CONSOLECELLITEM_H__

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