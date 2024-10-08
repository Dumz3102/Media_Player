#ifndef FOLDER_MANAGER_HPP
#define FOLDER_MANAGER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "folder.hpp"

class Folder_manager{
public:
static void playMusic(const std::string& filename);  // Function to play music
static void displayMenu();
static void managerFolder();  // Function to manage folder music playback
static void onMusicFinished();
};

#endif
