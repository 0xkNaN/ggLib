/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 11:33:59
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 00:09:41
 */

#include "UI.h"

#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Vector2D.h"

void UI::load(const LoaderParams *params)
{
  Node::load(params);

  m_textureId = params->textureId();
  m_numFrames = params->numFrames();
  m_animSpeed = params->animSpeed();

  m_currRow = 0;
  m_currFrame = int(UI_STATE::MOUSE_OUT);

  m_bHovered = false;
}

void UI::update()
{
  //? Mouse Position
  Vector2D *mpos = TheInputHandler::Instance()->mousePosition();
  float mposX = mpos->x();
  float mposY = mpos->y();

  //? UI Position
  float posX = m_position.x();
  float posY = m_position.y();

  //? Check Mouse Hover
  m_bHovered = mposX > posX && mposX < (posX + m_width) &&
               mposY > posY && mposY < (posY + m_height);
}

void UI::render()
{
  TheTextureManager::Instance()->render(
      TheGame::Instance()->renderer(),
      m_textureId,
      m_position.x(),
      m_position.y(),
      m_width,
      m_height,
      m_currRow,
      m_currFrame);
}

void UI::clean()
{
  Node::clean();
}