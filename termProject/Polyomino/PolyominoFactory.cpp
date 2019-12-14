#include "PolyominoFactory.h"
#include "Polyomino.h"
#include "../Block/BlockManager.h"



bool PolyominoFactory::createPolyomino(POLYOMINO type, int baseX, int baseY, LPPOLYOMINO * ppPolyomino)
{
	if (type == POLYOMINOTREE)
	{
		*ppPolyomino = new PolyominoTree(baseX, baseY, getColorRand(), getColorRand(), getColorRand());
	}
	else if (type == POLYOMINOFOLD)
	{
		*ppPolyomino = new PolyominoFold(baseX, baseY, getColorRand(), getColorRand(), getColorRand());
	}
	else if (type == POLYOMINOCROSS)
	{
		*ppPolyomino = new PolyominoCross(baseX, baseY, getColorRand(), getColorRand(), getColorRand(), getColorRand(), getColorRand());
	}
	else {
		return false;
	}
	return true;
}
