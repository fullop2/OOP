#pragma once
#include <string>

class View
{
private:
	// CONSTANT
	static const std::wstring topLine;
	static const std::wstring bottomLine;
	static const std::wstring bar;
	static const std::wstring block;
	static const std::wstring blankLine;

public:
	static void printBoardHeader();
	static void printBoardSide();
	static void printBlock();
	static void printBlank();
	static void printBoardFooter();
	static void printReturn();
	static void printBlankLine();

	static void printString(std::wstring);
	static void printCombo(unsigned combo);
	static void printScore(unsigned score);
};