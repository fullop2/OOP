#include "ScoreManager.h"

ScoreManager* ScoreManager::pScoreManager = nullptr;

ScoreManager::ScoreManager()
{
	score = 0;
	clearCombo();	
	clearColorCount();
}
ScoreManager::~ScoreManager()
{
}

ScoreManager& ScoreManager::get()
{
	if (pScoreManager == nullptr) { // lazy instantiation
		pScoreManager = new ScoreManager();
	}
	return *pScoreManager;
}

void ScoreManager::dropByKeyDown()
{
	score++;
}
void ScoreManager::dropByDropKey(unsigned dropCount)
{
	score += dropCount;
}
void ScoreManager::calc()
{
	score += calcTotalCount() * (calcComboPoint() + calcColorPoint() + calcMultiPoint()) * 10;
	clearColorCount();
}

void ScoreManager::clearColorCount()
{
	for (auto i = 0; i < static_cast<size_t>(COLOR::COLOREND); i++)
		explodeColorCount[i] = 0;
}
void ScoreManager::clearCombo()
{
	combo = 0;
}

void ScoreManager::increaseCombo()
{
	combo++;
}
unsigned int ScoreManager::getCombo()
{
	return combo;
}
unsigned int ScoreManager::getScore()
{
	return score;
}

unsigned int ScoreManager::calcTotalCount()
{
	unsigned int sum = 0;
	for (auto i = 0; i < static_cast<size_t>(COLOR::COLOREND); i++)
		sum += explodeColorCount[i];
	return sum;
}
unsigned int ScoreManager::calcComboPoint()
{
	return comboPoint[(combo > INDEX_OF_COMBO_POINT_MAX ? INDEX_OF_COMBO_POINT_MAX : combo)-1];
}
unsigned int ScoreManager::calcColorPoint()
{
	unsigned sum = 0;
	for (auto i = 0; i < static_cast<size_t>(COLOR::COLOREND); i++) {
		int tmp = explodeColorCount[i] - 4; 
		sum += colorCountPoint[((tmp < 0) ? 0 : tmp)];
	}
	return sum;
}
unsigned int ScoreManager::calcMultiPoint()
{
	unsigned sum = 0;
	for (auto i = 0; i < static_cast<size_t>(COLOR::COLOREND); i++)
		if (explodeColorCount[i] > 0) { sum++; }
	return multiPoint[sum-1];
}

void ScoreManager::addExplodedColorData(COLOR color)
{
	auto tmp = static_cast<int>(color);
	explodeColorCount[(--tmp < 0 ? 0 : tmp)]++;
}