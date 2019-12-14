#pragma once

#include <array>
#include <vector>
#include <unordered_set>

class ColorSet;
class Block;
class Polyomino;
class BlockManager;

using std::unordered_set;
using std::vector;
using std::array;

const int START_H = 3;
const int START_W = 0;

const int W = 6;
const int H = 12 + START_H + 1;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

typedef ColorSet* LPCOLORSET;
typedef Block* LPBLOCK;
typedef Polyomino* LPPOLYOMINO;
typedef array< array<LPBLOCK, W>, H> Board;

enum COLOR {
	RED, BLUE, GREEN, YELLOW, GRAY, COLOREND
};
enum POLYOMINO
{
	POLYOMINOFOLD, POLYOMINOTREE, POLYOMINOCROSS, POLYOMINOEND
};

int getRand(int max);
COLOR getColorRand();
POLYOMINO getPolyRand();

bool isSafe(int x, int y);
