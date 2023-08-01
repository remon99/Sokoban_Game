#include "Player.h"

Player::Player(Game* g) {
	game = g;
	texture = game->LoadTexture("assets/player.png");
	direction = 0;
	pos.x = 0;
	pos.y = 0;
	posRect = { pos.x,pos.y,TILE_SIZE,TILE_SIZE };
	spriteRect = { 0,0,TILE_SIZE,TILE_SIZE };
}

void Player::Move(int x, int y) {
	setDirection(x, y);
	int newPlayerX = pos.x + x;
	int newPlayerY = pos.y + y;

	if (game->HitWall(newPlayerX, newPlayerY)) {
		return;
	}

	if (!game->BoxUpdated(x, y, newPlayerX, newPlayerY)) {
		return;
	}

	pos.x = newPlayerX;
	pos.y = newPlayerY;

	posRect.x = pos.x * TILE_SIZE;
	posRect.y = pos.y * TILE_SIZE;
}

void Player::Draw(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, &spriteRect, &posRect);
}

void Player::Reset(int x, int y)//why this function...
//because it will not move player to desire position into a new level
{
	direction = 0;
	pos.x = x;
	pos.y = y;
	posRect = { pos.x * TILE_SIZE,pos.y * TILE_SIZE,TILE_SIZE,TILE_SIZE };
	spriteRect = { 0,0,TILE_SIZE,TILE_SIZE };
}

void Player::setDirection(int x, int y) {
	if (x > 0) {//that means we tried to move to the right
		direction = 0;
	}
	else if (x < 0) {//that means we tried to move to the left
		direction = 2;
	}
	else if (y > 0) {//that means we tried to move down
		direction = 1;
	}
	else if (y < 0) {//that means we tried to move top
		direction = 3;
	}
	
	spriteRect.x = direction * TILE_SIZE;//this to split the image
	//lets say x<0 that means we are trying to move to left ..
	//so our x should start from 2*64 pixels and the render should be from 64*2 + another 64
}