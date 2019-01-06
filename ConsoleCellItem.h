/**
 * @fileConsoleCellItem.h
 * @date2018/10/21
 * @authoryazilimperver
 * @brief 
 * Copyright (C) 2018, <yazilimpervergs@gmail.com>
 */
#ifndef CONSOLECELLITEM_H__
#define CONSOLECELLITEM_H__

#include <ConsoleCellData.h>
#include <ConsoleLevel.h>

/**
 * @brief Class that will be used to print a cell data on console level which
 * is used to cover console screen. This class remember the last value of a console
 * cell and update it to previous value when a movement like operation is performed.
 */
class ConsoleCellItem
{
public:		
	/**
	 * @brief Construct a new Console Cell Item object
	 * 
	 * @param level Reference to level which is used to manage overall console screen
	 * @param initialCellInfo Initial cell data that will be used for given cell
	 */
	ConsoleCellItem(ConsoleLevel& level, const ConsoleCellData& initialCellInfo);

	/**
	 * @brief Display the corresponding cell item in current position
	 * 
	 */
	void display();

	/**
	 * @brief Display the previously stored value at corresponding cell item
	 * 
	 */
	void displayPrevious();

	/**
	 * @brief Move the cell item to provided coordinate and return cell to previous state
	 * In case of first move no previous state update will be performed
	 * 
	 * @param newCoord The coordinate that cell item will be moved
	 */
	void moveTo(const COORD& newCoord);

	/**
	 * @brief Get a reference to the Cell Item Data object
	 * 
	 * @return ConsoleCellData& Reference to corresponding cell item data
	 */
	ConsoleCellData& getCellItemData();

	/**
	 * @brief Assignment operator
	 * 
	 * @param newItem 
	 * @return ConsoleCellItem& 
	 */
	ConsoleCellItem &operator =(const ConsoleCellItem & newItem);
protected:

	/**
	 * @brief Print provided cell data according to cellData
	 * 
	 * @param cellData Provided cell data
	 */
	void printCellData(const ConsoleCellData& cellData);

	/**
	 * @brief Console level representation on which movable item will travel
	 * 
	 */
	ConsoleLevel& mLevel;

	/**
	 * @brief Previous console data which will be used in case of movement
	 * 
	 */
	ConsoleCellData mPreviousCellItem;

	/**
	 * @brief Console cell item data that will be managed by this class
	 * 
	 */
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