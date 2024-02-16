/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-16 10:48:23
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 12:58:43
 */

#include "StateMachine.h"

void StateMachine::pushState(State *state)
{
  m_gameStates.push_back(state);
  m_gameStates.back()->onEnter();
}

void StateMachine::changeState(State *state)
{
  if (!m_gameStates.empty())
  {
    //? Do nothing if the Same State
    if (m_gameStates.back()->getStateId() == state->getStateId())
      return;

    //? Pop the last state
    if (m_gameStates.back()->onExit())
    {
      delete m_gameStates.back();
      m_gameStates.pop_back();
    }

    //? Push the new State
    m_gameStates.push_back(state);
    m_gameStates.back()->onEnter();
  }
}

void StateMachine::popState()
{
  if (!m_gameStates.empty())
  {
    if (m_gameStates.back()->onExit())
    {
      delete m_gameStates.back();
      m_gameStates.pop_back();
    }
  }
}

void StateMachine::update()
{
  if (!m_gameStates.empty())
  {
    m_gameStates.back()->update();
  }
}

void StateMachine::render()
{

  if (!m_gameStates.empty())
  {
    m_gameStates.back()->render();
  }
}

void StateMachine::clean()
{
  if (!m_gameStates.empty())
  {
    m_gameStates.back()->onExit();
    m_gameStates.clear();
  }
}