#include "soundmanager.h"

SoundManager *SoundManager::getInstance()
{
    static SoundManager instance;
    return &instance;
}

bool SoundManager::loadSound(const std::string &id, const std::string &filePath)
{
    Mix_Chunk *chunk = Mix_LoadWAV(filePath.c_str());
    if (!chunk)
    {
        printf("Failed to load sound: %s", Mix_GetError());
        return false;
    }
    sounds[id] = chunk;
    return true;
}

void SoundManager::playSound(const std::string &id, int loops)
{
    auto it = sounds.find(id);
    if (it != sounds.end())
    {
        Mix_PlayChannel(-1, it->second, loops);
    }
}

void SoundManager::clean()
{
    for (auto &pair : sounds)
    {
        Mix_FreeChunk(pair.second);
    }
    sounds.clear();
}

SoundManager::SoundManager() {}
SoundManager::~SoundManager() {}