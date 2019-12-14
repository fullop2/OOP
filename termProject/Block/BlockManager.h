#pragma once
#include "../stdafx.h"

/*
BlockManager
allocate and delete block and color set

*/
class BlockManager
{
private:
	BlockManager();
	~BlockManager();

	Board board;						// game board
	unordered_set<LPCOLORSET> colorSets;// sets of block which stuck in same color
	unordered_set<LPBLOCK> blocks;
	static BlockManager* pBlockManager;	// singleton this


	void displayBlock(LPBLOCK pBlock);
public:
	static BlockManager& get();

	const Board& getBoard() const;
	const LPBLOCK getBlock(int x, int y) const;
	void setBlock(int x, int y, LPBLOCK pBlock);
	const unordered_set<LPCOLORSET>& getColorSets();
	const unordered_set<LPBLOCK>& getBlocks();

	LPCOLORSET newColorSet(COLOR color);
	const unordered_set<LPCOLORSET>::iterator removeColorSet(const LPCOLORSET pColorSet);

	LPBLOCK newBlock(COLOR color, int x, int y);
	const unordered_set<LPBLOCK>::iterator removeBlock(const LPBLOCK pBlock);

	void clearBoard();
	void drawBoard();
};

