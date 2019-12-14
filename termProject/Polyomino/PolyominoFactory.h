#pragma once
#include "../stdafx.h"

/* template cannot separate from declaration */
// friend of Polyomino

class PolyominoFactory
{
	PolyominoFactory();
public:
	static bool createPolyomino(POLYOMINO type, int baseX, int baseY, LPPOLYOMINO* ppPolyomino);
};
