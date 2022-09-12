#include "TiledMap.h"
#include <iostream>


TiledMap::TiledMap(SDL_Renderer* sdlRenderer, std::string tiledMapFilename)
	: renderer(sdlRenderer), filename(tiledMapFilename)
{
	// Load tiles as a single texture
	SDL_Surface* image = IMG_Load(filename.c_str());
	if (image == NULL)
		std::cout << "Could not load tile map image file.\n";
	texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);


	// Create tiles by iterating through the indices of our map
	// and creating rectangles to crop from the texture and
	// to render on the screen.
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {

			SDL_Rect sourceRect;
			sourceRect.x = (map[i][j] % sourceNTilesInRow) * sourceTileSizePx;
			sourceRect.y = (map[i][j] / sourceNTilesInRow) * sourceTileSizePx;
			sourceRect.h = sourceTileSizePx;
			sourceRect.w = sourceTileSizePx;

			SDL_Rect renderRect;
			renderRect.x = j * tileWidth; // maybe i?
			renderRect.y = i * tileHeight; // maybe j?
			renderRect.h = tileHeight;
			renderRect.w = tileWidth;

			Tile newTile = Tile();
			newTile.sourceRect = sourceRect;
			newTile.destinationRect = renderRect;
			tiles.push_back(newTile);
		}
	}
}


void TiledMap::Render() {
	for (Tile& tile : tiles) {
		if (!tile.collision) {
			SDL_RenderCopy(renderer, texture, &tile.sourceRect, &tile.destinationRect);
		}
		else {
			SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
			SDL_RenderFillRect(renderer, &tile.destinationRect);
		}
	}
}

void TiledMap::CheckCollision(Player* player)
{
	for (Tile& tile : tiles) {
		SDL_Rect tileRect = tile.destinationRect;
		SDL_Rect playerRect = player->GetPlayerRect();


		bool collision = SDL_HasIntersection(&tileRect, &playerRect);
		tile.collision = collision;
	}
}

TiledMap::~TiledMap()
{
	SDL_DestroyTexture(texture);
}