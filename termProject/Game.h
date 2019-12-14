#pragma once
#include "stdafx.h"


class Game
{
private:

	LPPOLYOMINO currentPolyomino;
	LPPOLYOMINO nextPolyomino;

	bool canMove;

	static const int nextPolyominoX;
	static const int nextPolyominoY;


	void drawBoard();

	bool moveCurrentPolyomino();
	bool dropNotPlacedBlocks();
	bool explode();
	void jointColorSet();
	void render();
	bool asyncDelay(double delay);
	void syncDelay(double delay);
	bool newPolyomino();
	void asyncDropAll();

	void setConsoleColor(COLOR color);

	
public:
	Game();
	~Game();
	//void init();
	void update();
};

