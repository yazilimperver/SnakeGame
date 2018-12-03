/**
 * \file    Menu.h
 * \date    2018/12/02
 * \author  yazilimperver
 * \brief   
 * Copyright © 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef MENU_H__
#define MENU_H__

#include <MenuContent.h>

// TODO: Implement this using callbacks
class IMenuLister
{
public:
	virtual void menuItemSelected(const std::string& menuId) = 0;
};

/// Just enough menu :)
class Menu
{
public:
	Menu();
	MenuContent& getManagedMenu();
	void setStartPosition(int startRow, int centerCol);
	void setListener(IMenuLister* val);

	/// Calculate the menu metrics that will be used for display
	void calculateMenuMetrics();
	void update();
	void display();
	void reset();
private:
	void displayMenuItems();

	/// Update menu display
	bool mUpdateDisplay = true;

	/// Menu metrics that will be used for display
	int mWidth = 0;
	int mStartColumn = 0;

	int mCenterColumn = 0;
	int mStartRow = 0;

	/// The menu that will be managed
	MenuContent mManagedMenu;

	/// Currently active menu
	MenuContent* mActiveMenu = nullptr;

	/// Menu listener
	IMenuLister* mListener = nullptr;
};

#endif // MENU_H__

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
