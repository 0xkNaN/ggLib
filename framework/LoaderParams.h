/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 11:52:51
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-17 15:12:42
 */
#pragma once

class LoaderParams
{
public:
  LoaderParams(
      int x, int y, int width, int height, std::string textureId,
      int numFrames = 1, int animSpeed = 1, int callbackId = 0)
  {
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;

    m_textureId = textureId;
    m_numFrames = numFrames;
    m_animSpeed = animSpeed;

    m_callbackId = callbackId;
  }

  int x() const { return m_x; }
  int y() const { return m_y; }
  int width() const { return m_width; }
  int height() const { return m_height; }

  std::string textureId() const { return m_textureId; }

  int numFrames() const { return m_numFrames; }
  int animSpeed() const { return m_animSpeed; }

  int callbackId() const { return m_callbackId; }

private:
  int m_x;
  int m_y;
  int m_width;
  int m_height;

  std::string m_textureId;

  int m_numFrames;
  int m_animSpeed;

  int m_callbackId;
};