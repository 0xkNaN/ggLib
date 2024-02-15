/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:53:50
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-16 00:37:35
 */

#include "Player.h"
#include "InputHandler.h"

Player::Player()
{
}

void Player::load(const LoaderParams *params)
{
  Actor::load(params);
  m_flip = SDL_FLIP_HORIZONTAL;
}

void Player::draw()
{
  Actor::draw();
}

void Player::update()
{
  m_velocity.setX(0);
  m_velocity.setY(0);

  m_currFrame = int(((SDL_GetTicks() / 100) % 4));
  m_angle = 0;

  handleInputs();

  Actor::update();
}

void Player::handleInputs()
{

  //? Joystick
  if (TheInputHandler::Instance()->joysticksInitialised())
  {
    //? Joy Axis
    if (TheInputHandler::Instance()->xAxisValue(0, 1) != 0)
    {
      // m_velocity.setX(1 * TheInputHandler::Instance()->xAxisValue(0, 1));
    }
    if (TheInputHandler::Instance()->yAxisValue(0, 1) != 0)
    {
      // m_velocity.setY(1 * TheInputHandler::Instance()->yAxisValue(0, 1));
    }
    if (TheInputHandler::Instance()->xAxisValue(0, 2) != 0)
    {
      // m_velocity.setX(1 * TheInputHandler::Instance()->xAxisValue(0, 2));
    }
    if (TheInputHandler::Instance()->yAxisValue(0, 2) != 0)
    {
      // m_velocity.setY(1 * TheInputHandler::Instance()->yAxisValue(0, 2));
    }

    //? Joy Buttons
    if (TheInputHandler::Instance()->buttonState(0, 0))
    {
      // std::cout << "Joy Button 0" << std::endl;
    }
    if (TheInputHandler::Instance()->buttonState(0, 1))
    {
      // std::cout << "Joy Button 1" << std::endl;
    }
  }

  //? Mouse
  if (TheInputHandler::Instance()->mouseButtonState(MouseButtons::LEFT))
  {
    // std::cout << "Mouse Button Left" << std::endl;
  }
  if (TheInputHandler::Instance()->mouseButtonState(MouseButtons::MIDDLE))
  {
    // std::cout << "Mouse Button Middle" << std::endl;
  }
  if (TheInputHandler::Instance()->mouseButtonState(MouseButtons::RIGHT))
  {
    // std::cout << "Mouse Button Right" << std::endl;
  }

  //? Mouse Move
  // Vector2D *mousePosition = TheInputHandler::Instance()->mousePosition();
  // m_velocity = (*mousePosition - m_position) / 20;
  // if (mousePosition->getX() > m_position.getX())
  //   m_flip = SDL_FLIP_HORIZONTAL;
  // else
  //   m_flip = SDL_FLIP_NONE;

  //? Keyboard
  if (TheInputHandler::Instance()->keyPressed(SDL_SCANCODE_LEFT))
  {
    m_velocity.setX(-5);
    m_angle = -5;
    m_flip = SDL_FLIP_NONE;
  }
  if (TheInputHandler::Instance()->keyPressed(SDL_SCANCODE_RIGHT))
  {
    m_velocity.setX(5);
    m_angle = 5;
    m_flip = SDL_FLIP_HORIZONTAL;
  }
  if (TheInputHandler::Instance()->keyPressed(SDL_SCANCODE_UP))
  {
    m_velocity.setY(-5);
  }
  if (TheInputHandler::Instance()->keyPressed(SDL_SCANCODE_DOWN))
  {
    m_velocity.setY(5);
  }
}

void Player::clean()
{
  Actor::clean();
}
