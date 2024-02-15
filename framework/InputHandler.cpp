/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 15:05:39
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-15 17:16:13
 */

#include "InputHandler.h"
#include "Game.h"

InputHandler *InputHandler::s_pInstance = nullptr;

InputHandler::InputHandler()
{
  //? Joystick
  m_bJoysticksInitialised = false;

  //? Mouse
  m_mousePosition = new Vector2D(0, 0);
  for (int i = 0; i < 3; i++)
    m_mouseButtonStates.push_back(false);

  //? Keyboard
  m_keyStates = 0;
}

void InputHandler::update()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    //? Joystick
    case SDL_JOYAXISMOTION:
      onJoystickAxisMove(event);
      break;
    case SDL_JOYBUTTONDOWN:
      onJoystickButtonDown(event);
      break;
    case SDL_JOYBUTTONUP:
      onJoystickButtonUp(event);
      break;

    //? Mouse
    case SDL_MOUSEBUTTONDOWN:
      onMouseButtonDown(event);
      break;
    case SDL_MOUSEBUTTONUP:
      onMouseButtonUp(event);
      break;
    case SDL_MOUSEMOTION:
      onMouseMove(event);
      break;

    //? Keyboard
    case SDL_KEYDOWN:
      onKeyDown();
      break;
    case SDL_KEYUP:
      onKeyUp();
      break;

    //? Other
    case SDL_QUIT:
      TheGame::Instance()->quit();
      break;

    default:
      break;
    }
  }
}

void InputHandler::clean()
{
  if (m_bJoysticksInitialised)
  {
    for (unsigned int i = 0; i < SDL_NumJoysticks(); i++)
    {
      SDL_JoystickClose(m_joysticks[i]);
    }
  }
}

//? Joysticks
void InputHandler::initJoysticks()
{
  if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);

  if (SDL_NumJoysticks() > 0)
  {
    for (unsigned int i = 0; i < SDL_NumJoysticks(); i++)
    {
      SDL_Joystick *joy = SDL_JoystickOpen(i);
      if (SDL_JoystickGetAttached(joy))
      {
        m_joysticks.push_back(joy);
        m_joysticksValues.push_back(
            std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));

        //? Buttons
        std::vector<bool> tmpButtons;
        for (int j = 0; j < SDL_JoystickNumButtons(joy); j++)
        {
          tmpButtons.push_back(false);
        }

        m_buttonStates.push_back(tmpButtons);
      }
      else
        std::cout << "Joystick error :: " << SDL_GetError() << std::endl;
    }

    SDL_JoystickEventState(SDL_ENABLE);
    m_bJoysticksInitialised = true;

    std::cout << "#Joysticks :: found [" << SDL_NumJoysticks()
              << "] init [" << m_joysticks.size()
              << "]" << std::endl;
  }
  else
  {
    m_bJoysticksInitialised = false;
    std::cout << "No Joysticks found" << std::endl;
  }
}

int InputHandler::xAxisValue(int joy, int stick) const
{
  if (m_joysticksValues.size() > 0)
  {
    if (stick == 1)
      return m_joysticksValues[joy].first->getX();
    else if (stick == 2)
      return m_joysticksValues[joy].second->getX();
  }

  return 0;
}

int InputHandler::yAxisValue(int joy, int stick) const
{
  if (m_joysticksValues.size() > 0)
  {
    if (stick == 1)
      return m_joysticksValues[joy].first->getY();
    else if (stick == 2)
      return m_joysticksValues[joy].second->getY();
  }

  return 0;
}

bool InputHandler::buttonState(int joy, int buttonNumber) const
{
  return m_buttonStates[joy][buttonNumber];
}

void InputHandler::onJoystickAxisMove(SDL_Event &event)
{
  int whichJoy = event.jaxis.which;

  //? Left Stick move left or right
  if (event.jaxis.axis == 0)
  {
    if (event.jaxis.value > m_joystickDeadZone)
      m_joysticksValues[whichJoy].first->setX(1);
    else if (event.jaxis.value < -m_joystickDeadZone)
      m_joysticksValues[whichJoy].first->setX(-1);
    else
      m_joysticksValues[whichJoy].first->setX(0);
  }

  //? Left Stick move up or down
  if (event.jaxis.axis == 1)
  {
    if (event.jaxis.value > m_joystickDeadZone)
      m_joysticksValues[whichJoy].first->setY(1);
    else if (event.jaxis.value < -m_joystickDeadZone)
      m_joysticksValues[whichJoy].first->setY(-1);
    else
      m_joysticksValues[whichJoy].first->setY(0);
  }

  //? Right Stick move left or right
  if (event.jaxis.axis == 2)
  {
    if (event.jaxis.value > m_joystickDeadZone)
      m_joysticksValues[whichJoy].second->setX(1);
    else if (event.jaxis.value < -m_joystickDeadZone)
      m_joysticksValues[whichJoy].second->setX(-1);
    else
      m_joysticksValues[whichJoy].second->setX(0);
  }

  //? Right Stick move up or down
  if (event.jaxis.axis == 3)
  {
    if (event.jaxis.value > m_joystickDeadZone)
      m_joysticksValues[whichJoy].second->setY(1);
    else if (event.jaxis.value < -m_joystickDeadZone)
      m_joysticksValues[whichJoy].second->setY(-1);
    else
      m_joysticksValues[whichJoy].second->setY(0);
  }
}

void InputHandler::onJoystickButtonDown(SDL_Event &event)
{
  int whichJoy = event.jaxis.which;
  m_buttonStates[whichJoy][event.jbutton.button] = true;
}

void InputHandler::onJoystickButtonUp(SDL_Event &event)
{
  int whichJoy = event.jaxis.which;
  m_buttonStates[whichJoy][event.jbutton.button] = false;
}

//? Mouse
bool InputHandler::mouseButtonState(MouseButtons buttonNumber) const
{
  return m_mouseButtonStates[int(buttonNumber)];
}

Vector2D *InputHandler::mousePosition() const
{
  return m_mousePosition;
}

void InputHandler::onMouseButtonDown(SDL_Event &event)
{
  if (event.button.button == SDL_BUTTON_LEFT)
    m_mouseButtonStates[int(MouseButtons::LEFT)] = true;

  if (event.button.button == SDL_BUTTON_MIDDLE)
    m_mouseButtonStates[int(MouseButtons::MIDDLE)] = true;

  if (event.button.button == SDL_BUTTON_RIGHT)
    m_mouseButtonStates[int(MouseButtons::RIGHT)] = true;
}

void InputHandler::onMouseButtonUp(SDL_Event &event)
{
  if (event.button.button == SDL_BUTTON_LEFT)
    m_mouseButtonStates[int(MouseButtons::LEFT)] = false;

  if (event.button.button == SDL_BUTTON_MIDDLE)
    m_mouseButtonStates[int(MouseButtons::MIDDLE)] = false;

  if (event.button.button == SDL_BUTTON_RIGHT)
    m_mouseButtonStates[int(MouseButtons::RIGHT)] = false;
}

void InputHandler::onMouseMove(SDL_Event &event)
{
  m_mousePosition->setX(event.motion.x);
  m_mousePosition->setY(event.motion.y);
}

//? Keyboard
bool InputHandler::keyPressed(SDL_Scancode key) const
{
  if (m_keyStates != 0)
    return m_keyStates[key];
  return false;
}

void InputHandler::onKeyDown()
{
  m_keyStates = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp()
{
  m_keyStates = SDL_GetKeyboardState(0);
}