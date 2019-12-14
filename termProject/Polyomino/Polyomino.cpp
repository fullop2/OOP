#include <algorithm>
#include "Polyomino.h"
#include "../Block/Block.h"
#include "../Block/BlockManager.h"
#include "../ScoreManager.h"
#include "../System/Input.h"

Polyomino::Polyomino(int x, int y) :x(x), y(y), rotateState(0) {}
Polyomino::~Polyomino() {}
const vector<LPBLOCK>& Polyomino::getBlocks() const {return blocks;}

bool Polyomino::allCanLeft()
{
	bool canLeft = true;

	for (auto pBlock : blocks)
	{
		if (pBlock->isPlaced() || !pBlock->canLeft()) {
			canLeft = false;
			break;
		}
	}
	return canLeft;
}
bool Polyomino::allCanRight()
{
	bool canRight = true;

	for (auto pBlock : blocks)
	{
		if (pBlock->isPlaced() || !pBlock->canRight()) {
			canRight = false;
			break;
		}
	}
	return canRight;
}
bool Polyomino::allCanDown()
{
	bool canDown = true;

	for (auto pBlock : blocks)
	{
		if (pBlock->isPlaced() || !pBlock->canDown()) {
			canDown = false;
			break;
		}
	}
	return canDown;
}
void Polyomino::drop()
{
	auto lowestDropCount = H;
	for (auto pBlock : blocks)
	{
		auto lowestCurrent = 0;
		while (!pBlock->isPlaced())
		{
			pBlock->down();
			lowestCurrent++;
		}
		if (lowestDropCount > lowestCurrent)
			lowestDropCount = lowestCurrent;
	}
	ScoreManager::get().dropByDropKey(lowestDropCount);
}

void Polyomino::update()
{
	if (Input::getKeyDown() == 'h')
	{
		if(rotate())
			std::sort(blocks.begin(), blocks.end(), Block::cmp);
	}
	if (Input::getKeyDown() == 's' && allCanDown()) 
	{ 
		for(auto pBlock : blocks)
			if(!pBlock->isPlaced())
				pBlock->down(); 

		ScoreManager::get().dropByKeyDown();
	}
	else if (Input::getKeyDown() == 'a' && allCanLeft())
	{
		for (auto pBlock : blocks)
			if (!pBlock->isPlaced())
				pBlock->left(); 
	}
	else if (Input::getKeyDown() == 'd' && allCanRight())
	{
		for (auto pBlock : blocks)
			if (!pBlock->isPlaced())
				pBlock->right(); 
	}
	else if (Input::getKeyDown() == 'c')
	{
		drop();
	}
}
