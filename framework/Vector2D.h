/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 14:20:56
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-14 14:50:49
 */
#pragma once

#include <math.h>
class Vector2D
{

public:
  Vector2D()
  {
    m_x = 0;
    m_y = 0;
  }

  Vector2D(float x, float y) : m_x(x), m_y(y) {}

  float x() { return m_x; }
  float y() { return m_y; }

  void setX(float x) { m_x = x; }
  void setY(float y) { m_y = y; }

  float length() { return sqrt(m_x * m_x + m_y + m_y); }

  Vector2D operator+(const Vector2D &v) const
  {
    return Vector2D(m_x + v.m_x, m_y + v.m_y);
  }
  friend Vector2D &operator+=(Vector2D &v1, const Vector2D &v2)
  {
    v1.m_x += v2.m_x;
    v1.m_y += v2.m_y;
    return v1;
  }

  Vector2D operator-(const Vector2D &v) const
  {
    return Vector2D(m_x - v.m_x, m_y - v.m_y);
  }
  friend Vector2D &operator-=(Vector2D &v1, const Vector2D &v2)
  {
    v1.m_x -= v2.m_x;
    v1.m_y -= v2.m_y;
    return v1;
  }

  Vector2D operator*(float s)
  {
    return Vector2D(m_x * s, m_y * s);
  }
  Vector2D &operator*=(float s)
  {
    m_x *= s;
    m_y *= s;
    return *this;
  }

  Vector2D operator/(float s)
  {
    return Vector2D(m_x / s, m_y / s);
  }
  Vector2D &operator/=(float s)
  {
    m_x /= s;
    m_y /= s;
    return *this;
  }

  void normalize()
  {
    float l = length();
    if (l > 0)
    {
      (*this) *= 1 / l;
    }
  }

private:
  float m_x;
  float m_y;
};
