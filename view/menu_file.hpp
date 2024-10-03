// menu_file.hpp
#ifndef MENU_FILE_HPP
#define MENU_FILE_HPP

#include "file.hpp"
#include <chrono>
#include "media_controller.hpp"

void displayTimeThread(File &file);
void displayMetadataMenu();
void displayPlayFile();

#endif
