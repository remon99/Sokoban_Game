#pragma once
#include"utils.h"

class Box
{
public:
	Box(int x, int y);
	~Box();
	void Update(int x, int y, bool complete);
	Vec2 GetPos();
	SDL_Rect* GetRect();
	bool GetInGoal();

private:
	Vec2 pos;
	SDL_Rect rect;
	bool inGoal;
};

