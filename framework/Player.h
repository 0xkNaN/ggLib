/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:53:41
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-14 15:28:27
 */
#pragma once

#include <iostream>

#include "Node.h"

class Player : public Node
{
public:
  Player() : Node() {}
  ~Player() {}

  void load(const LoaderParams *params);

  void draw();
  void update();
  void clean();
};
