/**
 * \file    LoopManager.h
 * \date    2018/10/22
 * \author  yazilimperver
 * \brief   
 * Copyright © 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef LOOPMANAGER_H__
#define LOOPMANAGER_H__

class IApplication
{
public:
	virtual void display(float tickTime) = 0;
	virtual void update(float tickTime) = 0;
};

class LoopManager
{
public:
	void run();
	
	int getLastFPS() const;
	void setApplicationToRun(IApplication* val);
protected:

	// 1th loop approach
	// Brute force. Use everything you have :) 
	void loopApproach1();

	// 2nd loop approach
	// Fix FPS
	void loopApproach2();

	// 3rd loop approach
	// Variable FPS
	void loopApproach3();

	// 4rd loop approach
	// Constant Game Speed with Max FPS
	void loopApproach4Approach1();

	// 5th loop approach
	void loopApproach4Approach2();
	void loopApproach5();

	/// Perform reporting activities
	void reportStatistics(float elapsedTime);

	/// Check display and update methods
	void checkFunctionCallbacks();
	
	/// Is game running
	bool mIsGameRunning = true;

	/// Last calculated FPS
	int lastFPS = 0;

	// Reporting parameters
	bool enableConsolePrint = false;
	// 1 second
	float reportTime = 1000.0F;
	float accumulatedTime = 0.0F;
	int displayCount = 0;
	int updateCount = 0;
	int tickCount = 0;

	// Registered update and display functions
	IApplication* mApplicationToRun = nullptr;
};

#endif // LOOPMANAGER_H__

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

