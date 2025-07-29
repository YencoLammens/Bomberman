#include "TileMap.h"
#include <stdexcept>

dae::TileMap::TileMap()
	: m_Tiles(LEVEL_COLS* LEVEL_ROWS)
{
}

dae::Tile& dae::TileMap::GetTile(int col, int row)
{
	if (col < 0 || col >= LEVEL_COLS || row < 0 || row >= LEVEL_ROWS)
		throw std::out_of_range("TileMap::GetTile: out of bounds");

	return m_Tiles[row * LEVEL_COLS + col];
}

const dae::Tile& dae::TileMap::GetTile(int col, int row) const
{
	if (col < 0 || col >= LEVEL_COLS || row < 0 || row >= LEVEL_ROWS)
		throw std::out_of_range("TileMap::GetTile (const): out of bounds");

	return m_Tiles[row * LEVEL_COLS + col];
}

glm::vec3 dae::TileMap::GetTileWorldPosition(int col, int row) const
{
	return { static_cast<float>(col * TILE_SIZE), static_cast<float>(row * TILE_SIZE), 0 };
}