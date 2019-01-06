/**
 * @fileConsoleUtil.h
 * @date2018/10/22
 * @authoryazilimperver
 * @brief 
 * Copyright (C) 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef CONSOLEUTIL_H__
#define CONSOLEUTIL_H__				

#include <Color.h>
#include <Windows.h>

 /**
* @brief Some common key codes used through game
*/
const int KEY_UP = 0x48;
const int KEY_DOWN = 0x50;
const int KEY_LEFT = 0x4b;
const int KEY_RIGHT = 0x4d;
const int KEY_BACKSPACE = 0x8;
const int KEY_ESCAPE = 0x1b;
const int KEY_RETURN = 0x0d;

/**
 * @brief Display some common information about current console
 * 
 */
extern void displayConsoleInfo();

/**
 * @brief Set active color of console which will affect all console items that will be displayed hereafter
 * 
 * @param colorBack The background color
 * @param colorFore The foreground color
 */
extern void setColor(Color colorBack, Color colorFore);

/**
 * @brief Move the cursor given coordinates
 * 
 * @param x The column of given coordinate
 * @param y The row of given coordinate
 */
extern void moveCursor(int x, int y);

/**
 * @brief Move the cursor given coordinates
 * 
 * @param pos The position that cursor will be moved
 */
extern void moveCursor(const COORD& pos);

/**
 * @brief Display given text at the center of given row (ypos) according to consolewidth.
 *The alignment also take text length into consideration.
 * @param messageThe message that will be displayed
 * @param consoleWidth The console width
 * @param ypos The message row
 */
extern void displayCenteredText(const char *message, int consoleWidth, int ypos);

/**
 * @brief Hide the console cursor
 * 
 */
extern void cursorHide();

/**
 * @brief Example keyboard handler
 * 
 */
extern void keyboardHandle();

/**
 * @brief Function that clear current console
 * 
 */
extern void clearConsole();

/**
 * @brief Get the console size information 
 * 
 * @param width The width of console
 * @param height The height of console
 */
extern void getConsoleInformation(int& width, int& height);

/**
 * @brief Display a table starting from provided topLeft position that have width/height size with corresponding colors
 * 
 * @param topLeftThe top left coordinate of table
 * @param widthThe width of table
 * @param height The height of table
 * @param colorBackThe background color of table
 * @param colorFront The foreground color of table
 * @param themeThe theme of table (which is reserved for future use)
 */
extern void displayTable(const COORD& topLeft, int width, int height, Color colorBack, Color colorFront, int theme);

/**
 * @brief Set current console size
 * 
 * @param WidthConsole width
 * @param Height Console height
 */
extern void setWindowSize(int Width, int Height);

/**
 * @brief Set the console window with respect to provided parameters
 * 
 * @param left The left coordinate of console window
 * @param topThe top coordinate of console window
 * @param widthThe width of console window
 * @param height The height of console window
 */
extern void setConsoleInformation(short left, short top, short width, short height);

/**
 * @brief Get input from user in a non-blocking manner
 * 
 * @return int The integer representation of obtained char
 * Returns -1 if no input is provided
 */
extern int getNonBlockingChar();

/**
 * @brief A Mersenne Twister algorithm which gives you good tradeoff between randoness and speed.
 * 
 * @param low The lower bound of numbers that will be generated
 * @param high The uppoer bound of numbers that will be generated
 * @return int The generated number
 */
extern int generateRandromNumber(int low, int high);
#endif // CONSOLEUTIL_H__

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