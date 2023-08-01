#pragma once

#include "Utils.h"
#include"LevelManager.h"
#include"Player.h"
#include"Box.h"

class Game
{
public:
	bool Init();
	void GameLoop();
	void Shutdown();
	bool HitWall(int x, int y);
	bool BoxUpdated(int moveX, int moveY, int pX, int pY);

	SDL_Texture* LoadTexture(string path);
	

private:
	void HandleEvents();
	void Update();
	void Draw();
	void initLevel();
	void goToNextLevel();
	bool HitGoal(int x, int y);
	bool isRunning = true;
	bool allGoalComplete();
	void destroyBox();
	bool CanPushBox(Box* box, int x, int y);//the current box we are trying to push 
	//x and y is the location we are trying to push the box

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* wallTexture = nullptr;
	SDL_Texture* groundTexture = nullptr;
	SDL_Texture* boxTexture = nullptr;
	SDL_Texture* goalTexture = nullptr;

	class LevelManager* levelmanager;
	class Player* player;
	vector<Box*> boxes;//because we don't need to update our level map
};


