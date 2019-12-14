#pragma once
#include "../stdafx.h"

/* template cannot separate from declaration */
// friend of Polyomino

class PolyominoFactory
{
private:
	template <typename PolyType>
	static bool valid(int x, int y);

	PolyominoFactory();
public:
	static bool createPolyomino(POLYOMINO type, int baseX, int baseY, LPPOLYOMINO* ppPolyomino);
};
