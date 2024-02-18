/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 22:51:48
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 00:11:05
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


void UIText::update()
{
  m_currFrame = int((SDL_GetTicks() / (1000 / m_animSpeed)) % m_numFrames);

  UI::update();
}
void UIText::render()
{
  UI::render();
}

void UIText::clean()
{
  UI::clean();
}