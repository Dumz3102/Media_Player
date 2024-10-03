#ifndef FOLDER_MANAGER_HPP
#define FOLDER_MANAGER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "folder.hpp"

void playMusic(const std::string& filename);  // Function to play music
void displayMenu();
void displaySongTime();
void managerFolder();  // Function to manage folder music playback

#endif
