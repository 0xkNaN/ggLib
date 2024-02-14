/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:36:53
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-14 12:39:03
 */

#pragma once

#include "LoaderParams.h"

class Object
{
public:
  virtual void draw() = 0;
  virtual void update() = 0;
  virtual void clean() = 0;

protected:
  Object(const LoaderParams *params) {}
  virtual ~Object() {}
};