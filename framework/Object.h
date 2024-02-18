/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 10:36:53
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 00:07:01
 */

#pragma once

#include "LoaderParams.h"

class Object
{
public:
  virtual void load(const LoaderParams *params) = 0;

  virtual void update() = 0;
  virtual void render() = 0;
  virtual void clean() = 0;

protected:
  Object() {}
  virtual ~Object() {}
};