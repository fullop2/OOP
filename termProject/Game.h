#pragma once
#include "stdafx.h"
#include "System/time.h"

class Game
{
private:

	LPPOLYOMINO currentPolyomino;
	bool canMove;

	gametime lastUpdatedTime;

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

	void update();
public:
	Game();
	~Game();
	void init();
};

