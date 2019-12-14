#pragma once

#include <locale>

/* for use _kbhit and _getch */
#ifdef _WIN32
#include <conio.h>

#elif __linux__

int _kbhit(void);
int _getch(void);

#endif

class sys
{
public:
	static void sleep(int time);

	static void consoleColorWhite();
	static void consoleColorRed();
	static void consoleColorBlue();
	static void consoleColorGreen();
	static void consoleColorGray();
	static void consoleColorYellow();

	static void hideCursor();
	static void showCursor();

	static void clear();
};