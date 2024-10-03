#include <iostream>
#include "media_controller.hpp"

using namespace std;

int main(){
    int highlight = 0;

    // Init ncurses
    initscr();                                                // Init 
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);                                     // Enable keyboard
    curs_set(0);

    // Display main menu
    int height, width;
    getmaxyx(stdscr, height, width);
    WINDOW* main_win = newwin(HEIGHT, WIDTH, (height - HEIGHT) / 2, (width - WIDTH) / 2);
    displayMenu(main_win, highlight);

    int choice;
    bool exitProgram = false;

    while (!exitProgram) {
        choice = getch();

        switch (choice) {
            case KEY_UP:
                highlight = (highlight == 0) ? 5 : highlight - 1;
                break;
            case KEY_DOWN:
                highlight = (highlight == 5) ? 0 : highlight + 1;
                break;
            case 10: // Enter key
                switch (highlight) {
                    case 0:
                        // Play song (implement this later)
                        printf("\e[1;1H\e[2J"); // Clear screen
                        managePlaySong();
                        break;
                    case 1:
                        // Manage metadata
                        printf("\e[1;1H\e[2J"); // Clear screen
                        manageMetadata();
                        break;
                    case 2:
                        // Manage playlist
                        printf("\e[1;1H\e[2J"); // Clear screen
                        managePlaylist();
                        break;
                    case 3:
                        // View media file
                        printf("\e[1;1H\e[2J"); // Clear screen
                        manageMediafiles();
                        break;
                    case 4:
                        printf("\e[1;1H\e[2J"); // Clear screen
                        manageVolume(main_win);
                        break;
                    case 5:
                        exitProgram = true;
                        break;
                }
                break;
        }

        displayMenu(main_win, highlight);
    }

    // Close the audio system
    Mix_CloseAudio();
    SDL_Quit();

    // End ncurses
    endwin();
    return 0;
}
