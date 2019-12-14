#include "Block.h"
#include "ColorSet.h"
#include "BlockManager.h"
#include "../ScoreManager.h"


bool Block::cmp(const LPBLOCK lhs, const LPBLOCK rhs)
{
	return lhs->y > rhs->y;
}

Block::Block(COLOR color, int x, int y)
	:x(x), y(y), color(color), placed(false), pColorSet(nullptr)
{
	BlockManager::get().setBlock(x, y, this);
}

Block::~Block() {
	ScoreManager::get().addExplodedColorData(color);
	propagation();
}

void Block::propagation()
{
	for (int i = y-1; i >= START_H; i--) {
		auto upperBlock = BlockManager::get().getBlock(x,i);
		if (upperBlock != nullptr && getColorSet() != upperBlock->getColorSet())
		{
			auto upperBlockColorSet = upperBlock->getColorSet();
			if (upperBlockColorSet != nullptr && upperBlockColorSet->size() < 4)
			{
				upperBlockColorSet->removeBlock(upperBlock);
				upperBlock->setColorSet(nullptr);
				upperBlock->setPlaced(false);
			}
			else if (upperBlockColorSet == nullptr)
			{
				upperBlock->setPlaced(false);
			}
		}
	}
}

// getter and setter : inline
COLOR Block::getColor() const { return color; }
const int Block::getX() const { return x; }
const int Block::getY() const { return y; }
const LPCOLORSET Block::getColorSet() const { return pColorSet; }
const bool Block::isPlaced() const { return placed; }

void Block::setColorSet(LPCOLORSET pColorSet)
{
	this->pColorSet = pColorSet;
	if(pColorSet != nullptr)
		pColorSet->addBlock(this);
}
void Block::setPlaced(bool placed) {
	this->placed = placed;
}
void Block::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
	BlockManager::get().setBlock(x, y, this);
}


void Block::jointColorSet()
{
	if (pColorSet == nullptr)
	{
		setColorSet(BlockManager::get().newColorSet(color));
	}

	for (int i = 0; i < 4; i++)
	{
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (isSafe(cx, cy))
		{
			auto pNextBlock = BlockManager::get().getBlock(cx, cy);
			if (pNextBlock != nullptr && color == pNextBlock->getColor())
			{
				auto nextColorSet = pNextBlock->getColorSet();
				if (nextColorSet != nullptr)
				{
					if (nextColorSet != pColorSet)
					{
						auto nextColorSetBlocks = nextColorSet->getBlocks();
						for (auto pBlock : nextColorSetBlocks)
						{
							pBlock->setColorSet(pColorSet);
						}
						BlockManager::get().removeColorSet(nextColorSet);
					}
				}
				else 
				{
					pNextBlock->setColorSet(pColorSet);
					pNextBlock->jointColorSet();
				}
			}
		}
	}
}

bool Block::movable(int cx, int cy)
{
	if (isSafe(cx, cy))
	{
		auto pBlock = BlockManager::get().getBlock(cx, cy);
		if (pBlock == nullptr || !pBlock->isPlaced() && !this->isPlaced())
		{
			return true;
		}
	}
	return false;
}
bool Block::canDown()
{
	return movable(x, y + 1);
}
bool Block::canLeft()
{
	return movable(x - 1, y);
}
bool Block::canRight()
{
	return movable(x + 1, y);
}
void Block::down()
{
	if (canDown())
	{
		if (BlockManager::get().getBlock(x, y) == this)
			BlockManager::get().setBlock(x, y, nullptr);
		setPosition(x,++y);
	}
	else
	{
		placed = true;
	}
}
void Block::left()
{
	if (canLeft()) 
	{ 
		if (BlockManager::get().getBlock(x, y) == this)
			BlockManager::get().setBlock(x, y, nullptr);
		setPosition(--x, y);
	}
}
void Block::right()
{
	if (canRight()) 
	{ 
		if (BlockManager::get().getBlock(x, y) == this)
			BlockManager::get().setBlock(x, y, nullptr);
		setPosition(++x, y);
	}
}