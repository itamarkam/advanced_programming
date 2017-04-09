#pragma once
#include <fstream>
#include <iostream>

#include "C:\Users\kamin\Source\Repos\advanced_programming\IBattleshipGameAlgo.h"

class BattleshipFromFileAlgo :
	public IBattleshipGameAlgo
{
public:
	BattleshipFromFileAlgo(const char* path);
	BattleshipFromFileAlgo::~BattleshipFromFileAlgo();
	std::pair<int, int> attack() override;
	void setBoard(const char** board, int numRows, int numCols) override {};
	void notifyOnAttackResult(int player, int row, int col, AttackResult result) override {};

private:
	std::ifstream file_;
	const std::pair<int, int> dummy_pair_ = { -1, -1 };
};

