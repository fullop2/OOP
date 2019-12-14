#include "BlockManager.h"
#include "ColorSet.h"
#include "Block.h"

BlockManager* BlockManager::pBlockManager = nullptr;

BlockManager::BlockManager()
{
	clearBoard();
}
BlockManager::~BlockManager()
{
	for (auto pBlock : blocks)
	{
		delete pBlock;
	}

	for (auto pColorSet : colorSets)
	{
		delete pColorSet;
	}
}

BlockManager& BlockManager::get()
{
	if (pBlockManager == nullptr) { // lazy instantiation
		pBlockManager = new BlockManager();
	}
	return *pBlockManager;
}

const Board& BlockManager::getBoard() const 
{ 
	return board; 
}
const LPBLOCK BlockManager::getBlock(int x, int y) const 
{ 
	return board[y][x]; 
}
const unordered_set<LPBLOCK>& BlockManager::getBlocks()
{
	return blocks;
}
const unordered_set<LPCOLORSET>& BlockManager::getColorSets()
{
	return colorSets;
}

void BlockManager::setBlock(int x, int y, LPBLOCK pBlock)
{
	board[y][x] = pBlock;
}

void BlockManager::displayBlock(LPBLOCK pBlock)
{
	setBlock(pBlock->getX(), pBlock->getY(), pBlock);
}

LPCOLORSET BlockManager::newColorSet(COLOR color) 
{
	LPCOLORSET pColorSet = new ColorSet(color);
	colorSets.insert(pColorSet);
	return pColorSet;
}

const unordered_set<LPCOLORSET>::iterator BlockManager::removeColorSet(const LPCOLORSET pColorSet)
{
	const unordered_set<LPCOLORSET>::iterator& it = colorSets.erase(colorSets.find(pColorSet));
	delete pColorSet;
	return it;
}

LPBLOCK BlockManager::newBlock(COLOR color, int x, int y)
{
	LPBLOCK pBlock = new Block(color, x, y);
	blocks.insert(pBlock);
	setBlock(x, y, pBlock);
	return pBlock;
}
const unordered_set<LPBLOCK>::iterator BlockManager::removeBlock(LPBLOCK pBlock)
{
	setBlock(pBlock->getX(), pBlock->getY(), nullptr);
	const auto& it = blocks.erase(blocks.find(pBlock));
	delete pBlock;
	return it;
}

void BlockManager::clearBoard()
{
	for (auto& row : board)
	{
		for (auto& block : row)
			block = nullptr;
	}
	int i = 0;
}

void BlockManager::drawBoard()
{
	for (auto pBlock : blocks)
		displayBlock(pBlock);
}