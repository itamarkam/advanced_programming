#pragma once

#include <utility> // for std::pair
#include <map>
#include <vector>
#include <queue>

#include "c:\Users\kamin\Desktop\IBattleshipGameAlgo.h"
#include "Battleship.h"

class BattleshipPlayer : public IBattleshipGameAlgo {
public:
	BattleshipPlayer(int id);

	void setBoard(const char** board, int numRows, int numCols); // called once to notify player on his board

	std::pair<int, int> attack(); // ask player for his move

	void notifyOnAttackResult(int player, int row, int col, AttackResult result); // notify on last move result

	AttackResult opponentMove(std::pair<int, int> move, int* score);

	int getId();

	bool isAlive();

	int score = 0;

private:
	int id_;
	std::vector<Battleship> battleships_;
	std::map<std::pair<int, int>, Battleship*> hits_;
	std::queue<std::pair<int, int>> moves_;
	int n_ships_;
};