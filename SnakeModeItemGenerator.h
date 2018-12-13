/**
 * \file    SnakeModeItemGenerator.h
 * \date    2018/12/09
 * \author  yazilimperver
 * \brief   
 * Copyright © 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef SNAKEMODEITEMGENERATOR_H__
#define SNAKEMODEITEMGENERATOR_H__

#include <vector>
#include <SnakeModeItem.h>

class ConsoleLevel;
class Snake;

/// This class is responsible for generating fruits and poisons for snake mode game as well as generation of fruits when a snake died.
class SnakeModeItemGenerator
{
public:
	void setLevel(ConsoleLevel& val);
	void setSnakeItem(const Snake& val);

	/// Check cell content and return false if no item exist and true if item exist with corresponding content
	bool isCellContainItem(const COORD& coordToCheck, SnakeModeItem& cellContet);

	/// Remove corresponding snake item
	void removeSnakeItem(const COORD& coordToCheck);

	/// Generate random fruit
	void generateFruit();

	/// The tick function of fruit generator
	void update(float tickTime);

	/// Will be called to free fruits and reset timer
	void reset();
private:

	bool isCollideWithSnake(const COORD& coordToCheck);
	bool isItemLocatedAtPosition(const COORD& coordToCheck);

	/// Reference to game level
	ConsoleLevel* mLevel{ nullptr };

	/// The active snake item
	const Snake* mSnakeItem{ nullptr };

	/// Time since last fruit is generated in milliseconds
	float mAccumulatedTime{ 0.0F };

	/// Max fruit count
	const size_t mMaxAllowedFruitCount{ 5 };

	/// Currently active fruits
	std::vector<SnakeModeItem> mFruits;

	/// Fruit generation period in milliseconds
	const float mFruitGenerationPeriod{ 5000 };
};

#endif // SNAKEMODEITEMGENERATOR_H__

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
