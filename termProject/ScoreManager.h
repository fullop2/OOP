#pragma once
#include "stdafx.h"

/*
score calculate
http://kayezero.blogspot.com/2009/08/blog-post_8347.html
*/

class ScoreManager
{
private:
	unsigned int score;
	unsigned int explodeColorCount[COLOR::COLOREND];
	unsigned int combo;

	static constexpr int INDEX_OF_COMBO_POINT_MAX = 19;
	static constexpr int INDEX_OF_COLOR_COUNT_POINT_MAX = 8;
	static constexpr int INDEX_OF_MULTI_POINT_MAX = COLOR::COLOREND;

	unsigned int comboPoint[INDEX_OF_COMBO_POINT_MAX] = {0,8,16,32,64,96,128,160,192,224,256,288,320,352,388,416,448,480,512};
	unsigned int colorCountPoint[INDEX_OF_COLOR_COUNT_POINT_MAX] = { 0,2,3,4,5,6,7,10 };
	unsigned int multiPoint[INDEX_OF_MULTI_POINT_MAX] = { 0,3,6,12,24 };

	unsigned int calcTotalCount();
	unsigned int calcComboPoint();
	unsigned int calcColorPoint();
	unsigned int calcMultiPoint();

	static ScoreManager* pScoreManager;
	ScoreManager();
public:
	static ScoreManager& get();
	~ScoreManager();

	void dropByKeyDown();
	void dropByDropKey(unsigned dropCount);
	void calc();
	void addExplodedColorData(COLOR color);
	void clearColorCount();
	void clearCombo();
	unsigned int getCombo();
	void increaseCombo();
	unsigned int getScore();
};

