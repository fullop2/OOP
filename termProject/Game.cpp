#include "Game.h"

#include "Block/Block.h"
#include "Block/ColorSet.h"
#include "Block/BlockManager.h"

#include "ScoreManager.h"

#include "Polyomino/Polyomino.h"
#include "Polyomino/PolyominoFactory.h"

#include "System/Input.h"
#include "System/View.h"
#include "System/sys.h"


Game::Game()
{
	setlocale(LC_CTYPE, "");

	sys::hideCursor();
	canMove = true;
	currentPolyomino = nullptr;
	lastUpdatedTime = Time::getNowTime();
}
Game::~Game()
{
	sys::showCursor();
}

void Game::init()
{
	update();
}

bool Game::asyncDelay(double delay)
{
	if (Time::getElapsed(lastUpdatedTime).count() < delay) { return false; }
	lastUpdatedTime = Time::getNowTime();
	return true;
}
void Game::syncDelay(double delay)
{
	while (Time::getElapsed(lastUpdatedTime).count() < delay);
	lastUpdatedTime = Time::getNowTime();
}

void Game::asyncDropAll()
{
	while (1)
	{
		if (asyncDelay(0.2) && !dropNotPlacedBlocks())
		{
			jointColorSet();
			break;
		}
	}
}

void Game::setConsoleColor(COLOR color)
{
	switch (color)
	{
	case RED:
		sys::consoleColorRed();
		break;
	case GREEN:
		sys::consoleColorGreen();
		break;
	case BLUE:
		sys::consoleColorBlue();
		break;
	case YELLOW:
		sys::consoleColorYellow();
		break;
	case GRAY:
		sys::consoleColorGray();
		break;
	}
}

void Game::update()
{
	while (1) {
		render();
		if (currentPolyomino == nullptr && !newPolyomino())
		{
			return; // cannot make new block : game end
		}
		render();
		while (canMove)
		{
			Input::update(); // user input
			canMove = moveCurrentPolyomino();
			if ((canMove = currentPolyomino->allCanDown())&& asyncDelay(1.0)) {
				dropNotPlacedBlocks();
			};
		}
		{
			delete currentPolyomino;
			currentPolyomino = nullptr;
		}
		for(auto i = 0; i < W; i++){
			for(auto j = 0; j <= START_H; j++)
			{
				if(BlockManager::get().getBlock(i,j) != nullptr)
					return;
			}
		}
		asyncDropAll();
		while (explode())
		{
			ScoreManager::get().increaseCombo();
			ScoreManager::get().calc();
			syncDelay(0.2);
			render();

			asyncDropAll();
		}
		ScoreManager::get().clearColorCount();
		ScoreManager::get().clearCombo();
		canMove = true;
	}
}

bool Game::newPolyomino()
{
	int x = 2;
	int y = START_H+1;
	return PolyominoFactory::createPolyomino(getPolyRand(), x, y, &currentPolyomino);
}

bool Game::moveCurrentPolyomino()
{
	currentPolyomino->update();
	if (Input::getKeyDown()) { render(); }
	/* check current polyomino */
	auto& blocks = currentPolyomino->getBlocks();
	for (auto currentBlock : blocks)
	{
		if (currentBlock->isPlaced()) {
			return false;
		}
	}
	return true;
}

bool Game::dropNotPlacedBlocks()
{
	/* update all block position */
	bool somethingIsUpdated = false;
	for (auto y = H - 1; y >= 0; y--)
	{
		for (auto x = 0; x < W; x++)
		{
			auto pBlock = BlockManager::get().getBlock(x, y);
			if (pBlock != nullptr && !pBlock->isPlaced())
			{
				pBlock->down();
				somethingIsUpdated = true;
			}
		}
	}
	render();
	return somethingIsUpdated;
}

bool Game::explode()
{
	bool exploded = false;
	auto& colorSets = BlockManager::get().getColorSets();

	for (auto itSet = colorSets.begin(); itSet != colorSets.end();)
	{
		auto pColorSet = *itSet;
		if ((*itSet)->size() >= 4 && (*itSet)->getColor() != COLOR::GRAY)
		{
			pColorSet->explodeBlocks();
			itSet = BlockManager::get().removeColorSet(pColorSet);//colorSets.erase(itSet);
			exploded = true;
		}
		else
		{
			++itSet;
		}
	}
	for (auto itSet = colorSets.begin(); itSet != colorSets.end();)
	{
		auto pColorSet = *itSet;
		if ((*itSet)->size() == 0)
		{
			itSet = BlockManager::get().removeColorSet(pColorSet);//colorSets.erase(itSet);
		}
		else
		{
			++itSet;
		}
	}
	return exploded;
}

void Game::jointColorSet()
{
	for (auto y = H - 1; y >= 0; y--)
	{
		for (auto x = 0; x < W; x++)
		{
			auto pBlock = BlockManager::get().getBlock(x, y);
			if (pBlock != nullptr &&
				pBlock->isPlaced() &&
				pBlock->getColorSet() == nullptr)
			{
				pBlock->jointColorSet();
			}
		}
	}
}

void Game::drawBoard()
{
	View::printBoardHeader();
	const Board& board = BlockManager::get().getBoard();
	for (auto i = 4; i < H; i++)
	{
		auto& row = board[i];
		sys::consoleColorWhite();
		View::printBoardSide();
		for (auto& pBlock : row)
		{
			if (pBlock == nullptr) {
				View::printBlank();
			}
			else {
				setConsoleColor(pBlock->getColor());
				View::printBlock();
			}
		}
		sys::consoleColorWhite();
		View::printBoardSide();
		View::printReturn();
	}
	View::printBoardFooter();

	View::printBoardHeader();
	View::printBoardSide();
	View::printScore(ScoreManager::get().getScore());
	View::printBoardSide();
	View::printReturn();
	View::printBoardFooter();

	if (ScoreManager::get().getCombo() > 0)
	{
		static int i = -1;
		i = (i + 1) % (int)COLOR::GRAY;
		View::printBoardHeader();
		View::printBoardSide();
		setConsoleColor((COLOR)i);
		View::printCombo(ScoreManager::get().getCombo());
		sys::consoleColorWhite();
		View::printBoardSide();
		View::printReturn();
		View::printBoardFooter();
	}
	else {
		for(int i = 0; i < 3; i++)
			View::printBlankLine();
	}

}

void Game::render()
{
	sys::clear();
	drawBoard();
}
