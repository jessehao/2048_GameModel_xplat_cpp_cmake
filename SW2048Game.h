#pragma once
#include "Vector2.h"
#include "ProcessingQueue.h"
#include <vector>

class SW2048Game
{
#pragma region Constants
	const int MAX = 1 << 14; // 16384
#pragma endregion

#pragma region Variables
	int** last;
	int** board;
	ProcessingQueue* processQueue;
	int order;
	int score;
	int maxCell;
	bool playing;
	bool win;
	std::vector<int*> blankList;
#pragma endregion
    
#pragma region Methods
	void allocBoard();
	void initBoard();
	void deleteBoard();
	bool process(Vector2& direction);
	int randomGenerate(int count);
	void refreshBlankList();
	bool canMove();
	bool copyToLast();
#pragma endregion
public:
#pragma region Methods
	bool isPlaying() const;
	bool isWin() const;
	int getScore() const;
	int getCell(int y, int x) const;
	int getMaxCell() const;
	void restart();
    void move(const Vector2& direction);
#pragma endregion

#pragma region Constructor & Destructor
	SW2048Game(int order);
	~SW2048Game();
#pragma endregion
};

