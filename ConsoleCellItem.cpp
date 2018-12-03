#include <ConsoleCellItem.h>
#include <ConsoleUtil.h>
#include <iostream>

ConsoleCellItem::ConsoleCellItem(ConsoleLevel& level, const ConsoleCellData & initialCellInfo)
	: mLevel{ level }
	, mCellItemData{initialCellInfo}
{
	// Store previous cell information
	mPreviousCellItem = initialCellInfo;											
	mPreviousCellItem.mCellContent
		= mLevel.getCellData(initialCellInfo.mPosition.Y, initialCellInfo.mPosition.X,
			mPreviousCellItem.mBackgroundColor, mPreviousCellItem.mForegroundColor);
}

void ConsoleCellItem::display()
{		
	this->printCellData(mCellItemData);
}

void ConsoleCellItem::displayPrevious()
{
	this->printCellData(mPreviousCellItem);
}

ConsoleCellItem& ConsoleCellItem::operator =(const ConsoleCellItem & newItem)
{
	mPreviousCellItem = newItem.mPreviousCellItem;
	mLevel = newItem.mLevel;
	mCellItemData = newItem.mCellItemData;

	return *this;
}

void ConsoleCellItem::moveTo(const COORD & newCoord)
{										  
	// Print back previous cell data						   
	this->printCellData(mPreviousCellItem);

	// Store new position as previous one
	// To do so obtain information from corresponding level instance
	mPreviousCellItem.mPosition = newCoord;
	mPreviousCellItem.mCellContent 
		= mLevel.getCellData(newCoord.Y, newCoord.X, 
			mPreviousCellItem.mBackgroundColor, mPreviousCellItem.mForegroundColor);

	// Update current cell item position
	mCellItemData.mPosition = newCoord;

	// Display new cell item
	this->printCellData(mCellItemData);
}

ConsoleCellData & ConsoleCellItem::getCellItemData()
{
	return mCellItemData;
}

void ConsoleCellItem::printCellData(const ConsoleCellData& cellData)
{
	setColor(cellData.mBackgroundColor, cellData.mForegroundColor);

	// Move cursor to given position
	moveCursor(cellData.mPosition.X, cellData.mPosition.Y);

	// Print the corresponding cell content
	std::cout << (char)cellData.mCellContent;
}
