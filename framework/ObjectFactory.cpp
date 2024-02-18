/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-17 11:05:47
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 17:39:45
 */

#include "ObjectFactory.h"

ObjectFactory *ObjectFactory::s_pInstance = 0;

bool ObjectFactory::registerType(std::string typeId, BaseCreator *creator)
{
  std::map<std::string, BaseCreator *>::iterator it = m_creators.find(typeId);

  if (it != m_creators.end())
  {
    delete creator;
    return false;
  }

  m_creators[typeId] = creator;
  return true;
}

Node *ObjectFactory::createType(std::string typeId)
{
  std::map<std::string, BaseCreator *>::iterator it = m_creators.find(typeId);

  if (it == m_creators.end())
  {
    std::cout << "#Type not found ::" << typeId << std::endl;
    return NULL;
  }

  BaseCreator *creator = (*it).second;
  return creator->createNode();
}