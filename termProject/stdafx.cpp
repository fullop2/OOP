#include "stdafx.h"
#include <random>

std::random_device rn;
std::mt19937 mtRand(rn());

bool isSafe(int x, int y) {
	return (0 <= x && x < W) && (0 <= y && y < H);
}

int getRand(int max)
{
	return mtRand() % max;
}

COLOR getColorRand()
{
	return (COLOR)getRand(COLOR::COLOREND);
};

POLYOMINO getPolyRand()
{
	return (POLYOMINO)getRand(POLYOMINO::POLYOMINOEND);
};