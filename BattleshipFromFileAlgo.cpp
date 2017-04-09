#include "stdafx.h"
#include "BattleshipFromFileAlgo.h"


BattleshipFromFileAlgo::BattleshipFromFileAlgo(const char* path) : file_(std::ifstream(path)) {}

std::pair<int, int> BattleshipFromFileAlgo::attack() {
	if (file_.eof()) {
		return dummy_pair_;
	}
	
}

BattleshipFromFileAlgo::~BattleshipFromFileAlgo() { file_.close(); }
