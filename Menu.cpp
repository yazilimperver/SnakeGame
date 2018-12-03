#include <Menu.h>
#include <algorithm>
#include <Color.h>
#include <ConsoleUtil.h>
#include <iostream>
#include <conio.h>

Menu::Menu()
{
	mActiveMenu = &mManagedMenu;
}

MenuContent& Menu::getManagedMenu()
{
	return mManagedMenu;
}

void Menu::reset()
{
	mActiveMenu = &mManagedMenu;
	mActiveMenu->mSelectedItem = 0;
	mUpdateDisplay = true;
	this->displayMenuItems();
}

void Menu::displayMenuItems()
{
	Color colorBack = Color::eColor_darkblue;
	Color colorFront = Color::eColor_blue;

	// Display current menu
	if (nullptr != mActiveMenu)
	{
		setColor(colorBack, colorFront);
		moveCursor(mStartColumn, mStartRow);

		// top left corner
		std::cout << static_cast<char>(201);

		// title top side line
		for (int i = 1; i < mWidth - 1; i++)
		{
			std::cout << static_cast<char>(205);
		}

		// top right corner
		std::cout << static_cast<char>(187);
		//////////////////////////////

		// Title
		COORD cursor{ static_cast<short>(mStartColumn), static_cast<short>(mStartRow)};
		cursor.Y++;
		moveCursor(mStartColumn, cursor.Y);

		std::string title(mWidth - 2, ' ');
		title.replace((mWidth - 2 - mActiveMenu->mTitle.size()) / 2, mActiveMenu->mTitle.size(), mActiveMenu->mTitle);

		std::cout << static_cast<char>(186) << title;
		moveCursor(mStartColumn + mWidth - 1, cursor.Y);
		std::cout << static_cast<char>(186);

		// title bottom side line
		cursor.Y++;
		moveCursor(mStartColumn, cursor.Y);
		std::cout << static_cast<char>(204);

		for (int i = 1; i < mWidth - 1; i++)
		{
			std::cout << static_cast<char>(205);
		}

		std::cout << static_cast<char>(185);
		//////////////////////////////

		// menu items		
		std::string baseMenuItem(mWidth - 2, ' ');
		baseMenuItem[1] = '(';
		baseMenuItem[3] = ')';

		std::string menuItem;

		for (int i = 0; i < mActiveMenu->mItems.size(); ++i)
		{
			cursor.Y++;
			moveCursor(mStartColumn, cursor.Y);

			std::cout << static_cast<char>(186);
			menuItem = baseMenuItem;
			menuItem.replace(5, mActiveMenu->mItems[i].mTitle.size(), mActiveMenu->mItems[i].mTitle);

			if (i == mActiveMenu->mSelectedItem)
			{
				menuItem[2] = '>';
			}

			std::cout << menuItem;

			moveCursor(mStartColumn + mWidth - 1, cursor.Y);
			std::cout << static_cast<char>(186);
		}
		//////////////////////////////

		cursor.Y++;
		moveCursor(mStartColumn, cursor.Y);

		// bottom left corner
		std::cout << static_cast<char>(200);

		// bottom side
		for (int i = 1; i < mWidth - 1; i++)
		{
			std::cout << static_cast<char>(205);
		}

		// bottom right corner
		std::cout << static_cast<char>(188);
	}
}

void Menu::setStartPosition(int startRow, int centerCol)
{
	mStartRow = startRow;
	mCenterColumn = centerCol;
}

void Menu::setListener(IMenuLister* val)
{
	mListener = val;
}

void Menu::calculateMenuMetrics()
{
	if (nullptr != mActiveMenu)
	{
		mWidth = 0;

		for (const auto& item : mActiveMenu->mItems)
		{
			if (int length = static_cast<int>(item.mTitle.size()); length > mWidth)
			{
				mWidth = length;
			}
		}

		// Now add size for other items (margin, parenthesizes)
		mWidth += 6;
		mWidth = std::max<int>(mWidth, static_cast<int>(mActiveMenu->mTitle.size())+ 2);
		mWidth += 2;

		// Other metrics
		mStartColumn = mCenterColumn - mWidth / 2;
	}
}

void Menu::update()
{
	if (nullptr != mActiveMenu)
	{
		int input = _getch();

		if (input == KEY_UP)
		{
			mActiveMenu->mSelectedItem
				= (mActiveMenu->mSelectedItem + static_cast<int>(mActiveMenu->mItems.size()) - 1) % static_cast<int>(mActiveMenu->mItems.size());
			mUpdateDisplay = true;
			this->displayMenuItems();
		}
		else if (input == KEY_DOWN)
		{
			mActiveMenu->mSelectedItem = (mActiveMenu->mSelectedItem + 1) % mActiveMenu->mItems.size();
			mUpdateDisplay = true;
			this->displayMenuItems();
		}
		else if (input == ' ')
		{
			if (nullptr != mListener)
			{
				mListener->menuItemSelected(mActiveMenu->mItems[mActiveMenu->mSelectedItem].mTitle);
			}
		}
	}
}

void Menu::display()
{
	if (true == mUpdateDisplay)
	{
		this->displayMenuItems();
		mUpdateDisplay = false;
	}
}
