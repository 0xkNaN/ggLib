/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-18 13:26:58
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 22:38:27
 */

#include "include/base64/base64.h"
#include "include/zlib/zlib.h"

#include "Game.h"
#include "TextureManager.h"
#include "ObjectFactory.h"
#include "LevelParser.h"
// #include "LayerObject.h"
#include "LayerTile.h"
#include "Level.h"

Level *LevelParser::parseLevel(const char *levelFile)
{
  //? Create Level Docuemmt
  TiXmlDocument levelDoc;
  levelDoc.LoadFile(levelFile);

  //? Create the level object
  Level *pLevel = new Level();

  //? Get the root <map>
  TiXmlElement *pRoot = levelDoc.RootElement();
  //...
  pRoot->Attribute("width", &m_width);
  pRoot->Attribute("height", &m_height);
  pRoot->Attribute("tilewidth", &m_tileWidth);
  pRoot->Attribute("tileheight", &m_tileHeight);

  //? Get Properties
  TiXmlElement *pProperties = pRoot->FirstChildElement();

  //? Parse Textures
  for (TiXmlElement *e = pProperties->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
  {
    if (e->Value() == std::string("property"))
    {
      parseTextures(e);
    }
  }

  //? Parse the tileset
  for (TiXmlElement *e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
  {
    if (e->Value() == std::string("tileset"))
    {
      parseTilesets(e, pLevel->tilesets());
    }
  }

  //? Prase Object Layers
  for (TiXmlElement *e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
  {
    if (e->Value() == std::string("layer"))
    {
      parseLayerTile(e, pLevel->layers(), pLevel->tilesets());
    }

    //!
    // if (e->Value() == std::string("layer") || e->Value() == std::string("objectgroup"))
    // {
    //   if (e->FirstChildElement()->Value() == std::string("object"))
    //   {
    //     parseLayerObject(e, pLevel->layers(), pLevel);
    //   }
    //   else if (e->Value() == std::string("layer") || e->Value() == std::string("objectgroup"))
    //   {
    //     parseLayerTile(e, pLevel->layers(), pLevel->tilesets(), pLevel->collisionLayers());
    //   }
    // }
  }

  // #
  return pLevel;
}

void LevelParser::parseTextures(TiXmlElement *textureRoot)
{
  TheTextureManager::Instance()->load(
      TheGame::Instance()->renderer(),
      textureRoot->Attribute("value"),
      textureRoot->Attribute("name"));
}

void LevelParser::parseTilesets(TiXmlElement *tilesetRoot, std::vector<Tileset> *tilesets)
{
  std::string assetsFolder = "assets/";
  std::string tilesetName = std::string(tilesetRoot->Attribute("name"));
  std::string tilesetSrc = tilesetRoot->FirstChildElement()->Attribute("source");

  //? Add Tileset to TextureManager
  TheTextureManager::Instance()->load(
      TheGame::Instance()->renderer(), assetsFolder.append(tilesetSrc), tilesetName);

  //? Craeate Tileset Object
  Tileset tileset;
  tileset.name = tilesetRoot->Attribute("name");
  tilesetRoot->FirstChildElement()->Attribute("width", &tileset.width);
  tilesetRoot->FirstChildElement()->Attribute("height", &tileset.height);
  tilesetRoot->Attribute("firstgid", &tileset.firstGridId);
  tilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
  tilesetRoot->Attribute("tileheight", &tileset.tileHeight);
  tilesetRoot->Attribute("spacing", &tileset.spacing);
  tilesetRoot->Attribute("margin", &tileset.margin);

  tileset.numColums = tileset.width / (tileset.tileWidth + tileset.spacing);

  tilesets->push_back(tileset);
}

void LevelParser::parseLayerObject(TiXmlElement *objectElement, std::vector<Layer *> *layers, Level *level)
{
  //!
}

void LevelParser::parseLayerTile(TiXmlElement *tileElement, std::vector<Layer *> *layers, const std::vector<Tileset> *tilesets)
{
  LayerTile *layerTile = new LayerTile(m_tileWidth, m_tileHeight, *tilesets);

  bool collidable = false;

  //? Tile Data
  std::vector<std::vector<int>> data;
  std::string decodedIds;
  TiXmlElement *dataNode;

  for (TiXmlElement *e = tileElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
  {
    if (e->Value() == std::string("properties"))
    {
      //!
    }

    if (e->Value() == std::string("data"))
    {
      dataNode = e;
    }
  }

  for (TiXmlNode *n = dataNode->FirstChild(); n != NULL; n = n->NextSibling())
  {
    TiXmlText *text = n->ToText();
    std::string t = text->Value();
    decodedIds = base64_decode(t);
  }

  //? Uncompress zlib compression
  uLong numOfIds = m_width * m_height * sizeof(int);
  std::vector<int> ids(m_width * m_height);
  //! std::vector<unsigned> ids(numOfIds);
  //...
  uncompress((Bytef *)&ids[0], &numOfIds, (const Bytef *)decodedIds.c_str(), decodedIds.size());

  std::vector<int> layerRow(m_width);

  for (int rows = 0; rows < m_height; rows++)
  {
    data.push_back(layerRow);

    for (int cols = 0; cols < m_width; cols++)
    {
      data[rows][cols] = ids[rows * m_width + cols];
    }
  }

  layerTile->setMapWidth(m_width);
  layerTile->setMapHeight(m_height);
  layerTile->setTileIds(data);

  if (collidable)
  {
    //!
  }

  layers->push_back(layerTile);
}

// void LevelParser::parseLayerTile(TiXmlElement *tileElement, std::vector<Layer *> *layers, const std::vector<Tileset> *tilesets, std::vector<LayerTile *> *collisionLayers)
// {
// }
