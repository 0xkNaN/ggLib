/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-17 18:35:37
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 20:06:16
 */
#pragma once

#include <iostream>
#include <vector>

#include "Layer.h"
#include "LevelParser.h"

class TileLayer;

struct Tileset
{
  int firstGridId;
  int tileWidth;
  int tileHeight;
  int spacing;
  int margin;
  int width;
  int height;
  int numColums;
  std::string name;
};

class Level
{
public:
  ~Level();

  void update();
  void render();

  std::vector<Tileset> *tilesets() { return &m_tilesets; }
  std::vector<Layer *> *layers() { return &m_layers; }
  std::vector<TileLayer *> *collisionLayers() { return &m_collisionLayers; }
  const std::vector<TileLayer *> &collidableLayers() { return m_collisionLayers; }

private:
  friend class LevelParser;

  Level();

  std::vector<Tileset> m_tilesets;
  std::vector<Layer *> m_layers;
  std::vector<TileLayer *> m_collisionLayers;
};
