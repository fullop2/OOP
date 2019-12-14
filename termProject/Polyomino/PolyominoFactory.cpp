#include "PolyominoFactory.h"
#include "Polyomino.h"
#include "../Block/BlockManager.h"

template <typename PolyType>
bool PolyominoFactory::valid(int x, int y)
{
	for (int i = 0; i < PolyType::BLOCK_COUNT; i++)
	{
		int nx = x + PolyType::blockPosX[i];
		int ny = y + PolyType::blockPosX[i];
		if (BlockManager::get().getBlock(nx, ny) != nullptr) {			
			return false;
		}
			
	}
	return true;
}

bool PolyominoFactory::createPolyomino(POLYOMINO type, int baseX, int baseY, LPPOLYOMINO * ppPolyomino)
{
	if (type == POLYOMINOTREE && valid<PolyominoTree>(baseX, baseY))
	{
		*ppPolyomino = new PolyominoTree(baseX, baseY, getColorRand(), getColorRand(), getColorRand());
	}
	else if (type == POLYOMINOFOLD && valid<PolyominoFold>(baseX, baseY))
	{
		*ppPolyomino = new PolyominoFold(baseX, baseY, getColorRand(), getColorRand(), getColorRand());
	}
	else if (type == POLYOMINOCROSS && valid<PolyominoCross>(baseX, baseY))
	{
		*ppPolyomino = new PolyominoCross(baseX, baseY, getColorRand(), getColorRand(), getColorRand(), getColorRand(), getColorRand());
	}
	else {
		return false;
	}
	return true;
}
