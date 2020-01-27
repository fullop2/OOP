#pragma once
#include "../stdafx.h"

class ColorSet
{
private:
	friend BlockManager;

	COLOR color;
	unordered_set<LPBLOCK> blocks;

	explicit ColorSet(COLOR color);

public:

	const std::size_t size() const;
	const COLOR getColor() const;
	unordered_set<LPBLOCK>& getBlocks();

	void addBlock(const LPBLOCK pBlock);
	unordered_set<LPBLOCK>::const_iterator removeBlock(const LPBLOCK pBlock);
	void explodeBlocks();
};