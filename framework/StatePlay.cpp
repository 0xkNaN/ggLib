/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 10:45:10
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 11:05:58
 */

#include "StatePlay.h"

#include <iostream>

const char *StatePlay::s_playId = "PLAY";

void StatePlay::update()
{
}

void StatePlay::render()
{
}

bool StatePlay::onEnter()
{
  std::cout << "StatePlay enter" << std::endl;
  return true;
}

bool StatePlay::onExit()
{
  std::cout << "StatePlay exit" << std::endl;
  return true;
}