#pragma once

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <list>
#include "Player.h"


const int mapWidth = 10;
const int mapHeight = 4;
const int map[mapHeight][mapWidth] = {
	{5, 6, 6, 6, 6, 6, 6, 6, 6, 7},
	{19, 20, 20, 20, 20, 20, 20, 20, 20, 21},
	{19, 20, 20, 20, 20, 20, 20, 20, 20, 21},
	{1, 20, 20, 20, 20, 20, 20, 20, 20, 2}
};

struct Tile {
	SDL_Rect sourceRect;
	SDL_Rect destinationRect;
	bool collision;
};



class TiledMap {
public:
	TiledMap(SDL_Renderer* sdlRenderer,
		std::string tiledMapFilename);
	~TiledMap();

	void Render();
	void CheckCollision(Player* player);

private:

	const int sourceTileSizePx = 32;
	const int sourceNTilesInRow = 14;
	const int tileWidth = 64;
	const int tileHeight = 64;

	std::list<Tile> tiles;

	std::string filename;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
};