#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "ConsoleUtil.h"

void displayConsoleInfo()
{
	int width;
	int height;

	getConsoleInformation(width, height);
	std::cout << "Current console width and height are: " << width << " ," << height << '\n';
}

void setColor(Color colorBack, Color colorFore)
{
	int back = 0;
	int colorBackInt = static_cast<int>(colorBack);

	if (colorBackInt & 1) back |= BACKGROUND_BLUE;
	if (colorBackInt & 2) back |= BACKGROUND_GREEN;
	if (colorBackInt & 4) back |= BACKGROUND_RED;
	if (colorBackInt & 8) back |= BACKGROUND_INTENSITY;

	int fore = 0;
	int colorForeInt = static_cast<int>(colorFore);
	if (colorForeInt & 1) fore |= FOREGROUND_BLUE;
	if (colorForeInt & 2) fore |= FOREGROUND_GREEN;
	if (colorForeInt & 4) fore |= FOREGROUND_RED;
	if (colorForeInt & 8) fore |= FOREGROUND_INTENSITY;
	
	// Get the Win32 handle representing standard output.
	// This generally only has to be done once, so we make it static.
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hOut, back | fore);
}

void clearConsole()
{
	setColor(Color::eColor_black, Color::eColor_black);

	// Get the Win32 handle representing standard output.
	// This generally only has to be done once, so we make it static.
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD topLeft = { 0, 0 };

	// std::cout uses a buffer to batch writes to the underlying console.
	// We need to flush that to the console because we@re circumventing
	// std::cout entirely; after we clear the console, we don@t want
	// stale buffered text to randomly be written out.
	std::cout.flush();

	// Figure out the current width and height of the console window
	if (!GetConsoleScreenBufferInfo(hOut, &csbi)) 
	{
		// TODO: Handle failure!
		abort();
	}
	DWORD length = csbi.dwSize.X * csbi.dwSize.Y;

	DWORD written;

	// Flood-fill the console with spaces to clear it
	FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);

	// Reset the attributes of every character to the default.
	// This clears all background color formatting, if any.
	FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);

	// Move the cursor back to the top left for the next sequence of writes
	SetConsoleCursorPosition(hOut, topLeft);
}

void moveCursor(const COORD& pos)
{
	// Get the Win32 handle representing standard output.
	// This generally only has to be done once, so we make it static.
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(hOut, pos);
}

void moveCursor(int x, int y)
{
	COORD point;
	point.X = x;
	point.Y = y;
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, point);
}

void displayCenteredText(const char *message, int consoleWidth, int ypos)
{
	size_t len = strlen(message);
	if (len > 0)
	{
		size_t xpos = (consoleWidth - len) / 2;
		moveCursor(static_cast<int>(xpos), static_cast<int>(ypos));
		printf(message);
	}
}  

void cursorHide()
{
	HANDLE hwnd;
	hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;

	info.bVisible = 0;
	info.dwSize = 1;

	SetConsoleCursorInfo(hwnd, &info);
}

void keyboardHandle()
{
	bool exit = false;
	int key = _getch();
	
	switch (key)
	{
		case KEY_LEFT: ; break;
		case KEY_RIGHT: ; break;
		case KEY_UP: ; break;
		case KEY_DOWN: ; break;
		case KEY_RETURN: ; break;
	}

	if (key == KEY_ESCAPE) 
		exit = true;
}

void getConsoleInformation(int& width, int& height)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD consoleInfo = GetLargestConsoleWindowSize(hConsole);

	width = consoleInfo.X;
	height = consoleInfo.Y;
}

void displayTable(const COORD& topLeft, int width, int height, Color colorBack, Color colorFront, int theme)
{
	setColor(colorBack, colorFront);
	moveCursor(topLeft);

	// top left corner
	std::cout << static_cast<char>(218);

	// top side
	for (int i = 1; i < width - 1; i++)
	{
		std::cout << static_cast<char>(196);
	}

	// top right corner
	std::cout << static_cast<char>(191);

	COORD cursor = topLeft;
	cursor.Y++;

	for (int i = 1; i < height - 1; i++)
	{
		moveCursor(cursor);
		std::cout << static_cast<char>(179);
		cursor.X = topLeft.X + width - 1;

		moveCursor(cursor);
		std::cout << static_cast<char>(179);

		cursor.X = topLeft.X;
		cursor.Y++;
	}

	cursor = topLeft;
	cursor.Y = topLeft.Y + height-1;
	moveCursor(cursor);

	// bottom left corner
	std::cout << static_cast<char>(192);

	// bottom side
	for (int i = 1; i < width - 1; i++)
	{
		std::cout << static_cast<char>(196);
	}

	// bottom right corner
	std::cout << static_cast<char>(217);
}

void setWindowSize(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
}

void setConsoleInformation(short left, short top, short width, short height)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT rect = { left, top, width, height};
	BOOL result = SetConsoleWindowInfo(hConsole, TRUE, &rect);
}

int getNonBlockingChar()
{
	if (_kbhit())
		return _getch();
	else
		return -1;
}