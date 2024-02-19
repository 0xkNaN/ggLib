/**
 * @Author: Hassen Rmili
 * @Date:   2024-02-19 14:47:39
 * @Last Modified by:   Hassen Rmili
 * @Last Modified time: 2024-02-19 14:56:40
 */

#include "SoundManager.h"

SoundManager *SoundManager::s_pInstance = 0;

SoundManager::SoundManager()
{
  Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
}

SoundManager::~SoundManager()
{
  Mix_CloseAudio();
}

bool SoundManager::load(std::string file, std::string id, SOUND_TYPE type)
{
  if (type == SOUND_TYPE::SOUND_MUSIC)
  {
    Mix_Music *music = Mix_LoadMUS(file.c_str());
    if (music == 0)
    {
      std::cout << "Could not load music " << Mix_GetError() << std::endl;
      return false;
    }

    m_music[id] = music;
    return true;
  }
  else if (type == SOUND_TYPE::SOUND_SFX)
  {
    Mix_Chunk *chunk = Mix_LoadWAV(file.c_str());
    if (chunk == 0)
    {
      std::cout << "Could not load sfx " << Mix_GetError() << std::endl;
      return false;
    }

    m_sfxs[id] = chunk;
    return true;
  }

  return false;
}

void SoundManager::playMusic(std::string id, int loop)
{
  Mix_PlayMusic(m_music[id], loop);
}

void SoundManager::playSFX(std::string id, int loop)
{
  Mix_PlayChannel(-1, m_sfxs[id], loop);
}
