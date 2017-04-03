#pragma once

#include <utility>
#include <map>

enum class BattleshipType {
	B, P, M, D
};

class Battleship {
public:
	Battleship(BattleshipType t);
	void hit();
	bool isSunk();
	int getValue();

private:
	int size_;
	int value_;
	int hits_ = 0;
};

static const std::map<BattleshipType, std::pair<int, int>> battleship_details_ = {
	{ BattleshipType::B, { 1, 2 } },
	{ BattleshipType::P, { 2, 3 } },
	{ BattleshipType::M, { 3, 7 } },
	{ BattleshipType::D, { 4, 8 } }
};

