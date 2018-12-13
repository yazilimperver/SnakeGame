#include <SnakeModeItemGenerator.h>
#include <ConsoleLevel.h>
#include <algorithm>
#include <ConsoleUtil.h>
#include <Snake.h>
#include <iostream>

void SnakeModeItemGenerator::setLevel(ConsoleLevel& val)
{
	mLevel = &val;
}

void SnakeModeItemGenerator::setSnakeItem(const Snake& val)
{
	mSnakeItem = &val;
}

bool SnakeModeItemGenerator::isCellContainItem(const COORD& coordToCheck, SnakeModeItem& cellContet)
{
	bool result = false;
	if (mFruits.size() > 0)
	{
		for (const auto& item : mFruits)
		{
			if (item.mPosition.X == coordToCheck.X
				&&
				item.mPosition.Y == coordToCheck.Y)
			{
				result = true;
				cellContet = item;
				break;
			}
		}
	}

	return result;
}

void SnakeModeItemGenerator::removeSnakeItem(const COORD& coordToCheck)
{
	if (mFruits.size() > 0)
	{
		// find corresponding fruit and remove it
		auto itr = std::find_if(mFruits.begin(), mFruits.end(),
			[&](const auto& val) { return val.mPosition.X == coordToCheck.X && val.mPosition.Y == coordToCheck.Y; });

		if (itr != mFruits.end())
		{
			// roll back level
			mFruits.erase(itr);

			// TODO: clearing corresponding level?
		}
	}
}

void SnakeModeItemGenerator::generateFruit()
{
	SnakeModeItem newItem;
	COORD newFruitCoord;
	RECT border;
	mLevel->getLevelBorders(border);

	int xRange = border.right - border.left;
	int yRange = border.bottom - border.top;

	// need to limit checks
	while (true)
	{
		// randomly generate coordinate
		newFruitCoord.X = border.left + generateRandromNumber(0, xRange - 1);
		newFruitCoord.Y = border.top + generateRandromNumber(0, yRange - 1);

		// check if any fruit is generated on this coord.
		if (false == isItemLocatedAtPosition(newFruitCoord)
			&&
			false == isCollideWithSnake(newFruitCoord))
		{
			// add this item to fruit list and print
			moveCursor(newFruitCoord);

			newItem.mPosition = newFruitCoord;
			setColor(newItem.mBackColor, newItem.mFrontColor);
			std::cout << newItem.mData;
			mFruits.emplace_back(newItem);

			break;
		}

		// otherwise generate other coordinates
	}
}

void SnakeModeItemGenerator::update(float tickTime)
{
	mAccumulatedTime += tickTime;

	if (mAccumulatedTime > mFruitGenerationPeriod
		&&
		mFruits.size() < mMaxAllowedFruitCount)
	{
		this->generateFruit();
		mAccumulatedTime = 0;
	}
}

void SnakeModeItemGenerator::reset()
{
	mFruits.clear();
	mAccumulatedTime = 0.0F;
}

bool SnakeModeItemGenerator::isCollideWithSnake(const COORD& coordToCheck)
{
	bool result = false;
	if (nullptr != mSnakeItem)
	{
		auto& body = mSnakeItem->getBody();
		auto itr = std::find_if(body.begin(), body.end(),
			[&](const auto& val) { return val.X == coordToCheck.X && val.Y == coordToCheck.Y; });

		if (itr!= body.end())
		{
			result = true;
		}
	}
	return result;
}

bool SnakeModeItemGenerator::isItemLocatedAtPosition(const COORD& coordToCheck)
{
	bool result = false;
	
	// find corresponding fruit and remove it
	auto itr = std::find_if(mFruits.begin(), mFruits.end(),
		[&](const auto& val) { return val.mPosition.X == coordToCheck.X && val.mPosition.Y == coordToCheck.Y; });

	if (itr != mFruits.end())
		result = true;

	return result;
}
