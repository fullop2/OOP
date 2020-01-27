#include "ColorSet.h"
#include "Block.h"
#include "BlockManager.h"

ColorSet::ColorSet(COLOR color)
	:color(color)
{
}

const std::size_t ColorSet::size() const {return blocks.size();}
const COLOR ColorSet::getColor() const { return color; }
unordered_set<LPBLOCK>& ColorSet::getBlocks() { return blocks; }

void ColorSet::addBlock(LPBLOCK pBlock)
{
	blocks.insert(pBlock);
}
unordered_set<LPBLOCK>::const_iterator ColorSet::removeBlock(const LPBLOCK pBlock)
{
	return blocks.erase(blocks.find(pBlock));
}

void ColorSet::explodeBlocks()
{
	/* find gray color set (if not gray) */
	if (getColor() != COLOR::GRAY)
	{
		for (auto pBlock : getBlocks())
		{
			for (int i = 0; i < 4; i++)
			{
				int cx = pBlock->getX() + dx[i];
				int cy = pBlock->getY() + dy[i];

				if (isSafe(cx, cy))
				{
					auto neighborBlock = BlockManager::get().getBlock(cx, cy);
					if (neighborBlock != nullptr)
					{
						/* add all neighbor gray block to current color set */
						auto neighborColorSet = neighborBlock->getColorSet();
						if (neighborColorSet != this && neighborColorSet != nullptr && neighborColorSet->getColor() == COLOR::GRAY)
						{
							auto itBlock = neighborColorSet->getBlocks().begin();
							while (itBlock != neighborColorSet->getBlocks().end()) {
								(*itBlock)->setColorSet(nullptr);
								addBlock(*itBlock);
								itBlock = neighborColorSet->removeBlock(*itBlock);
							}
							BlockManager::get().removeColorSet(neighborColorSet);

						}
					}
				}
			}
		}
	}

	/* delete this color set blocks */
	auto itBlock = blocks.begin();
	while (itBlock != blocks.end())
	{
		BlockManager::get().removeBlock(*itBlock);
		itBlock = blocks.erase(itBlock);
	}
}