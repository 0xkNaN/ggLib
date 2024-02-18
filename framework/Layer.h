/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-17 18:44:49
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-18 18:46:10
 */
#pragma once

class Level;

class Layer
{
public:
  virtual ~Layer() {}

  virtual void update(Level *level) = 0;
  virtual void render() = 0;
};
