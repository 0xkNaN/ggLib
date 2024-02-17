/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:53:41
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 11:09:48
 */
#pragma once

#include <iostream>

#include "ObjectFactory.h"
#include "Node.h"
#include "Actor.h"

class Player : public Actor
{
public:
  Player();
  ~Player() {}

  void load(const LoaderParams *params);

  void draw();
  void update();
  void clean();

private:
  void handleInputs();
};

class PlayerCreator : public BaseCreator
{
  Node *createNode() const
  {
    return new Player();
  }
};
