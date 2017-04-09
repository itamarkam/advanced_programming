#pragma once

#include <utility> // for std::pair
#include <map>
#include <vector>
#include <queue>

#include "c:\Users\kamin\Desktop\IBattleshipGameAlgo.h"
#include "Battleship.h"
#include "IBattleshipGameAlgo.h"

class BattleshipPlayer : public IBattleshipGameAlgo {
public:
	BattleshipPlayer(int id);
	// Algorithm methods
	void setBoard(const char** board, int numRows, int numCols); // called once to notify player on his board
	std::pair<int, int> attack(); // ask player for his move
	void notifyOnAttackResult(int player, int row, int col, AttackResult result); // notify on last move result

	int getId();
	bool isAlive();
	void addBattleship(Battleship& battleship);
	int getScore();
	void addPoints(int points);
private:
	int id_;
	int score = 0;
	std::vector<Battleship> battleships_;
	IBattleshipGameAlgo algo_;
};