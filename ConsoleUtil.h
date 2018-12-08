/**
 * \file    ConsoleUtil.h
 * \date    2018/10/22
 * \author  yazilimperver
 * \brief   
 * Copyright © 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef CONSOLEUTIL_H__
#define CONSOLEUTIL_H__				  

#include <Color.h>
#include <Windows.h>

 // Some common key codes
const int KEY_UP = 0x48;
const int KEY_DOWN = 0x50;
const int KEY_LEFT = 0x4b;
const int KEY_RIGHT = 0x4d;
const int KEY_BACKSPACE = 0x8;
const int KEY_ESCAPE = 0x1b;
const int KEY_RETURN = 0x0d;

extern void displayConsoleInfo();
extern void setColor(Color colorBack, Color colorFore);
extern void moveCursor(int x, int y);
extern void moveCursor(const COORD& pos);
extern void displayCenteredText(const char *message, int consoleWidth, int ypos);
extern void cursorHide();
extern void keyboardHandle();
extern void clearConsole();
extern void getConsoleInformation(int& width, int& height);
extern void displayTable(const COORD& topLeft, int width, int height, Color colorBack, Color colorFront, int theme);
extern void setWindowSize(int Width, int Height);
extern void setConsoleInformation(short left, short top, short width, short height);
// Returns -1 if no input is provided
extern int  getNonBlockingChar();
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