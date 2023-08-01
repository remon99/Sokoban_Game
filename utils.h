#pragma once

#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Vec2
{
	int x;
	int y;
};

const int TILE_SIZE = 64;
const int TILE_ROWS = 10;
const int TILE_COLS = 10;
const int SCREEN_WIDTH = TILE_SIZE*TILE_COLS;
const int SCREEN_HEIGHT = TILE_SIZE*TILE_ROWS;