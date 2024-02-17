/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:53:57
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 11:11:26
 */
#pragma once

#include <iostream>

#include "ObjectFactory.h"
#include "Node.h"
#include "Actor.h"

class Enemy : public Actor
{
public:
  Enemy() {}
  ~Enemy() {}

  virtual void load(const LoaderParams *params);

  virtual void draw();
  virtual void update();
  virtual void clean();

protected:
};

class EnemyCreator : public BaseCreator
{
  Node *createNode() const
  {
    return new Enemy();
  }
};
