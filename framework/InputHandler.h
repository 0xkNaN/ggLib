/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 15:05:28
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-15 17:06:42
 */
#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "Vector2D.h"

enum class MouseButtons
{
  LEFT = 0,
  MIDDLE = 1,
  RIGHT = 2
};

class InputHandler
{
public:
  static InputHandler *Instance()
  {
    if (s_pInstance == 0)
      s_pInstance = new InputHandler();
    return s_pInstance;
  }

  void update();
  void clean();

  //? Joysticks
  void initJoysticks();
  bool joysticksInitialised() const { return m_bJoysticksInitialised; }
  int xAxisValue(int joy, int stick) const;
  int yAxisValue(int joy, int stick) const;
  bool buttonState(int joy, int buttonNumber) const;

  //? Mouse
  bool mouseButtonState(MouseButtons mouseButtonState) const;
  Vector2D *mousePosition() const;

  //? Keyboard
  bool keyPressed(SDL_Scancode key) const;

private:
  InputHandler();
  ~InputHandler() {}

  static InputHandler *s_pInstance;

  //? Joysticks
  bool m_bJoysticksInitialised;
  static const int m_joystickDeadZone = 10000;
  std::vector<SDL_Joystick *> m_joysticks;
  std::vector<std::pair<Vector2D *, Vector2D *>> m_joysticksValues;
  std::vector<std::vector<bool>> m_buttonStates;
  //...
  void onJoystickAxisMove(SDL_Event &event);
  void onJoystickButtonDown(SDL_Event &event);
  void onJoystickButtonUp(SDL_Event &event);

  //? Mouse
  Vector2D *m_mousePosition;
  std::vector<bool> m_mouseButtonStates;
  void onMouseButtonDown(SDL_Event &event);
  void onMouseButtonUp(SDL_Event &event);
  void onMouseMove(SDL_Event &event);

  //? Keyboard
  const Uint8 *m_keyStates;
  void onKeyDown();
  void onKeyUp();
};

typedef InputHandler TheInputHandler;
