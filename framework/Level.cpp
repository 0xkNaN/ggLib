/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-17 18:40:47
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 20:09:00
 */

#include "Level.h"

Level::Level()
{
}

Level::~Level()
{
  for (int i = 0; i < m_layers.size(); i++)
  {
    delete m_layers[i];
  }

  m_layers.clear();
}

void Level::update()
{
  for (int i = 0; i < m_layers.size(); i++)
  {
    m_layers[i]->update(this);
  }
}

void Level::render()
{
  for (int i = 0; i < m_layers.size(); i++)
  {
    m_layers[i]->render();
  }
}
