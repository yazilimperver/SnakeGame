/**
 * @fileMenuContent.h
 * @date2018/12/02
 * @authoryazilimperver
 * @brief 
 * Copyright (C) 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef MENUCONTENT_H__
#define MENUCONTENT_H__

#include <string>
#include <vector>

/**
 * @brief This simple struct is responsible for holding all menu and sub menu content
 * 
 */
struct MenuContent
{
	/**
	 * @brief The title of current menu
	 * 
	 */
	std::string mTitle {"MENU"};

	/**
	 * @brief Is this menu item has input field
	 * 
	 */
	bool mIsInputField {false};

	/**
	 * @brief The index of currently selected child menu
	 * 
	 */
	int mSelectedItem {0};

	/**
	 * @brief Reference to parent menu (null in case of top menu)
	 * 
	 */
	MenuContent* mParent {nullptr};

	/**
	 * @brief Children menu items
	 * 
	 */
	std::vector<MenuContent> mItems;

	/**
	 * @brief The assignment operator for menu content stuff
	 * 
	 * @param rhs 
	 * @return MenuContent& 
	 */
	MenuContent& operator=(const MenuContent& rhs)
	{
		mTitle = rhs.mTitle;
		mIsInputField = rhs.mIsInputField;
		mSelectedItem = rhs.mSelectedItem;
		mParent = rhs.mParent;
		mItems = rhs.mItems;

		return *this;
	}
};

#endif // MENUCONTENT_H__

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
