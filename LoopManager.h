/**
 * @fileLoopManager.h
 * @date2018/10/22
 * @authoryazilimperver
 * @brief The loopmanagement class. The different loop management approachs are illustrated through this game. Currently, fifth approach is employed for this game.
 * 			For more details. Check out the corresponding blog post: http://www.yazilimperver.com/index.php/2018/10/24/oyun-donguleri-ornek-kodlar/
 * Copyright (C) 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef LOOPMANAGER_H__
#define LOOPMANAGER_H__

/**
 * @brief The base class for applications that will be managed by loop manager
 * 
 */
class IApplication
{
public:
	
	/**
	 * @brief The display entry point for our game which will perform all drawing
	 * 
	 * @param tickTime: The time provided by loop manager in miliseconds
	 */
	virtual void display(float tickTime) = 0;
	/**
	 * @brief The update entry point for our game which will perform all physics and game mechanics
	 * 
	 * @param tickTime: The time provided by loop manager in miliseconds
	 */
	virtual void update(float tickTime) = 0;
};

/**
 * @brief This class is responsible for management of application loop through display and game mechanic update methods. The approaches
 *described in http://www.yazilimperver.com/index.php/2018/10/24/oyun-donguleri-ornek-kodlar/ are implemented.
 */
class LoopManager
{
public:
	/**
	 * @brief Start loop management and assigned application
	 * 
	 */
	void run();
	
	/**
	 * @brief Get the last measured FPS
	 * 
	 * @return int The FPS value
	 */
	int getLastFPS() const;

	/**
	 * @brief Set the Application to be managed by loop manager
	 * 
	 * @param val 
	 */
	void setApplicationToRun(IApplication* val);
protected:

	/**
	 * @brief 1th loop approach
	 * Brute force. Use everything you have :) 
	 * 
	 */
	void loopApproach1();

	/**
	 * @brief 2nd loop approach
	 * Fix FPS
	 * 
	 */
	void loopApproach2();

	/**
	 * @brief 3rd loop approach
	 * Variable FPS 
	 * 
	 */
	void loopApproach3();

	/**
	 * @brief 4rd loop approach
	 * Constant Game Speed with Max FPS
	 * 
	 */
	void loopApproach4Approach1();

	/**
	 * @brief 5th loop approach 
	 * 
	 */
	void loopApproach4Approach2();
	void loopApproach5();

	/**
	 * @brief Perform FPS reporting activities
	 * 
	 * @param elapsedTime Last loop time in miliseconds
	 */
	void reportStatistics(float elapsedTime);

	/**
	 * @brief Is application/game currently running
	 * 
	 */
	bool mIsGameRunning = true;

	/**
	 * @brief Last calculated FPS
	 * 
	 */
	int lastFPS = 0;

	/**
	 * @brief Reporting flag
	 * 
	 */
	bool enableConsolePrint = false;

	/**
	 * @brief Reporting interval in miliseconds
	 * 
	 */
	float reportTime = 1000.0F;

	/**
	 * @brief Accumulated time in miliseconds for reporting
	 * 
	 */
	float accumulatedTime = 0.0F;

	/**
	 * @brief Last display count for given report interval
	 * 
	 */
	int displayCount = 0;

	/**
	 * @brief Last update count for given report interval
	 * 
	 */
	int updateCount = 0;

	/**
	 * @brief Last tick count for given report interval
	 * 
	 */
	int tickCount = 0;

	/**
	 * @brief The application that will be managed by loop manager
	 * 
	 */
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

