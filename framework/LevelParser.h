/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-18 13:15:19
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 22:31:41
 */
#pragma once

#include <iostream>
#include <vector>

#include "include/tinyxml/tinyxml.h"

class Level;
struct Tileset;
class Layer;
class LayerTile;

class LevelParser
{
public:
  Level *parseLevel(const char *levelFile);

private:
  void parseTextures(TiXmlElement *textureRoot);
  void parseTilesets(TiXmlElement *tilesetRoot, std::vector<Tileset> *tilesets);
  void parseLayerObject(TiXmlElement *objectElement, std::vector<Layer *> *layers, Level *level);
  void parseLayerTile(TiXmlElement *tileElement, std::vector<Layer *> *layers, const std::vector<Tileset> *tilesets);
  // void parseLayerTile(TiXmlElement *tileElement, std::vector<Layer *> *layers, const std::vector<Tileset> *tilesets, std::vector<LayerTile *> *collisionLayers);

  int m_width;
  int m_height;
  int m_tileWidth;
  int m_tileHeight;
};
