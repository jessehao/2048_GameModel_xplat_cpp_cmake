#include "SW2048Game.h"
#include <stdexcept>
#include <cstdlib>
#include <ctime>

#pragma region Methods
bool SW2048Game::isPlaying() const {
	return playing;
}

bool SW2048Game::isWin() const {
	return win;
}

int SW2048Game::getScore() const {
	return score;
}

int SW2048Game::getMaxCell() const {
	return maxCell;
}

int SW2048Game::getCell(int y, int x) const {
	if (y < 0 || x < 0 || y >= order || x >= order)
		throw new std::out_of_range(NULL);
	return board[y][x];
}

void SW2048Game::move(const Vector2& direction){
	int rNum;
	if (direction == Vector2::ZERO) return;
	Vector2* fixedDirection;
	if (direction.x != 0 && direction.y != 0)
		fixedDirection = direction.x > direction.y ? new Vector2(direction.x, 0) : new Vector2(0, direction.y);
	else
		fixedDirection = new Vector2(direction);
	process(*fixedDirection);
	if (copyToLast()) {
		rNum = randomGenerate(1);
		maxCell = rNum > maxCell ? rNum : maxCell;
		copyToLast();
	}
	refreshBlankList();
	if (!canMove()) {
		playing = false;
		win = false;
	}
	
}

void SW2048Game::restart() {
	int rNum;
	score = 0;
	maxCell = 0;
	initBoard();
	rNum = randomGenerate(2);
	maxCell = rNum > maxCell ? rNum : maxCell;
	copyToLast();
	playing = true;
}
#pragma endregion

#pragma region Constructor & Destructor
SW2048Game::SW2048Game(int order) : order(order), processQueue(new ProcessingQueue(order))
{
	playing = false;
	allocBoard();
}

SW2048Game::~SW2048Game()
{
	delete processQueue;
	deleteBoard();
}
#pragma endregion

#pragma Private Methods
bool SW2048Game::process(Vector2& direction) {
	int *x, *y, outter, inner, fixedInner, start, current;
	bool result = false;
	if (direction.isVertical()) {
		y = &fixedInner;
		x = &outter;
	}
	else if(direction.isHorizontal()) {
		y = &outter;
		x = &fixedInner;
	}
	else
		throw new std::invalid_argument("invalid direction");
	if (Vector2::dot(direction, Vector2::ONE) > 0)
		start = order - 1;
	else
		start = 0;
	for(outter = 0; outter < order; outter++){
		processQueue->clear();
		for (inner = 0; inner < order; inner++) {
			fixedInner = std::abs(start - inner);
			current = processQueue->enqueue(board[*y][*x]);
			if (current > 0) {
				score += current;
				result = true;
			}
			maxCell = current > maxCell ? current : maxCell;
			if (maxCell >= SW2048Game::MAX) {
				playing = false;
				win = true;
			}	
		}
        for(inner = 0; inner < order; inner++){
            fixedInner = std::abs(start - inner);
            if(processQueue->isEmpty())
                board[*y][*x] = 0;
            else
                board[*y][*x] = processQueue->dequeue();
        }
    }
	return result;
}

int SW2048Game::randomGenerate(int count) {
	int result = 2;
	refreshBlankList();
	if ((int)blankList.size() == 0) return 0;
	int raw, rIndex, rValue;
	std::srand(std::time(NULL));
	for (int i = 0; i < count; i++) {
		raw = std::rand();
		rIndex = std::abs(raw % (int)blankList.size());
		rValue = raw % 2 == 0 ? 2 : 4;
		result = rValue > result ? rValue : result;
		*blankList[rIndex] = rValue;
	}
	return result;
}

void SW2048Game::refreshBlankList() {
	blankList.clear();
	for(int y = 0; y<order; y++)
		for (int x = 0; x < order; x++) {
			if (board[y][x] == 0) {
				blankList.push_back(&board[y][x]);
			}
		}
}

bool SW2048Game::canMove()
{
	if ((int)blankList.size() > 0) return true;
	for (int y = 0; y<order; y++) {
		for (int x = 0; x<order; x++) {
			if ((y + 1 < order ? board[y][x] == board[y + 1][x] : false) ||
				(x + 1 < order ? board[y][x] == board[y][x + 1] : false))
				return true;
		}
	}
	return false;
}

void SW2048Game::allocBoard() {
	board = new int*[order];
	last = new int*[order];
	for (int y = 0; y < order; y++) {
		board[y] = new int[order];
		last[y] = new int[order];
	}
}

void SW2048Game::initBoard() {
	for (int y = 0; y < order; y++)
		for (int x = 0; x < order; x++) 
			board[y][x] = 0;
}

void SW2048Game::deleteBoard() {
	for (int i = 0; i < order; i++) {
		delete[] board[i];
	}
	delete[] board;
}

bool SW2048Game::copyToLast() {
	bool result = false;
	for(int y = 0; y<order; y++)
		for (int x = 0; x < order; x++) {
			if (last[y][x] != board[y][x]) {
				last[y][x] = board[y][x];
				result = true;
			}
		}
	return result;
}
#pragma endregion