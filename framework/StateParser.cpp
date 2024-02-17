/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-17 11:21:54
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 15:21:42
 */

#include <iostream>

#include "Game.h"
#include "TextureManager.h"
#include "ObjectFactory.h"
#include "LoaderParams.h"
#include "StateParser.h"

bool StateParser::parseState(
    std::string file,
    std::string stateId,
    std::vector<Node *> *objects,
    std::vector<std::string> *textureIds)
{
  //? Create the XML document
  TiXmlDocument xmlDoc;

  //? Load the state file
  if (!xmlDoc.LoadFile(file))
  {
    std::cout << xmlDoc.ErrorDesc() << std::endl;
    return false;
  }

  //? Get <states>
  TiXmlElement *pRoot = xmlDoc.RootElement();

  //? Get <stateId>
  TiXmlElement *pStateRoot = 0;
  for (TiXmlElement *e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
  {
    std::string test = stateId;
    if (e->Value() == std::string(stateId))
    {
      pStateRoot = e;
    }
  }

  //? Get <textures>
  TiXmlElement *pTextureRoot = 0;
  for (TiXmlElement *e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
  {
    if (e->Value() == std::string("textures"))
    {
      pTextureRoot = e;
    }
  }
  //...
  parseTextures(pTextureRoot, textureIds);

  //? Get <objects>
  TiXmlElement *pObjectRoot = 0;
  for (TiXmlElement *e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
  {
    if (e->Value() == std::string("objects"))
    {
      pObjectRoot = e;
    }
  }
  //...
  parseObjects(pObjectRoot, objects);

  return true;
}

void StateParser::parseTextures(TiXmlElement *stateRoot, std::vector<std::string> *textureIds)
{
  for (TiXmlElement *e = stateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
  {
    std::string file = e->Attribute("file");
    std::string textureId = e->Attribute("id");

    textureIds->push_back(textureId);
    TheTextureManager::Instance()->load(TheGame::Instance()->renderer(), file, textureId);
  }
}

void StateParser::parseObjects(TiXmlElement *stateRoot, std::vector<Node *> *objects)
{
  for (TiXmlElement *e = stateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
  {
    std::string type, textureId;

    int x, y, width, height, numFrames, animSpeed, callbackId;

    type = e->Attribute("type");
    textureId = e->Attribute("textureId");

    e->Attribute("x", &x);
    e->Attribute("y", &y);
    e->Attribute("width", &width);
    e->Attribute("height", &height);
    e->Attribute("numFrames", &numFrames);
    e->Attribute("animSpeed", &animSpeed);
    e->Attribute("callbackId", &callbackId);

    Node *obj = TheObjectFactory::Instance()->create(type);
    obj->load(new LoaderParams(x, y, width, height, textureId, numFrames, animSpeed, callbackId));

    objects->push_back(obj);
  }
}
