/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 09:59:48
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 10:12:56
 */

#include "Area.h"
#include "Game.h"

Area::Area(Uint8 r, Uint8 g, Uint8 b, Uint8 a) : Empty(r, g, b, a)
{
}

void Area::load(const LoaderParams *params)
{
  Node::load(params);
}

void Area::draw()
{
  SDL_Rect rect;
  rect.x = m_position.getX();
  rect.y = m_position.getY();
  rect.w = m_width;
  rect.h = m_height;

  SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), m_r, m_g, m_b, m_a);
  SDL_RenderDrawRect(TheGame::Instance()->getRenderer(), &rect);
}

void Area::update()
{
}

void Area::clean()
{
  Empty::clean();
}