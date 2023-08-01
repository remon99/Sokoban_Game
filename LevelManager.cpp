#include "LevelManager.h"

void LevelManager::loadLevel() {
	int rowCount = 0;
	int colCount = 0;

	string path = "levels/level" + to_string(currentLevel) + ".txt";//this is a big definition
	//first path will be just levels->level
	//and then it will convert the integer currentlevel to string
	//and than it will concatanate to ".txt"

	levelfile.open(path);
	if (levelfile.is_open()) {
		char inChar;
		while (levelfile.get(inChar)) {
			if (inChar == '\n') {
				colCount = 0;
				rowCount++;
			}
			else {
				levelMap[colCount][rowCount] = inChar;
				colCount++;
			}
		}
	}
	levelfile.close();

	
}

void LevelManager::updateLevel()
{
	currentLevel++;
}
