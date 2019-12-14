#include "sys.h"


#ifdef _WIN32
#include <Windows.h>

#elif __linux__
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <fcntl.h>

#else
#error "Unknown compiler"

#endif

#ifdef _WIN32

void sys::sleep(int milliseconds)
{
	Sleep(milliseconds);
}

void sys::consoleColorWhite()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
}
void sys::consoleColorRed()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
}
void sys::consoleColorBlue()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
void sys::consoleColorGreen()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}
void sys::consoleColorYellow()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
}
void sys::consoleColorGray()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
}

void sys::hideCursor()
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
void sys::showCursor()
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = 1;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void sys::clear()
{
	COORD pos = { 0,0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

#elif __linux__

void sys::sleep(int milliseconds)
{
	usleep(milliseconds * 1000);
}

void sys::consoleColorWhite()
{
	wprintf(L"%c[0m", 27);
}
void sys::consoleColorRed()
{
	wprintf(L"%c[1;31m", 27);
}
void sys::consoleColorBlue()
{
	wprintf(L"%c[1;34m", 27);
}
void sys::consoleColorGreen()
{
	wprintf(L"%c[1;32m", 27);
}
/* comment : Linux's gray is so dark, replace it with purple */
void sys::consoleColorGray()
{
	wprintf(L"%c[1;35m", 27);
}
void sys::consoleColorYellow()
{
	wprintf(L"%c[1;33m", 27);
}
void sys::hideCursor()
{
	system("setterm -cursor off");
}

void sys::showCursor()
{
	system("setterm -cursor on");
}

void sys::clear()
{
	system("clear");
}

#endif

#ifdef __linux__
/* open source kbhit, getch */
int _kbhit(void)
{
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if (ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}

	return 0;
}

int _getch(void) {
	int ch;
	struct termios buf, save;
	tcgetattr(0, &save);
	buf = save;
	buf.c_lflag &= ~(ICANON | ECHO);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &buf);
	ch = getchar();
	tcsetattr(0, TCSAFLUSH, &save);
	return ch;
}
#endif