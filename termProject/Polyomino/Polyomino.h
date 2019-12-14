#pragma once
#include "../stdafx.h"

class PolyominoFactory;

class Polyomino
{
protected:

	int x, y;
	vector<LPBLOCK> blocks;
	explicit Polyomino(int x, int y);

	int rotateState;

private:
	bool allCanLeft();
	bool allCanRight();

	void drop();

	virtual bool rotate() = 0;
public:
	
	~Polyomino();

	const vector<LPBLOCK>& getBlocks() const;
	bool allCanDown();
	void update();
};

class PolyominoFold :
	public Polyomino
{
	friend PolyominoFactory;

private:
	static const int BLOCK_COUNT = 3;
	static const int blockPosX[BLOCK_COUNT];
	static const int blockPosY[BLOCK_COUNT];
	LPBLOCK pBlock[BLOCK_COUNT];

	bool rotate() override;

	explicit PolyominoFold(int baseX, int baseY, COLOR c1, COLOR c2, COLOR c3);
};

class PolyominoTree :
	public Polyomino
{
	friend PolyominoFactory;

private:
	static const int BLOCK_COUNT = 3;
	static const int blockPosX[BLOCK_COUNT];
	static const int blockPosY[BLOCK_COUNT];
	LPBLOCK pBlock[BLOCK_COUNT];

	bool rotate() override;

	explicit PolyominoTree(int baseX, int baseY, COLOR c1, COLOR c2, COLOR c3);
};

class PolyominoCross :
	public Polyomino
{
	friend PolyominoFactory;

private:
	static const int BLOCK_COUNT = 5;
	static const int blockPosX[BLOCK_COUNT];
	static const int blockPosY[BLOCK_COUNT];
	LPBLOCK pBlock[BLOCK_COUNT];
	bool rotate() override;

	explicit PolyominoCross(int baseX, int baseY, COLOR c1, COLOR c2, COLOR c3, COLOR c4, COLOR c5);
};