/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-19 14:39:03
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-19 14:57:11
 */
#pragma once

#include <iostream>
#include <map>
#include <SDL2/SDL_mixer.h>

enum class SOUND_TYPE
{
  SOUND_MUSIC = 0,
  SOUND_SFX = 1
};

class SoundManager
{
public:
  static SoundManager *Instance()
  {
    if (s_pInstance == 0)
      s_pInstance = new SoundManager();
    return s_pInstance;
  }

  bool load(std::string file, std::string id, SOUND_TYPE type);

  void playMusic(std::string id, int loop);
  void playSFX(std::string id, int loop);

private:
  static SoundManager *s_pInstance;

  SoundManager();
  ~SoundManager();

  SoundManager(const SoundManager &);
  SoundManager &operator=(const SoundManager &);

  std::map<std::string, Mix_Music *> m_music;
  std::map<std::string, Mix_Chunk *> m_sfxs;
};

typedef SoundManager TheSoundManager;
