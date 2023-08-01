#pragma once

#include"utils.h"
#include<fstream>

class LevelManager
{
public:
	void loadLevel();
	char levelMap[TILE_ROWS][TILE_COLS];
	void updateLevel();


private:
	ifstream levelfile;
	int currentLevel = 1;
};

