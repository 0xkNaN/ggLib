/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 11:55:44
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 15:24:06
 */

#include "UIButton.h"
#include "InputHandler.h"

UIButton::UIButton(void (*callback)())
{
  m_callback = callback;
}

void UIButton::load(const LoaderParams *params)
{
  UI::load(params);

  m_bClicked = false;
}

void UIButton::draw()
{
  UI::draw();
}

void UIButton::update()
{
  UI::update();

  if (m_currFrame == int(UI_STATE::MOUSE_HOVER))
  {
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
}

void UIButton::clean()
{
  UI::clean();
}