/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 11:33:59
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 15:03:52
 */

#include "UI.h"

#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Vector2D.h"

void UI::load(const LoaderParams *params)
{
  Node::load(params);

  m_textureId = params->getTextureId();
  m_currRow = 0;
  m_currFrame = int(UI_STATE::MOUSE_OUT);
}

void UI::draw()
{
  TheTextureManager::Instance()->draw(
      TheGame::Instance()->getRenderer(),
      m_textureId,
      m_position.getX(),
      m_position.getY(),
      m_width,
      m_height,
      m_currRow,
      m_currFrame);
}

void UI::update()
{
  //? Mouse Position
  Vector2D *mpos = TheInputHandler::Instance()->mousePosition();
  float mposX = mpos->getX();
  float mposY = mpos->getY();

  //? UI Position
  float posX = m_position.getX();
  float posY = m_position.getY();

  //? Check Mouse Hover
  if (
      mposX > posX && mposX < (posX + m_width) &&
      mposY > posY && mposY < (posY + m_height))
  {
    m_currFrame = int(UI_STATE::MOUSE_HOVER);
  }
  else
  {
    m_currFrame = int(UI_STATE::MOUSE_OUT);
  }
}

void UI::clean()
{
  Node::clean();
}