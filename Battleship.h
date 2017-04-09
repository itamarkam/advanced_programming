#pragma once

#include <utility>
#include <map>

#include "BattleshipPlayer.h"

enum class BattleshipType {
	B, P, M, D
};

class Battleship {
public:
	Battleship(BattleshipType t, BattleshipPlayer* owner);
	Battleship* owner();
	void hit();
	bool isSunk();
	int getValue();

private:
	BattleshipPlayer* owner_;
	int size_;
	int value_;
};

static const std::map<BattleshipType, std::pair<int, int>> battleship_details_ = {
	{ BattleshipType::B, { 1, 2 } },
	{ BattleshipType::P, { 2, 3 } },
	{ BattleshipType::M, { 3, 7 } },
	{ BattleshipType::D, { 4, 8 } }
};

