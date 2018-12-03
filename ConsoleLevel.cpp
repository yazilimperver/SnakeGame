#include <ConsoleLevel.h>
#include <ConsoleUtil.h>

#include <iostream>
    							 
ConsoleLevel::ConsoleLevel()
{
	// Create mMap
	mLevelMap.resize(mHeight);
	
	for (auto &it : mLevelMap)
	{
		it.resize(mWidth, 
				  ConsoleCellData{ {0, 0}, 0, Color::eColor_black, Color::eColor_black });
	}
}

void ConsoleLevel::getLevelBorders(RECT& border)
{
	border.left = mLeftOffset;
	border.top = mTopOffset;
	border.right = mWidth - mRightOffset;
	border.bottom = mHeight - mBottomOffset;
}

int ConsoleLevel::getWidth()
{
	return mWidth;
}

int ConsoleLevel::getHeight()
{
	return mHeight;
}

void ConsoleLevel::load()
{
	// Prepare level layout
	for (int y = 0; y < mHeight; y++)
	{
		for (int x = 0; x < mWidth; x++)
		{
			// Assign position
			mLevelMap[y][x].mPosition.X = x;
			mLevelMap[y][x].mPosition.Y = y;

			// Fill level
			if (y == 0)
				mLevelMap[y][x].mCellContent = EMPTY;
			else if (x == 0)
			{
				if (y == (mTopOffset - 2))
				{
					mLevelMap[y][x].mCellContent = 201;
				}
				else if (y == (mHeight - mBottomOffset + 1))
				{
					mLevelMap[y][x].mCellContent = 200;
				}
				else
					mLevelMap[y][x].mCellContent = 186;
			}
			else if (x == mWidth - 1)
			{
				if (y == (mTopOffset - 2))
				{
					mLevelMap[y][x].mCellContent = 187;
				}
				else if (y == (mHeight - mBottomOffset + 1))
				{
					mLevelMap[y][x].mCellContent = 188;
				}
				else
					mLevelMap[y][x].mCellContent = 186;
			}
			else if ((y == (mTopOffset-2))
				     ||
				     (y == (mHeight - mBottomOffset + 1)))
				mLevelMap[y][x].mCellContent = 205;
			else if (((x >= mLeftOffset && y >= mTopOffset) && (x < mWidth - mRightOffset && y < mHeight - mBottomOffset)))
				mLevelMap[y][x].mCellContent = SAND;
			else 
				mLevelMap[y][x].mCellContent = WALL;

			// Assign cell color
			switch (mLevelMap[y][x].mCellContent)
			{
			case EMPTY:
			{
				mLevelMap[y][x].mBackgroundColor = Color::eColor_black;
				mLevelMap[y][x].mForegroundColor = Color::eColor_black;
			} break;
			case SAND:
			{
				mLevelMap[y][x].mBackgroundColor = Color::eColor_black;
				mLevelMap[y][x].mForegroundColor = Color::eColor_black;
			} break;
			case WALL:
			{
				mLevelMap[y][x].mBackgroundColor = Color::eColor_black;
				mLevelMap[y][x].mForegroundColor = Color::eColor_darkgreen;
			}
			break;
			case 200:
			case 201:
			case 205:
			case 186:
			case 187:
			case 188:
			{
				mLevelMap[y][x].mBackgroundColor = Color::eColor_black;
				mLevelMap[y][x].mForegroundColor = Color::eColor_green;
			}
			break;
			}
		}
	}
}

void ConsoleLevel::display()
{				 
	for (int y = 0; y < mHeight; y++)
	{
		for (int x = 0; x < mWidth; x++)
		{
			moveCursor(x, y);

			setColor(mLevelMap[y][x].mBackgroundColor, mLevelMap[y][x].mForegroundColor);
			std::cout << (char)mLevelMap[y][x].mCellContent;
		}
	}
}

int ConsoleLevel::getCellData(int row, int col, Color& background, Color& foreground)
{
	foreground = mLevelMap[row][col].mForegroundColor;
	background = mLevelMap[row][col].mBackgroundColor;

	return mLevelMap[row][col].mCellContent;
}

void ConsoleLevel::getCellData(int row, int col, ConsoleCellData& cellData)
{
	cellData = mLevelMap[row][col];
}
