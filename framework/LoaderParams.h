/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 11:52:51
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-14 14:51:06
 */
#pragma once

class LoaderParams
{
public:
  LoaderParams(int x, int y, int width, int height, const char *textureId) : m_x(x), m_y(y), m_width(width), m_height(height), m_textureId(textureId)
  {
  }

  int getX() const { return m_x; }
  int getY() const { return m_y; }
  int getWidth() const { return m_width; }
  int getHeight() const { return m_height; }
  const char *getTextureId() const { return m_textureId; }

private:
  int m_x;
  int m_y;
  int m_width;
  int m_height;

  const char *m_textureId;
};