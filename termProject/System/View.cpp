#include "View.h"
#include <iostream>
#include <iomanip>

const std::wstring View::topLine{ L" \u250c\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510" };
const std::wstring View::bottomLine{ L" \u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518" };
const std::wstring View::bar{ L" \u2502" };
const std::wstring View::block{ L" \u25cf" };
const std::wstring View::blankLine{ L"                            \n" };

void View::printBoardHeader()
{
	std::wcout << topLine;
}
void View::printBoardSide()
{
	std::wcout << bar;
}
void View::printReturn()
{
	std::wcout << std::endl;
}
void View::printBlock()
{
	std::wcout << block;
}
void View::printBlank()
{
	std::wcout << L"  ";
}
void View::printBoardFooter()
{
	std::wcout << bottomLine;
}

void View::printCombo(unsigned combo)
{
	std::wcout << std::setw(2) << combo << L" Combo! ";
}

void View::printScore(unsigned score)
{
	auto prev = std::wcout.fill(L'0');
	std::wcout << " ";
	std::wcout.width(9);
	std::wcout << score;
	std::wcout.fill(prev);
}
void View::printBlankLine()
{
	std::wcout << blankLine;
}

void View::printString(std::wstring string)
{
	std::wcout << string;
}