/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-18 13:12:27
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 22:44:17
 */

#include "Game.h"
#include "TextureManager.h"
#include "LayerTile.h"

LayerTile::LayerTile(int tileWidth, int tileHeight, const std::vector<Tileset> &tilesets)
    : m_tileWidth(tileWidth), m_tileHeight(tileHeight), m_tilesets(tilesets)
{
  m_numRows = TheGame::Instance()->gameHeight() / m_tileHeight;
  m_numColumns = TheGame::Instance()->gameWidth() / m_tileWidth;

  m_position = Vector2D(0, 0);
  m_velocity = Vector2D(0, 0);
}

void LayerTile::update(Level *level)
{
  m_position += m_velocity;
}

void LayerTile::render()
{
  int x = m_position.x() / m_tileWidth;
  int y = m_position.y() / m_tileHeight;

  int x2 = int(m_position.x() / m_tileWidth) % m_tileWidth;
  int y2 = int(m_position.y() / m_tileHeight) % m_tileHeight;

  for (int i = 0; i < m_numRows; i++)
  {
    for (int j = 0; j < m_numColumns; j++)
    {
      int id = m_tileIds[i + y][j + x];

      if (id == 0)
        continue;

      Tileset tileset = tilesetById(id);

      id--;

      //? Render tile
      int x = (j * m_tileWidth) - x2;
      int y = (i * m_tileHeight) - y2;
      int width = m_tileWidth;
      int height = m_tileHeight;
      int currRow = (id - (tileset.firstGridId - 1)) / tileset.numColums;
      int currFrame = (id - (tileset.firstGridId - 1)) % tileset.numColums;
      //...
      TheTextureManager::Instance()->renderTile(
          TheGame::Instance()->renderer(), tileset.name,
          tileset.margin, tileset.spacing,
          x, y, width, height,
          currRow, currFrame);
    }
  }
}

Tileset LayerTile::tilesetById(int tileId)
{
  for (int i = 0; i, m_tilesets.size(); i++)
  {
    if (i + 1 == m_tilesets.size() - 1)
    {
      if (tileId >= m_tilesets[i].firstGridId && tileId < m_tilesets[i + 1].firstGridId)
      {
        return m_tilesets[i];
      }
    }
    else
    {
      return m_tilesets[i];
    }
  }

  //? Return empty tileset
  std::cout << "No tileset found, returning empty tileset" << std::endl;
  Tileset t;
  return t;
}