/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 09:42:10
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 10:11:46
 */

#include "Empty.h"
#include "Game.h"

Empty::Empty(Uint8 r, Uint8 g, Uint8 b, Uint8 a) : m_r(r), m_g(g), m_b(b), m_a(a)
{
}

void Empty::load(const LoaderParams *params)
{
  Node::load(params);
}

void Empty::draw()
{
  SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), m_r, m_g, m_b, m_a);
  SDL_RenderDrawPoint(TheGame::Instance()->getRenderer(), m_position.getX(), m_position.getY());
}

void Empty::update()
{
}

void Empty::clean()
{
  Node::clean();
}
