#ifndef MEDIA_CONTROLLER_HPP
#define MEDIA_CONTROLLER_HPP

#include <atomic>
#include <ncurses.h>
#include <string>
#include <filesystem>
#include <cstring>
#include "menu_file.hpp"
#include "menu_showfile.hpp"
#include "menu_playlist.hpp"
#include "menu_play.hpp"

extern std::atomic<bool> showTimeFlag;
#define HEIGHT 10
#define WIDTH  55

void drawVolumeBar(WINDOW* win, int currentVolume, int maxVolume);
void manageVolume(WINDOW* main_win);
void displayMenu(WINDOW* main_win, int highlight);
void manageMetadata();
void manageMediafiles();
void managePlaylist();
void managePlaySong();


#endif