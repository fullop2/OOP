#pragma once
#include "../stdafx.h"

class Block
{
private:
	friend BlockManager;
	explicit Block(COLOR color, int x, int y);

	int x, y;
	bool placed;
	LPCOLORSET pColorSet;
	COLOR color;

	void propagation();

	bool movable(int cx, int cy);
	
public:

	~Block();

	// getter and setter : inline
	const int getX() const;
	const int getY() const;
	const bool isPlaced() const;
	const LPCOLORSET getColorSet() const;
	COLOR getColor() const;
	void setColorSet(LPCOLORSET pColorSet);
	void setPlaced(bool placed);
	void setPosition(int x, int y);
	void jointColorSet();

	bool canDown();
	bool canLeft();
	bool canRight();
	void down();
	void left();
	void right();

	static bool cmp(const LPBLOCK lhs, const LPBLOCK rhs);
};




