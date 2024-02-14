/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-14 15:05:28
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-14 15:08:35
 */
#pragma once

class InputHandler
{
public:
  static InputHandler *Instance()
  {
    if (s_pInstance == 0)
      s_pInstance = new InputHandler();
    return s_pInstance;
  }

  void update();
  void clean();

private:
  InputHandler();
  ~InputHandler() {}

  static InputHandler *s_pInstance;
};

typedef InputHandler TheInputHandler;
