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
#define HEIGHT 12
#define WIDTH  55

class Media_controller{
public:
static void drawVolumeBar(WINDOW* win, int currentVolume, int maxVolume);
static void manageVolume(WINDOW* main_win);
static void displayMenu(WINDOW* main_win, int highlight);
static void manageMetadata();
static void manageMediafiles();
static void managePlaylist();
static void managePlaySong();
};

#endif