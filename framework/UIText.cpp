/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 22:51:48
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 00:01:42
 */

#include "UIText.h"
#include "InputHandler.h"

UIText::UIText()
{
}

void UIText::load(const LoaderParams *params)
{
  UI::load(params);
}

void UIText::draw()
{
  UI::draw();
}

void UIText::update()
{
  m_currFrame = int((SDL_GetTicks() / (1000 / m_animSpeed)) % m_numFrames);

  UI::update();
}

void UIText::clean()
{
  UI::clean();
}