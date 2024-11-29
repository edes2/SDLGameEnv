#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SDL_mixer.h>
#include <string>
#include <unordered_map>

class SoundManager
{
public:
    // Singleton instance accessor
    static SoundManager *getInstance();

    // Load a sound effect
    bool loadSound(const std::string &id, const std::string &filePath);

    // Load background music
    bool loadMusic(const std::string &id, const std::string &filePath);

    // Play a sound effect
    void playSound(const std::string &id, int loops = 0);

    // Play background music
    void playMusic(const std::string &id, int loops = -1);

    // Clean up loaded sounds and music
    void clean();

private:
    // Private constructor to enforce singleton pattern
    SoundManager();

    // Destructor
    ~SoundManager();

    // Disable copy constructor and assignment operator
    SoundManager(const SoundManager &) = delete;
    SoundManager &operator=(const SoundManager &) = delete;

    // Maps for storing sounds and music
    std::unordered_map<std::string, Mix_Chunk *> sounds;
    std::unordered_map<std::string, Mix_Music *> musics;
};

#endif // SOUNDMANAGER_H