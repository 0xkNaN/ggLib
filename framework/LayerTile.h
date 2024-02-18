/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-17 18:59:15
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 22:37:00
 */
#pragma once

#include <iostream>
#include <vector>

#include "Vector2D.h"
#include "Layer.h"
#include "Level.h"

class LayerTile : public Layer
{
public:
  LayerTile(int tileWidth, int tileHeight, const std::vector<Tileset> &tilesets);

  virtual ~LayerTile() {}

  virtual void update(Level *level);
  virtual void render();

  Tileset tilesetById(int tileId);

  const Vector2D position() { return m_position; }
  const std::vector<std::vector<int>> &tileIds() { return m_tileIds; }

  void setTileWidth(int w) { m_tileWidth = w; }
  void setTileHeight(int h) { m_tileHeight = h; }
  void setMapWidth(int w) { m_mapWidth = w; }
  void setMapHeight(int h) { m_mapHeight = h; }
  void setTileIds(const std::vector<std::vector<int>> &data) { m_tileIds = data; }

private:
  int m_numRows;
  int m_numColumns;
  int m_tileWidth;
  int m_tileHeight;

  int m_mapWidth;
  int m_mapHeight;

  Vector2D m_position;
  Vector2D m_velocity;

  const std::vector<Tileset> &m_tilesets;

  std::vector<std::vector<int>> m_tileIds;
};
