#include "Polyomino.h"
#include "../Block/BlockManager.h"
#include "../Block/Block.h"

const int PolyominoFold::blockPosX[] = { -1,0,0 };
const int PolyominoFold::blockPosY[] = { 0,0,-1 };

const int PolyominoTree::blockPosX[] = { 0,0,0 };
const int PolyominoTree::blockPosY[] = { 0,-1,-2 };

const int PolyominoCross::blockPosX[] = { 0,-1,0,1,0 };
const int PolyominoCross::blockPosY[] = { 0,-1,-1,-1,-2 };

PolyominoFold::PolyominoFold(int x, int y, COLOR c1, COLOR c2, COLOR c3)
	: Polyomino(x, y)
{
	COLOR color[BLOCK_COUNT] = { c1,c2,c3 };
	for (int i = 0; i < BLOCK_COUNT; i++)
	{
		pBlock[i] = BlockManager::get().newBlock(color[i], x + blockPosX[i], y + blockPosY[i]);
		blocks.push_back(pBlock[i]);
	}
}

bool PolyominoFold::rotate()
{
	int cx = pBlock[1]->getX();
	int cy = pBlock[1]->getY();

	int prevRotState = (rotateState + 3) % 4;

	if (isSafe(cx + dx[rotateState], cy + dy[rotateState]) &&
		BlockManager::get().getBlock(cx + dx[rotateState], cy + dy[rotateState]) == nullptr)
	{
		BlockManager::get().setBlock(cx - dx[rotateState], cy - dy[rotateState], nullptr);
		pBlock[0]->setPosition(cx + dx[prevRotState], cy + dy[prevRotState]);
		pBlock[2]->setPosition(cx + dx[rotateState], cy + dy[rotateState]);
		rotateState = (rotateState + 1) % 4;

		return true;
	}
	else
	{
		return false;
	}
}

bool PolyominoFold::checkValid(int x, int y) {
	return pValid(x, y, BLOCK_COUNT, blockPosX, blockPosY);
}
void PolyominoFold::setPosition(int x, int y) {
	pSetPosition(x, y, BLOCK_COUNT, blockPosX, blockPosY);
}


PolyominoTree::PolyominoTree(int x, int y, COLOR c1, COLOR c2, COLOR c3)
	: Polyomino(x, y)
{
	COLOR color[BLOCK_COUNT] = { c1,c2,c3 };
	for (int i = 0; i < BLOCK_COUNT; i++)
	{
		pBlock[i] = BlockManager::get().newBlock(color[i], x + blockPosX[i], y + blockPosY[i]);
		blocks.push_back(pBlock[i]);
	}
}

bool PolyominoTree::rotate()
{
	int cx = pBlock[1]->getX();
	int cy = pBlock[1]->getY();

	int prevRotState = (rotateState + 3) % 4;

	if (isSafe(cx + dx[rotateState], cy + dy[rotateState]) && isSafe(cx - dx[rotateState], cy - dy[rotateState]) &&
		BlockManager::get().getBlock(cx + dx[rotateState], cy + dy[rotateState]) == nullptr &&
		BlockManager::get().getBlock(cx - dx[rotateState], cy - dy[rotateState]) == nullptr)
	{
		pBlock[0]->setPosition(cx - dx[rotateState], cy - dy[rotateState]);
		pBlock[2]->setPosition(cx + dx[rotateState], cy + dy[rotateState]);

		BlockManager::get().setBlock(cx - dx[prevRotState], cy - dy[prevRotState], nullptr);
		BlockManager::get().setBlock(cx + dx[prevRotState], cy + dy[prevRotState], nullptr);

		rotateState = (rotateState + 1) % 4;

		return true;
	}
	else
	{
		return false;
	}

}

bool PolyominoTree::checkValid(int x, int y) {
	return pValid(x, y, BLOCK_COUNT, blockPosX, blockPosY);
}
void PolyominoTree::setPosition(int x, int y) {
	pSetPosition(x, y, BLOCK_COUNT, blockPosX, blockPosY);
}

PolyominoCross::PolyominoCross(int x, int y, COLOR c1, COLOR c2, COLOR c3, COLOR c4, COLOR c5)
	: Polyomino(x, y)
{
	COLOR color[BLOCK_COUNT] = { c1,c2,c3,c4,c5 };
	for (int i = 0; i < BLOCK_COUNT; i++)
	{
		pBlock[i] = BlockManager::get().newBlock(color[i], x + blockPosX[i], y + blockPosY[i]);
		blocks.push_back(pBlock[i]);
	}
}

bool PolyominoCross::rotate()
{
	int cx = pBlock[2]->getX();
	int cy = pBlock[2]->getY();

	int allRotateState[] = {
		(rotateState + 2) % 4,
		(rotateState + 3) % 4,
		0, // dummy
		(rotateState + 1) % 4,
		(rotateState	) % 4,
	};
	rotateState = (rotateState + 1) % 4;

	for (int i = 0; i < 5; i++)
	{
		if (i != 2) { pBlock[i]->setPosition(cx + dx[allRotateState[i]], cy + dy[allRotateState[i]]); }
	}

	return true;
}

bool PolyominoCross::checkValid(int x, int y) {
	return pValid(x, y, BLOCK_COUNT, blockPosX, blockPosY);
}
void PolyominoCross::setPosition(int x, int y) {
	pSetPosition(x, y, BLOCK_COUNT, blockPosX, blockPosY);
}