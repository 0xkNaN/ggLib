/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 11:55:44
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 15:10:19
 */

#include "UIButton.h"
#include "InputHandler.h"

UIButton::UIButton()
{
}

void UIButton::load(const LoaderParams *params)
{
  UI::load(params);

  m_callbackId = params->callbackId();
  m_bClicked = false;
}

void UIButton::draw()
{
  UI::draw();
}

void UIButton::update()
{
  UI::update();

  if (m_bHovered)
  {
    m_currFrame = int(UI_STATE::MOUSE_HOVER);

    if (TheInputHandler::Instance()->mouseButtonState(MouseButtons::LEFT) && !m_bClicked)
    {
      m_bClicked = true;
      m_currFrame = int(UI_STATE::MOUSE_CLICK);
      
      m_callback();
    }
    else if (!TheInputHandler::Instance()->mouseButtonState(MouseButtons::LEFT) && m_bClicked)
    {
      m_bClicked = false;
    }
  }
  else
  {
    m_currFrame = int(UI_STATE::MOUSE_OUT);
  }
}

void UIButton::clean()
{
  UI::clean();
}