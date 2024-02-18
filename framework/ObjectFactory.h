/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-17 10:48:44
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 17:39:42
 */
#pragma once

#include <string>
#include <map>

#include "Node.h"

class BaseCreator
{
public:
  virtual Node *createNode() const = 0;
  virtual ~BaseCreator() {}
};

class ObjectFactory
{
public:
  static ObjectFactory *Instance()
  {
    if (s_pInstance == 0)
      s_pInstance = new ObjectFactory();
    return s_pInstance;
  }

  bool registerType(std::string typeId, BaseCreator *creator);
  Node *createType(std::string typeId);

private:
  ObjectFactory() {}
  ~ObjectFactory() {}

  static ObjectFactory *s_pInstance;

  std::map<std::string, BaseCreator *> m_creators;
};

typedef ObjectFactory TheObjectFactory;