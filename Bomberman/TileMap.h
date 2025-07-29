#pragma once
#include <vector>
#include "glm.hpp"
namespace dae
{
	class Tile
	{
	public:
		enum class Type
		{
			Empty,
			Indestructible,
			Destructible,
			Spawn,
			Pickup
			// Add more types as needed
		};

		Tile(Type type = Type::Empty)
			: m_Type(type) {
		}

		Type GetType() const { return m_Type; }
		void SetType(Type type) { m_Type = type; }

	private:
		Type m_Type;
	};

	class TileMap
	{
	public:
		static constexpr int TILE_SIZE = 16;
		static constexpr int LEVEL_COLS = 31;  // Full width
		static constexpr int LEVEL_ROWS = 13;  // Full height

		//divide world position by the tilesize to find on which column or row it is

		TileMap();

		Tile& GetTile(int col, int row);
		const Tile& GetTile(int col, int row) const;

		glm::vec3 GetTileWorldPosition(int col, int row) const;
		int GetCols() const { return LEVEL_COLS; }
		int GetRows() const { return LEVEL_ROWS; }

	private:
		std::vector<Tile> m_Tiles;
	};
}